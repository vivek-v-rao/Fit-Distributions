#include "hyperbolic_sech.hpp"

#include <algorithm>
#include <cmath>

#include "constants.hpp"
#include "stats.hpp"

// Moment-based scale and location for the hyperbolic secant distribution.
HyperbolicSecantFit hyperbolicSecantFit(const std::vector<double>& data) {
    double mu = mean(data);
    double var = variance(data, mu);
    double sigma = std::sqrt(std::max(var, 1e-12));
    return {mu, sigma};
}

// Hyperbolic secant log-likelihood derived from its PDF.
double hyperbolicSecantLogLikelihood(const std::vector<double>& data, const HyperbolicSecantFit& fit) {
    double logLik = 0.0;
    double coeff = -std::log(2.0 * fit.sigma);
    for (double x : data) {
        double arg = (kPi * (x - fit.mu)) / (2.0 * fit.sigma);
        logLik += coeff - std::log(std::cosh(arg));
    }
    return logLik;
}

// Returns the fitted hyperbolic secant standard deviation.
double hyperbolicSecantStddev(const HyperbolicSecantFit& fit) {
    return fit.sigma;
}

// Samples from the hyperbolic secant distribution (R's rhypersecant).
std::vector<double> rhypersecant(size_t n, double mu, double sigma, std::mt19937_64& rng) {
    std::uniform_real_distribution<double> uniform(0.0, 1.0);
    std::vector<double> samples(n);
    const double epsilon = 1e-12;
    for (double& value : samples) {
        double u = uniform(rng);
        u = std::clamp(u, epsilon, 1.0 - epsilon);
        double inside = std::tan((kPi * 0.5) * u);
        value = mu + sigma * (2.0 / kPi) * std::log(inside);
    }
    return samples;
}
