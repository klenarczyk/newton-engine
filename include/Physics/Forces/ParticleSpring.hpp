#pragma once

#include "./IParticleForceGenerator.hpp"
#include "../Dynamics/Particle.hpp"

namespace nwtn {

    class ParticleSpring : public IParticleForceGenerator {
    private:
        /** Particle at the end of the spring */
        Particle *other;

        float springConstant;
        float restLength;

    public:
        ParticleSpring(Particle *other, float springConstant, float restLength)
            : other(other), springConstant(springConstant), restLength(restLength) {}

        virtual void updateForce(Particle *particle);

        /** Getters & Setters */
        float getSpringConstant() const { return springConstant; }
        float getRestLength() const { return restLength; }
        void setSpringConstant(float newSprConst) { this->springConstant = newSprConst; }
        void setRestLength(float newRestLength) { this->restLength = newRestLength; }
    };

}
