#include "../../../include/Physics/Forces/ParticleAnchoredSpring.hpp"

using namespace nwtn;

void ParticleAnchoredSpring::updateForce(nwtn::Particle *particle) {
    Vector2 force = particle->getPosition() -= *anchor;

    float magnitude = std::abs(force.length() - restLength);
    magnitude *= springConstant;

    force.normalize();
    force *= -magnitude;
    particle->addForce(force);
}