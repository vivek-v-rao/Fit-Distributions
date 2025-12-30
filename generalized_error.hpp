#pragma once

#include <random>
#include <vector>

struct GeneralizedErrorFit {
    double mu;
    double beta;
    double power;
};

GeneralizedErrorFit generalizedErrorFit(const std::vector<double>& data, double power);
double generalizedErrorLogLikelihood(const std::vector<double>& data, const GeneralizedErrorFit& fit);
double generalizedErrorStddev(const GeneralizedErrorFit& fit);
double generalizedErrorKurtosis(double power);
std::vector<double> rged(size_t n, double mu, double beta, double power, std::mt19937_64& rng);
