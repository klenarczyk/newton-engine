#pragma once

#include "IParticleForceGenerator.hpp"

namespace nwtn {

    class ParticleGravity : public IParticleForceGenerator {
    private:
        Vector2 gravity;

    public:
        // Constructor
        explicit ParticleGravity(const Vector2& gravity) : gravity(gravity) {}

        // Override the updateForce method
        void updateForce(Particle* particle) override;
    };
}
