#include "../../../include/Physics/Dynamics/Particle.hpp"

#include <cmath>

using namespace nwtn;

float Particle::getMass() const {
    return inverseMass == 0 ? std::numeric_limits<float>::max() : (1.0f / inverseMass);
}

void Particle::setMass(float mass) {
    inverseMass = (mass == 0) ? std::numeric_limits<float>::max() : (1.0f / mass);
}