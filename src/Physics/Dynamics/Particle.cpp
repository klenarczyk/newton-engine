#include "../../../include/Physics/Dynamics/Particle.hpp"

using namespace nwtn;

float Particle::getMass() const {
    return inverseMass == 0 ? 0 : (1.0f / inverseMass);
}

void Particle::setMass(float mass) {
    inverseMass = (mass == 0) ? 0 : (1.0f / mass);
}

void Particle::setDamping(float newDamping) {
    // Clamp the damping value
    if ( newDamping < 0.0f ) {
        newDamping = 0.0f;
    } else if ( newDamping > 1.0f ) {
        newDamping = 1.0f;
    }

    damping = newDamping;
}