#pragma once

#include <random>
#include <vector>

struct LogisticFit {
    double mu;
    double scale;
};

LogisticFit logisticFit(const std::vector<double>& data);
double logisticLogLikelihood(const std::vector<double>& data, const LogisticFit& fit);
double logisticStddev(const LogisticFit& fit);
constexpr double kLogisticKurtosis = 4.2;
std::vector<double> rlogis(size_t n, double mu, double scale, std::mt19937_64& rng);
