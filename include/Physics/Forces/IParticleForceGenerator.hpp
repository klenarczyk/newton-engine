#ifndef NEWTON_ENGINE_IPARTICLEFORCEGENERATOR_HPP
#define NEWTON_ENGINE_IPARTICLEFORCEGENERATOR_HPP

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

#endif //NEWTON_ENGINE_IPARTICLEFORCEGENERATOR_HPP
