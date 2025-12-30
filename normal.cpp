#include "normal.hpp"

#include <cmath>

#include "constants.hpp"
#include "stats.hpp"

// Maximum likelihood fit for the normal distribution.
NormalFit normalFit(const std::vector<double>& data) {
    double mu = mean(data);
    double var = variance(data, mu);
    double sigma = std::sqrt(std::max(var, 1e-12));
    return {mu, sigma};
}

// Computes the normal log-likelihood for the fitted parameters.
double normalLogLikelihood(const std::vector<double>& data, const NormalFit& fit) {
    double logLik = 0.0;
    double var = fit.sigma * fit.sigma;
    double logNorm = -0.5 * std::log(2.0 * kPi * var);
    for (double x : data) {
        double diff = x - fit.mu;
        logLik += logNorm - (diff * diff) / (2.0 * var);
    }
    return logLik;
}

// Returns the fitted normal standard deviation (sigma).
double normalStddev(const NormalFit& fit) {
    return fit.sigma;
}

// Generates Gaussian samples (matches R's rnorm helper).
std::vector<double> rnorm(size_t n, double mu, double sigma, std::mt19937_64& rng) {
    std::normal_distribution<double> dist(mu, sigma);
    std::vector<double> samples(n);
    for (double& value : samples) {
        value = dist(rng);
    }
    return samples;
}
