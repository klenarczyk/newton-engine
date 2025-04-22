#include "../../../include/Physics/Forces/ParticleGravity.hpp"

using namespace nwtn;

void ParticleGravity::updateForce(Particle* particle) {
    // Check if the particle has infinite mass
    if (particle->getInverseMass() == 0) { return; }

    particle->addForce(gravity * particle->getMass());
}