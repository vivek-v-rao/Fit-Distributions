#include "student_t.hpp"

#include <cmath>
#include <limits>
#include <random>

#include "constants.hpp"
#include "stats.hpp"

// Fits a Student t distribution with fixed degrees of freedom.
StudentTFit studentTFit(const std::vector<double>& data, double df) {
    double mu = mean(data);
    double var = variance(data, mu);
    double sigma = 0.0;
    if (df > 2.0) {
        sigma = std::sqrt(std::max(var, 1e-12) * (df - 2.0) / df);
    } else {
        sigma = std::sqrt(std::max(var, 1e-12));
    }
    return {mu, std::max(sigma, 1e-12), df};
}

// Computes the Student t log-likelihood for the fitted parameters.
double studentTLogLikelihood(const std::vector<double>& data, const StudentTFit& fit) {
    double logLik = 0.0;
    double df = fit.df;
    double invScaleSq = 1.0 / (fit.sigma * fit.sigma);
    double logNorm = std::lgamma((df + 1.0) / 2.0) - std::lgamma(df / 2.0) - 0.5 * std::log(df * kPi) - std::log(fit.sigma);
    for (double x : data) {
        double z = (x - fit.mu);
        double inner = 1.0 + (z * z * invScaleSq) / df;
        logLik += logNorm - ((df + 1.0) / 2.0) * std::log(inner);
    }
    return logLik;
}

// Returns the implied Student t standard deviation.
double studentTStddev(const StudentTFit& fit) {
    if (fit.df > 2.0) {
        return fit.sigma * std::sqrt(fit.df / (fit.df - 2.0));
    }
    return std::numeric_limits<double>::infinity();
}

// Provides the theoretical kurtosis for the specified degrees of freedom.
double studentTKurtosis(double df) {
    if (df > 4.0) {
        return 6.0 / (df - 4.0);
    }
    return std::numeric_limits<double>::infinity();
}

// Generates Student t samples with fixed degrees of freedom.
std::vector<double> rt(size_t n, double mu, double sigma, double df, std::mt19937_64& rng) {
    std::student_t_distribution<double> dist(df);
    std::vector<double> samples(n);
    for (double& value : samples) {
        value = mu + sigma * dist(rng);
    }
    return samples;
}
