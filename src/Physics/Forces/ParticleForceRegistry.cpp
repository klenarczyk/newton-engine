#include "../../../include/Physics/Forces/ParticleForceRegistry.hpp"

using namespace nwtn;

void ParticleForceRegistry::remove(Particle* particle, IParticleForceGenerator* fg) {
    for (unsigned int i = 0; i < registrations.size(); ++i) {
        if (registrations[i].particle == particle && registrations[i].fg == fg) {
            registrations.erase(registrations.begin() + i);
            break;
        }
    }
}

void ParticleForceRegistry::updateForces() {
    for (const RegistryEntry& entry : registrations) {
        entry.fg->updateForce(entry.particle);
    }
}