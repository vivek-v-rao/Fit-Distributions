#include "symmetric_hyperbolic.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <random>

#include "constants.hpp"
#include "stats.hpp"

namespace {
double varianceFromAlpha(double alpha) {
    double k1 = std::cyl_bessel_k(1.0, alpha);
    double k2 = std::cyl_bessel_k(2.0, alpha);
    if (k1 <= 0.0) {
        return std::numeric_limits<double>::infinity();
    }
    return k2 / (alpha * k1);
}

// Solves for alpha so the theoretical variance matches the sample variance.
double solveAlpha(double targetVar) {
    if (!(targetVar > 0.0)) {
        return 1.0;
    }
    double low = 1e-6;
    double high = 1.0;
    while (varianceFromAlpha(high) > targetVar) {
        high *= 2.0;
        if (high > 1e6) {
            break;
        }
    }
    for (int i = 0; i < 80; ++i) {
        double mid = 0.5 * (low + high);
        double varMid = varianceFromAlpha(mid);
        if (varMid > targetVar) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return std::max(0.5 * (low + high), 1e-6);
}

double logCoefficient(double alpha) {
    return std::log(alpha) + alpha - std::log(kPi);
}

double pdfValue(double diff, double alpha) {
    double r = std::sqrt(1.0 + diff * diff);
    double k0 = std::cyl_bessel_k(0.0, alpha * r);
    return (alpha * std::exp(alpha) / kPi) * k0;
}

double proposalDensity(double x, double scale) {
    double z = x / scale;
    return 1.0 / (kPi * scale * (1.0 + z * z));
}

double computeProposalBound(double alpha, double scale) {
    double bound = 0.0;
    const double maxX = 25.0;
    const int steps = 50000;
    for (int i = 0; i <= steps; ++i) {
        double x = -maxX + (2.0 * maxX * i) / steps;
        double ratio = pdfValue(x, alpha) / proposalDensity(x, scale);
        bound = std::max(bound, ratio);
    }
    return bound * 1.05;
}
}

// Fits the symmetric hyperbolic distribution (? = 1/2, ? = 0, ? = 1).
HyperbolicSymmetricFit hyperbolicSymmetricFit(const std::vector<double>& data) {
    double mu = mean(data);
    double var = variance(data, mu);
    double alpha = solveAlpha(var);
    return {mu, alpha};
}

// Computes the log-likelihood for the fitted symmetric hyperbolic model.
double hyperbolicSymmetricLogLikelihood(const std::vector<double>& data, const HyperbolicSymmetricFit& fit) {
    double logCoef = logCoefficient(fit.alpha);
    double logLik = 0.0;
    for (double x : data) {
        double diff = x - fit.mu;
        double r = std::sqrt(1.0 + diff * diff);
        double k0 = std::cyl_bessel_k(0.0, fit.alpha * r);
        if (k0 <= 0.0) {
            continue;
        }
        logLik += logCoef + std::log(k0);
    }
    return logLik;
}

// Returns the implied standard deviation from the fitted alpha.
double hyperbolicSymmetricStddev(const HyperbolicSymmetricFit& fit) {
    double var = varianceFromAlpha(fit.alpha);
    return std::sqrt(std::max(var, 0.0));
}

// Provides the theoretical kurtosis for the symmetric hyperbolic distribution.
double hyperbolicSymmetricKurtosis(double alpha) {
    double k1 = std::cyl_bessel_k(1.0, alpha);
    double k2 = std::cyl_bessel_k(2.0, alpha);
    double k3 = std::cyl_bessel_k(3.0, alpha);
    if (k2 == 0.0) {
        return std::numeric_limits<double>::infinity();
    }
    return 3.0 * k3 * k1 / (k2 * k2);
}

// Samples from the symmetric hyperbolic distribution using rejection sampling.
std::vector<double> rsymmetricHyperbolic(size_t n, double mu, double alpha, std::mt19937_64& rng) {
    std::vector<double> samples(n);
    double scale = std::max(0.75, 1.0 / alpha);
    std::cauchy_distribution<double> proposal(0.0, scale);
    double bound = computeProposalBound(alpha, scale);
    std::uniform_real_distribution<double> uni(0.0, 1.0);

    for (double& value : samples) {
        while (true) {
            double candidate = proposal(rng);
            double target = pdfValue(candidate, alpha);
            double prop = proposalDensity(candidate, scale);
            double acceptProb = target / (bound * prop);
            if (uni(rng) <= acceptProb) {
                value = mu + candidate;
                break;
            }
        }
    }
    return samples;
}
