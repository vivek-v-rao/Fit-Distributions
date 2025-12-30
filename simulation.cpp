#include "simulation.hpp"

#include "generalized_error.hpp"
#include "hyperbolic_sech.hpp"
#include "laplace.hpp"
#include "logistic.hpp"
#include "normal.hpp"
#include "student_t.hpp"
#include "symmetric_hyperbolic.hpp"

// Generates synthetic datasets from each supported distribution.
std::vector<Dataset> simulateDatasets(size_t sampleCount, std::mt19937_64& rng) {
    std::vector<Dataset> datasets;
    datasets.push_back({"Normal(mu=0.5, sigma=1.2)", rnorm(sampleCount, 0.5, 1.2, rng)});
    datasets.push_back({"Laplace(mu=-1.0, b=0.8)", rlaplace(sampleCount, -1.0, 0.8, rng)});
    datasets.push_back({"Hyperbolic Sech(mu=0.0, sigma=1.0)", rhypersecant(sampleCount, 0.0, 1.0, rng)});
    datasets.push_back({"Logistic(mu=1.0, scale=0.7)", rlogis(sampleCount, 1.0, 0.7, rng)});
    datasets.push_back({"t_3(mu=0.0, scale=1.0)", rt(sampleCount, 0.0, 1.0, 3.0, rng)});
    datasets.push_back({"t_6(mu=0.0, scale=1.0)", rt(sampleCount, 0.0, 1.0, 6.0, rng)});
    datasets.push_back({"GED_1.5(mu=0.0, beta=1.0)", rged(sampleCount, 0.0, 1.0, 1.5, rng)});
    datasets.push_back({"SymHyperbolic(mu=0.0, alpha=1.3)", rsymmetricHyperbolic(sampleCount, 0.0, 1.3, rng)});
    return datasets;
}
