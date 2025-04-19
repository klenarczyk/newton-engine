#ifndef NEWTON_ENGINE_PARTICLEGRAVITY_HPP
#define NEWTON_ENGINE_PARTICLEGRAVITY_HPP

#include "IParticleForceGenerator.hpp"

namespace nwtn {

    class ParticleGravity : public IParticleForceGenerator {
    private:
        Vector2 gravity;

    public:
        // Constructor
        ParticleGravity(const Vector2& gravity) : gravity(gravity) {}

        // Override the updateForce method
        virtual void updateForce(Particle* particle, float duration);
    };
}

#endif //NEWTON_ENGINE_PARTICLEGRAVITY_HPP
