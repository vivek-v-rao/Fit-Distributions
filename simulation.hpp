#pragma once

#include <random>
#include <string>
#include <vector>

struct Dataset {
    std::string name;
    std::vector<double> samples;
};

std::vector<Dataset> simulateDatasets(size_t sampleCount, std::mt19937_64& rng);
