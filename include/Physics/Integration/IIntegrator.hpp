#pragma once

#include "../../Physics/Dynamics/Particle.hpp"

namespace nwtn {

    class IIntegrator {
    public:
        virtual void integrate(Particle& particle, float deltaTime) = 0;
        virtual ~IIntegrator() = default;
    };

}
