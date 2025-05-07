#pragma once

#include "IIntegrator.hpp"
#include <cmath>

namespace nwtn {

    /**
    * @brief Euler particle integrator.
    */

    class EulerIntegrator : public IIntegrator {
    public:
        void integrate(Particle& particle, float deltaTime) override;
    };

}