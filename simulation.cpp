#include "simulation.hpp"

#include <functional>
#include <string>
#include <vector>

#include "generalized_error.hpp"
#include "hyperbolic_sech.hpp"
#include "laplace.hpp"
#include "logistic.hpp"
#include "normal.hpp"
#include "student_t.hpp"
#include "symmetric_hyperbolic.hpp"

namespace {
struct DistributionSpec {
    std::string label;
    std::function<std::vector<double>(size_t, std::mt19937_64&)> sampler;
};

DistributionSpec makeSpec(std::string name, std::function<std::vector<double>(size_t, std::mt19937_64&)> sampler) {
    return DistributionSpec{std::move(name), std::move(sampler)};
}
}

// Generates synthetic datasets from each supported distribution.
std::vector<Dataset> simulateDatasets(size_t sampleCount, size_t groupCount, std::mt19937_64& rng) {
    std::vector<DistributionSpec> specs;
    specs.emplace_back(makeSpec("Normal(mu=0.5, sigma=1.2)", [](size_t n, std::mt19937_64& gen) {
        return rnorm(n, 0.5, 1.2, gen);
    }));
    specs.emplace_back(makeSpec("Laplace(mu=-1.0, b=0.8)", [](size_t n, std::mt19937_64& gen) {
        return rlaplace(n, -1.0, 0.8, gen);
    }));
    specs.emplace_back(makeSpec("Hyperbolic Sech(mu=0.0, sigma=1.0)", [](size_t n, std::mt19937_64& gen) {
        return rhypersecant(n, 0.0, 1.0, gen);
    }));
    specs.emplace_back(makeSpec("Logistic(mu=1.0, scale=0.7)", [](size_t n, std::mt19937_64& gen) {
        return rlogis(n, 1.0, 0.7, gen);
    }));
    specs.emplace_back(makeSpec("t_3(mu=0.0, scale=1.0)", [](size_t n, std::mt19937_64& gen) {
        return rt(n, 0.0, 1.0, 3.0, gen);
    }));
    specs.emplace_back(makeSpec("t_6(mu=0.0, scale=1.0)", [](size_t n, std::mt19937_64& gen) {
        return rt(n, 0.0, 1.0, 6.0, gen);
    }));
    specs.emplace_back(makeSpec("GED_1.5(mu=0.0, beta=1.0)", [](size_t n, std::mt19937_64& gen) {
        return rged(n, 0.0, 1.0, 1.5, gen);
    }));
    specs.emplace_back(makeSpec("SymHyperbolic(mu=0.0, alpha=1.3)", [](size_t n, std::mt19937_64& gen) {
        return rsymmetricHyperbolic(n, 0.0, 1.3, gen);
    }));

    std::vector<Dataset> datasets;
    datasets.reserve(specs.size() * groupCount);
    for (const auto& spec : specs) {
        for (size_t g = 0; g < groupCount; ++g) {
            std::string name = spec.label + " [group " + std::to_string(g + 1) + "]";
            datasets.push_back({name, spec.sampler(sampleCount, rng)});
        }
    }
    return datasets;
}
