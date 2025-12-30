#pragma once

#include <random>
#include <vector>

struct HyperbolicSecantFit {
    double mu;
    double sigma;
};

HyperbolicSecantFit hyperbolicSecantFit(const std::vector<double>& data);
double hyperbolicSecantLogLikelihood(const std::vector<double>& data, const HyperbolicSecantFit& fit);
double hyperbolicSecantStddev(const HyperbolicSecantFit& fit);
constexpr double kHyperbolicSecantKurtosis = 5.0;
std::vector<double> rhypersecant(size_t n, double mu, double sigma, std::mt19937_64& rng);
