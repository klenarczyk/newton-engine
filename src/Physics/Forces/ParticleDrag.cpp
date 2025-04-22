#include "../../../include/Physics/Forces/ParticleDrag.hpp"

using namespace nwtn;

void ParticleDrag::updateForce(Particle* particle) {
    if (particle->getVelocity().isZero()) {
        return;
    }

    Vector2 v = particle->getVelocity();
    float speed = v.length();

    Vector2 drag = -v.normalized() * speed * (k1 + k2 * speed);

    particle->addForce(drag);
}