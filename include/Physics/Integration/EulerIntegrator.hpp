#ifndef NEWTON_ENGINE_EULERINTEGRATOR_HPP
#define NEWTON_ENGINE_EULERINTEGRATOR_HPP

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

#endif //NEWTON_ENGINE_EULERINTEGRATOR_HPP
