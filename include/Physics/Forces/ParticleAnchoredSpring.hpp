#pragma once

#include "./IParticleForceGenerator.hpp"

namespace nwtn {

    /**
     * @brief A spring force generator that is anchored to a fixed point in space.
     */

    class ParticleAnchoredSpring : public IParticleForceGenerator {
    private:
        Vector2* anchor;

        float springConstant;
        float restLength;

    public:
        ParticleAnchoredSpring(Vector2* anchor, float springConstant, float restLength)
            : anchor(anchor), springConstant(springConstant), restLength(restLength) {};

        void updateForce(Particle* particle) override;

        /** Getters & Setters */
        [[nodiscard]] float getSpringConstant() const { return springConstant; }
        [[nodiscard]] float getRestLength() const { return restLength; }
        void setSpringConstant(float newSprConst) { this->springConstant = newSprConst; }
        void setRestLength(float newRestLength) { this->restLength = newRestLength; }
    };

}
