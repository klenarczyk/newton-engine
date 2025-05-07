#include "../../../include/Physics/Integration/EulerIntegrator.hpp"

using namespace nwtn;

void EulerIntegrator::integrate(Particle& particle, float deltaTime) {
    if (deltaTime <= 0.0f) return;

    // Calculate new acceleration
    Vector2 resAcc = particle.getForceAccum() * particle.getInverseMass();

    Vector2 newVelocity = particle.getVelocity() + (resAcc * deltaTime);


    // Update position (acceleration omitted because of small deltaTime)
    Vector2 newPosition = particle.getPosition() + (newVelocity * deltaTime);

    particle.setPosition(newPosition);
    particle.setVelocity(newVelocity);
    particle.clearAccumulator();
}