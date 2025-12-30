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
#include "stats.hpp"

namespace {
struct RunConfig {
    uint64_t seed;
    size_t groupCount;
};

uint64_t chooseAutoSeed() {
    // Generates a fresh seed using entropy from random_device.
    std::random_device rd;
    uint64_t seed = (static_cast<uint64_t>(rd()) << 32) ^ rd();
    return seed;
}

RunConfig determineRunConfig(int argc, char** argv) {
    // Returns the run configuration based on optional seed/group command-line inputs.
    uint64_t seed = chooseAutoSeed();
    size_t groups = 5;
    if (argc > 1) {
        try {
            seed = std::stoull(argv[1]);
        } catch (const std::exception&) {
            std::cerr << "Invalid seed '" << argv[1] << "', generating one automatically.\n";
            seed = chooseAutoSeed();
        }
    }
    if (argc > 2) {
        try {
            groups = std::max<size_t>(1, std::stoull(argv[2]));
        } catch (const std::exception&) {
            std::cerr << "Invalid group count '" << argv[2] << "', defaulting to 5.\n";
            groups = 5;
        }
    }
    return {seed, groups};
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

    double empiricalMean = mean(dataset.samples);
    double empiricalStd = std::sqrt(variance(dataset.samples, empiricalMean));
    double empiricalKurt = kurtosis(dataset.samples, empiricalMean);

    std::cout << std::left << std::setw(18) << "Empirical"
              << std::right << std::setw(15) << "nan"
              << std::setw(15) << std::fixed << std::setprecision(3) << empiricalMean
              << std::setw(15) << empiricalStd
              << std::setw(15) << empiricalKurt << "\n";

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
    constexpr size_t sampleCount = 1000;
    RunConfig config = determineRunConfig(argc, argv);
    std::cout << "Seed: " << config.seed << "\n";
    std::cout << "Groups: " << config.groupCount << "\n\n";
    std::mt19937_64 rng(config.seed);

    std::vector<Dataset> datasets = simulateDatasets(sampleCount, config.groupCount, rng);
    const std::vector<ModelEntry>& registry = modelRegistry();

    for (const auto& dataset : datasets) {
        printDatasetReport(dataset, registry);
    }

    return 0;
}
