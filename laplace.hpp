#pragma once

#include <random>
#include <vector>

struct LaplaceFit {
    double mu;
    double b;
};

LaplaceFit laplaceFit(const std::vector<double>& data);
double laplaceLogLikelihood(const std::vector<double>& data, const LaplaceFit& fit);
double laplaceStddev(const LaplaceFit& fit);
constexpr double kLaplaceKurtosis = 6.0;
std::vector<double> rlaplace(size_t n, double mu, double b, std::mt19937_64& rng);
