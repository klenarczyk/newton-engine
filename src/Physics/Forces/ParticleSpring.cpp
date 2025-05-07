#include "../../../include/Physics/Forces/ParticleSpring.hpp"
#include <cmath>

using namespace nwtn;

void ParticleSpring::updateForce(nwtn::Particle *particle) {
    Vector2 force = particle->getPosition() - other->getPosition();

    float magnitude = fabsf(force.length() - restLength) * springConstant;

    force.normalize();
    force *= -magnitude;
    particle->addForce(force);
}