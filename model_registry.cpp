#include "model_registry.hpp"

#include <vector>

#include "generalized_error.hpp"
#include "hyperbolic_sech.hpp"
#include "laplace.hpp"
#include "logistic.hpp"
#include "normal.hpp"
#include "student_t.hpp"
#include "symmetric_hyperbolic.hpp"

namespace {
FitSummary evaluateNormal(const std::vector<double>& data) {
    // Builds the fit summary for the normal model.
    auto params = normalFit(data);
    return {"Normal", normalLogLikelihood(data, params), params.mu, normalStddev(params), kNormalKurtosis};
}

FitSummary evaluateLaplace(const std::vector<double>& data) {
    // Builds the fit summary for the Laplace model.
    auto params = laplaceFit(data);
    return {"Laplace", laplaceLogLikelihood(data, params), params.mu, laplaceStddev(params), kLaplaceKurtosis};
}

FitSummary evaluateHyperbolicSecant(const std::vector<double>& data) {
    // Builds the fit summary for the hyperbolic secant model.
    auto params = hyperbolicSecantFit(data);
    return {"Hyperbolic Sech", hyperbolicSecantLogLikelihood(data, params), params.mu, hyperbolicSecantStddev(params), kHyperbolicSecantKurtosis};
}

FitSummary evaluateLogistic(const std::vector<double>& data) {
    // Builds the fit summary for the logistic model.
    auto params = logisticFit(data);
    return {"Logistic", logisticLogLikelihood(data, params), params.mu, logisticStddev(params), kLogisticKurtosis};
}

FitSummary evaluateStudentT(const std::vector<double>& data, double df, const std::string& label) {
    // Builds the fit summary for a Student t model with fixed degrees of freedom.
    StudentTFit params = studentTFit(data, df);
    return {label, studentTLogLikelihood(data, params), params.mu, studentTStddev(params), studentTKurtosis(df)};
}

FitSummary evaluateGeneralizedError(const std::vector<double>& data, double power, const std::string& label) {
    // Builds the fit summary for a generalized error model with fixed power.
    GeneralizedErrorFit params = generalizedErrorFit(data, power);
    return {label, generalizedErrorLogLikelihood(data, params), params.mu, generalizedErrorStddev(params), generalizedErrorKurtosis(power)};
}

FitSummary evaluateSymmetricHyperbolic(const std::vector<double>& data) {
    // Builds the fit summary for the symmetric hyperbolic distribution (?=0, ?=1).
    HyperbolicSymmetricFit params = hyperbolicSymmetricFit(data);
    return {"SymHyperbolic", hyperbolicSymmetricLogLikelihood(data, params), params.mu, hyperbolicSymmetricStddev(params), hyperbolicSymmetricKurtosis(params.alpha)};
}

const std::vector<ModelEntry> kModels = {
    {ModelType::Normal, "Normal", evaluateNormal},
    {ModelType::Laplace, "Laplace", evaluateLaplace},
    {ModelType::HyperbolicSecant, "Hyperbolic Sech", evaluateHyperbolicSecant},
    {ModelType::Logistic, "Logistic", evaluateLogistic},
    {ModelType::StudentT3, "t_3", [](const std::vector<double>& data) { return evaluateStudentT(data, 3.0, "t_3"); }},
    {ModelType::StudentT6, "t_6", [](const std::vector<double>& data) { return evaluateStudentT(data, 6.0, "t_6"); }},
    {ModelType::GeneralizedError15, "GED_1.5", [](const std::vector<double>& data) { return evaluateGeneralizedError(data, 1.5, "GED_1.5"); }},
    {ModelType::SymmetricHyperbolic, "SymHyperbolic", evaluateSymmetricHyperbolic},
};
}  // namespace

// Exposes the registry of available models and their evaluation hooks.
const std::vector<ModelEntry>& modelRegistry() {
    return kModels;
}
