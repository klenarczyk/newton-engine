#pragma once

#include "../Dynamics/Particle.hpp"

namespace nwtn {

    class IParticleForceGenerator {
    public:
        /**
         * @brief Applies the force to the particle.
         */
        virtual void updateForce(Particle* particle) = 0;
    };

}
