#pragma once

#include "IParticleForceGenerator.hpp"

namespace nwtn {

    class ParticleDrag : public IParticleForceGenerator {
    private:
        /** Velocity drag coefficient */
        float k1;
        /** Velocity squared drag coefficient */
        float k2;

    public:
        // Constructor
        ParticleDrag(float k1, float k2) : k1(k1), k2(k2) {}

        // Override the updateForce method
        virtual void updateForce(Particle* particle);
    };
}
