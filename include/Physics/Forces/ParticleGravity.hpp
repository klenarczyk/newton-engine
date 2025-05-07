#pragma once

#include "IParticleForceGenerator.hpp"

namespace nwtn {

    class ParticleGravity : public IParticleForceGenerator {
    private:
        Vector2 gravity;

    public:
        // Constructor
        ParticleGravity(const Vector2& gravity) : gravity(gravity) {}

        // Override the updateForce method
        virtual void updateForce(Particle* particle);
    };
}
