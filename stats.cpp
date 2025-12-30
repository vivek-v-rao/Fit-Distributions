#include "stats.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>

// Computes the arithmetic mean of the samples or returns 0 when empty.
double mean(const std::vector<double>& data) {
    if (data.empty()) {
        return 0.0;
    }
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / static_cast<double>(data.size());
}

// Returns the population variance around the provided mean.
double variance(const std::vector<double>& data, double mean) {
    if (data.empty()) {
        return 0.0;
    }
    double accum = 0.0;
    for (double x : data) {
        double diff = x - mean;
        accum += diff * diff;
    }
    return accum / static_cast<double>(data.size());
}

// Calculates the sample median by sorting a copy of the data.
double median(std::vector<double> data) {
    if (data.empty()) {
        return 0.0;
    }
    std::sort(data.begin(), data.end());
    size_t n = data.size();
    if (n % 2 == 1) {
        return data[n / 2];
    }
    return 0.5 * (data[n / 2 - 1] + data[n / 2]);
}

// Stable helper computing log(1 + exp(x)).
double log1pExp(double x) {
    if (x > 0) {
        return x + std::log1p(std::exp(-x));
    }
    return std::log1p(std::exp(x));
}

// Computes the population kurtosis using the provided mean.
double kurtosis(const std::vector<double>& data, double mean) {
    if (data.empty()) {
        return 0.0;
    }
    double m2 = 0.0;
    double m4 = 0.0;
    for (double x : data) {
        double diff = x - mean;
        double diff2 = diff * diff;
        m2 += diff2;
        m4 += diff2 * diff2;
    }
    if (m2 == 0.0) {
        return 0.0;
    }
    double n = static_cast<double>(data.size());
    m2 /= n;
    m4 /= n;
    return m4 / (m2 * m2);
}
