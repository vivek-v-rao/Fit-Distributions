#include "logistic.hpp"

#include <algorithm>
#include <cmath>

#include "constants.hpp"
#include "stats.hpp"

// Estimates logistic parameters via matching the mean and variance.
LogisticFit logisticFit(const std::vector<double>& data) {
    double mu = mean(data);
    double var = variance(data, mu);
    double scale = std::sqrt(std::max(var, 1e-12)) * std::sqrt(3.0) / kPi;
    return {mu, std::max(scale, 1e-12)};
}

// Logistic log-likelihood with location-scale parameters.
double logisticLogLikelihood(const std::vector<double>& data, const LogisticFit& fit) {
    double logLik = 0.0;
    for (double x : data) {
        double z = (x - fit.mu) / fit.scale;
        logLik += -std::log(fit.scale) - z - 2.0 * log1pExp(-z);
    }
    return logLik;
}

// Converts logistic scale to its implied standard deviation.
double logisticStddev(const LogisticFit& fit) {
    return kPi * fit.scale / std::sqrt(3.0);
}

// Generates logistic samples (like R's rlogis).
std::vector<double> rlogis(size_t n, double mu, double scale, std::mt19937_64& rng) {
    std::uniform_real_distribution<double> uniform(0.0, 1.0);
    std::vector<double> samples(n);
    for (double& value : samples) {
        double u = uniform(rng);
        u = std::clamp(u, 1e-12, 1.0 - 1e-12);
        value = mu + scale * std::log(u / (1.0 - u));
    }
    return samples;
}
