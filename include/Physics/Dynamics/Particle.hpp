#ifndef NEWTON_ENGINE_PARTICLE_HPP
#define NEWTON_ENGINE_PARTICLE_HPP

#include "../../Core/Math/Vector2.hpp"

namespace nwtn {

    /**
    * @brief A simple particle (point with mass).
    */

    class Particle {
    private:
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;
        float damping;

        float inverseMass;

    public:
        // Constructors
        Particle() : position(0, 0), velocity(0, 0), acceleration(0, 0), damping(0.995f), inverseMass(1.0f) {}
        Particle(const Vector2& position, const Vector2& velocity, const Vector2& acceleration, float damping, float inverseMass)
            : position(position), velocity(velocity), acceleration(acceleration), damping(damping), inverseMass(inverseMass) {}

        // Getters and Setters
        Vector2 getPosition() const { return position; }
        Vector2 getVelocity() const { return velocity; }
        Vector2 getAcceleration() const { return acceleration; }
        float getDamping() const { return damping; }
        float getInverseMass() const { return inverseMass; }
        float getMass() const;
        void setPosition(const Vector2& newPosition) { position = newPosition; }
        void setPosition(float x, float y) { position.x = x; position.y = y; }
        void setVelocity(const Vector2& newVelocity) { velocity = newVelocity; }
        void setVelocity(float x, float y) { velocity.x = x; velocity.y = y; }
        void setAcceleration(const Vector2& newAcceleration) { acceleration = newAcceleration; }
        void setAcceleration(float x, float y) { acceleration.x = x; acceleration.y = y; }
        void setDamping(float newDamping);
        void setInverseMass(float newInverseMass) { inverseMass = newInverseMass; }
        void setMass(float mass);
    };

}

#endif //NEWTON_ENGINE_PARTICLE_HPP
