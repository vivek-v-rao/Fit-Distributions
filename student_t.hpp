#pragma once

#include <random>
#include <vector>

struct StudentTFit {
    double mu;
    double sigma;
    double df;
};

StudentTFit studentTFit(const std::vector<double>& data, double df);
double studentTLogLikelihood(const std::vector<double>& data, const StudentTFit& fit);
double studentTStddev(const StudentTFit& fit);
double studentTKurtosis(double df);
std::vector<double> rt(size_t n, double mu, double sigma, double df, std::mt19937_64& rng);
