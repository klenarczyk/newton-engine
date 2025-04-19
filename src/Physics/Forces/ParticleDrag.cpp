#include "../../../include/Physics/Forces/ParticleDrag.hpp"

using namespace nwtn;

void ParticleDrag::updateForce(Particle* particle, float duration) {
    Vector2 force = particle->getVelocity();
    float dragCoeff = force.length();
    dragCoeff = (k1 + k2 * dragCoeff) * dragCoeff;

    // Normalize and apply the drag force
    force.normalize();
    force *= -dragCoeff;
    particle->addForce(force);
}