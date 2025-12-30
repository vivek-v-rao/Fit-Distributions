#pragma once

#include <functional>
#include <string>
#include <vector>

enum class ModelType { Normal, Laplace, HyperbolicSecant, Logistic, StudentT3, StudentT6, GeneralizedError15, SymmetricHyperbolic };

struct FitSummary {
    std::string modelName;
    double logLikelihood;
    double mean;
    double stddev;
    double kurtosis;
};

struct ModelEntry {
    ModelType type;
    std::string name;
    std::function<FitSummary(const std::vector<double>&)> fitFunction;
};

const std::vector<ModelEntry>& modelRegistry();
