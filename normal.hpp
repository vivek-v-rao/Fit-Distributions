#pragma once

#include <random>
#include <vector>

struct NormalFit {
    double mu;
    double sigma;
};

NormalFit normalFit(const std::vector<double>& data);
double normalLogLikelihood(const std::vector<double>& data, const NormalFit& fit);
double normalStddev(const NormalFit& fit);
constexpr double kNormalKurtosis = 3.0;
std::vector<double> rnorm(size_t n, double mu, double sigma, std::mt19937_64& rng);
