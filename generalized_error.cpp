#include "generalized_error.hpp"

#include <cmath>
#include <random>

#include "stats.hpp"

// Fits a generalized error distribution with fixed power.
GeneralizedErrorFit generalizedErrorFit(const std::vector<double>& data, double power) {
    double mu = mean(data);
    double var = variance(data, mu);
    double scaleRatio = std::tgamma(3.0 / power) / std::tgamma(1.0 / power);
    double beta = std::sqrt(std::max(var, 1e-12) / scaleRatio);
    return {mu, std::max(beta, 1e-12), power};
}

// Computes the GED log-likelihood for the fitted parameters.
double generalizedErrorLogLikelihood(const std::vector<double>& data, const GeneralizedErrorFit& fit) {
    double power = fit.power;
    double beta = fit.beta;
    double logCoef = std::log(power) - std::log(2.0 * beta) - std::lgamma(1.0 / power);
    double invBeta = 1.0 / beta;
    double logLik = 0.0;
    for (double x : data) {
        double z = std::abs(x - fit.mu) * invBeta;
        logLik += logCoef - std::pow(z, power);
    }
    return logLik;
}

// Converts the GED scale to its implied standard deviation.
double generalizedErrorStddev(const GeneralizedErrorFit& fit) {
    double power = fit.power;
    double ratio = std::tgamma(3.0 / power) / std::tgamma(1.0 / power);
    return fit.beta * std::sqrt(ratio);
}

// Returns the theoretical kurtosis of a GED with fixed power.
double generalizedErrorKurtosis(double power) {
    double gamma1 = std::tgamma(1.0 / power);
    double gamma3 = std::tgamma(3.0 / power);
    double gamma5 = std::tgamma(5.0 / power);
    return (gamma5 * gamma1) / (gamma3 * gamma3);
}

// Generates GED samples using a simple power-transformed exponential method.
std::vector<double> rged(size_t n, double mu, double beta, double power, std::mt19937_64& rng) {
    std::uniform_real_distribution<double> uniform(0.0, 1.0);
    std::vector<double> samples(n);
    for (double& value : samples) {
        double u = uniform(rng) - 0.5;
        double sign = (u >= 0) ? 1.0 : -1.0;
        double magnitude = std::pow(-std::log(1.0 - 2.0 * std::abs(u)), 1.0 / power);
        value = mu + sign * beta * magnitude;
    }
    return samples;
}
