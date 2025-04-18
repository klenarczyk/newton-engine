#include "../../../include/Physics/Integration/EulerIntegrator.hpp"
#include <cmath>

using namespace nwtn;

void EulerIntegrator::integrate(Particle& particle, float deltaTime) {
    if (deltaTime <= 0.0f) return;

    Vector2 newVelocity = particle.getVelocity() + (particle.getAcceleration() * deltaTime);

    // Apply damping
    newVelocity *= std::pow(particle.getDamping(), deltaTime);

    // Update position (acceleration omitted because of small deltaTime)
    Vector2 newPosition = particle.getPosition() + (newVelocity * deltaTime);

    particle.setPosition(newPosition);
    particle.setVelocity(newVelocity);
}