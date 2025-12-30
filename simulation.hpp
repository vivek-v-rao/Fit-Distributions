#pragma once

#include <random>
#include <vector>

struct Dataset {
    std::string name;
    std::vector<double> samples;
};

std::vector<Dataset> simulateDatasets(size_t sampleCount, size_t groupCount, std::mt19937_64& rng);
