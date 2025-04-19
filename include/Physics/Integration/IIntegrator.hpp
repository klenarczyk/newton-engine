#ifndef NEWTON_ENGINE_IINTEGRATOR_HPP
#define NEWTON_ENGINE_IINTEGRATOR_HPP

#include "../../Physics/Dynamics/Particle.hpp"

namespace nwtn {

    class IIntegrator {
    public:
        virtual void integrate(Particle& particle, float deltaTime) = 0;
        virtual ~IIntegrator() = default;
    };

}

#endif //NEWTON_ENGINE_IINTEGRATOR_HPP
