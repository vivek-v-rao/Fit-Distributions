#pragma once

#include <vector>

double mean(const std::vector<double>& data);
double variance(const std::vector<double>& data, double mean);
double median(std::vector<double> data);
double log1pExp(double x);
double kurtosis(const std::vector<double>& data, double mean);
