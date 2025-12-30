#pragma once

#include <random>
#include <vector>

struct HyperbolicSymmetricFit {
    double mu;
    double alpha;
};

HyperbolicSymmetricFit hyperbolicSymmetricFit(const std::vector<double>& data);
double hyperbolicSymmetricLogLikelihood(const std::vector<double>& data, const HyperbolicSymmetricFit& fit);
double hyperbolicSymmetricStddev(const HyperbolicSymmetricFit& fit);
double hyperbolicSymmetricKurtosis(double alpha);
std::vector<double> rsymmetricHyperbolic(size_t n, double mu, double alpha, std::mt19937_64& rng);
