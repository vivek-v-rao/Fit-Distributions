#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

#include "model_registry.hpp"
#include "simulation.hpp"

namespace {
uint64_t chooseAutoSeed() {
    // Generates a fresh seed using entropy from random_device.
    std::random_device rd;
    uint64_t seed = (static_cast<uint64_t>(rd()) << 32) ^ rd();
    return seed;
}

uint64_t determineSeed(int argc, char** argv) {
    // Returns the user-provided seed or generates a new one if none/invalid supplied.
    if (argc > 1) {
        try {
            return std::stoull(argv[1]);
        } catch (const std::exception&) {
            std::cerr << "Invalid seed '" << argv[1] << "', generating one automatically.\n";
        }
    }
    return chooseAutoSeed();
}

void printTableHeader() {
    // Prints the aligned column headers for the summary table.
    std::cout << std::left << std::setw(18) << "Model"
              << std::right << std::setw(15) << "LogLik"
              << std::setw(15) << "Mean"
              << std::setw(15) << "StdDev"
              << std::setw(15) << "Kurtosis" << "\n";
    std::cout << std::string(78, '-') << "\n";
}

void printRanking(const std::vector<FitSummary>& results) {
    // Prints models ordered from best (highest log-likelihood) to worst.
    std::vector<std::pair<double, std::string>> ranking;
    ranking.reserve(results.size());
    for (const auto& summary : results) {
        ranking.emplace_back(summary.logLikelihood, summary.modelName);
    }
    std::sort(ranking.begin(), ranking.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first > rhs.first;
    });
    std::cout << "Ranking: ";
    for (size_t i = 0; i < ranking.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << ranking[i].second;
    }
    std::cout << "\n\n";
}

void printDatasetReport(const Dataset& dataset, const std::vector<ModelEntry>& registry) {
    // Prints the per-model fit table for a dataset and a ranking line.
    std::cout << "Dataset: " << dataset.name << " (" << dataset.samples.size() << " samples)\n";
    printTableHeader();
    std::vector<FitSummary> summaries;
    summaries.reserve(registry.size());
    for (const auto& entry : registry) {
        FitSummary summary = entry.fitFunction(dataset.samples);
        summaries.push_back(summary);
        std::cout << std::left << std::setw(18) << summary.modelName
                  << std::right << std::setw(15) << std::fixed << std::setprecision(2) << summary.logLikelihood
                  << std::setw(15) << std::setprecision(3) << summary.mean
                  << std::setw(15) << summary.stddev
                  << std::setw(15) << summary.kurtosis << "\n";
    }
    printRanking(summaries);
}
}  // namespace

int main(int argc, char** argv) {
    // Simulates datasets and evaluates every model on each sample set.
    constexpr size_t sampleCount = 100000;
    uint64_t seed = determineSeed(argc, argv);
    std::cout << "Seed: " << seed << "\n\n";
    std::mt19937_64 rng(seed);

    std::vector<Dataset> datasets = simulateDatasets(sampleCount, rng);
    const std::vector<ModelEntry>& registry = modelRegistry();

    for (const auto& dataset : datasets) {
        printDatasetReport(dataset, registry);
    }

    return 0;
}
