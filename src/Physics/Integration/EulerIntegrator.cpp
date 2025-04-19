#include "../../../include/Physics/Integration/EulerIntegrator.hpp"
#include <cmath>

using namespace nwtn;

void EulerIntegrator::integrate(Particle& particle, float deltaTime) {
    if (deltaTime <= 0.0f) return;
    // equation v' = v*d^t + at with damping given as d^t
    Vector2 newVelocity = particle.getVelocity()*std::pow(particle.getDamping(), deltaTime) + (particle.getAcceleration() * deltaTime);

    // Update position (acceleration omitted because of small deltaTime)
    Vector2 newPosition = particle.getPosition() + (newVelocity * deltaTime);

    particle.setPosition(newPosition);
    particle.setVelocity(newVelocity);
}