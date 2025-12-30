#include "laplace.hpp"

#include <cmath>

#include "stats.hpp"

// Fits a Laplace distribution using the median and mean absolute deviation.
LaplaceFit laplaceFit(const std::vector<double>& data) {
    double mu = median(data);
    double avgAbs = 0.0;
    if (!data.empty()) {
        for (double x : data) {
            avgAbs += std::abs(x - mu);
        }
        avgAbs /= static_cast<double>(data.size());
    }
    double b = std::max(avgAbs, 1e-12);
    return {mu, b};
}

// Laplace log-likelihood using the fitted location and scale.
double laplaceLogLikelihood(const std::vector<double>& data, const LaplaceFit& fit) {
    double logLik = 0.0;
    double logCoef = -std::log(2.0 * fit.b);
    for (double x : data) {
        logLik += logCoef - std::abs(x - fit.mu) / fit.b;
    }
    return logLik;
}

// Converts the Laplace scale to a standard deviation.
double laplaceStddev(const LaplaceFit& fit) {
    return std::sqrt(2.0) * fit.b;
}

// Draws Laplace samples (analogous to R's rlaplace).
std::vector<double> rlaplace(size_t n, double mu, double b, std::mt19937_64& rng) {
    std::uniform_real_distribution<double> uniform(0.0, 1.0);
    std::vector<double> samples(n);
    for (double& value : samples) {
        double u = uniform(rng);
        double sign = (u < 0.5) ? 1.0 : -1.0;
        double term = -std::log(1.0 - 2.0 * std::abs(u - 0.5));
        value = mu - b * sign * term;
    }
    return samples;
}
