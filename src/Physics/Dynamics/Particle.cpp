#include "../../../include/Physics/Dynamics/Particle.hpp"

using namespace nwtn;

float Particle::getMass() const {
    return inverseMass == 0 ? 0 : (1.0f / inverseMass);
}

void Particle::setMass(float mass) {
    inverseMass = (mass == 0) ? 0 : (1.0f / mass);
}