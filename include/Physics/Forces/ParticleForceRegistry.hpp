#ifndef NEWTON_ENGINE_PARTICLEFORCEREGISTRY_HPP
#define NEWTON_ENGINE_PARTICLEFORCEREGISTRY_HPP

#include <vector>
#include "../Dynamics/Particle.hpp"
#include "IParticleForceGenerator.hpp"

namespace nwtn {

    /**
     * @brief A registry for managing particle force generators and the particles they affect.
     */

    class ParticleForceRegistry {
    protected:
        struct RegistryEntry {
            Particle* particle;
            IParticleForceGenerator* fg;
        };

        typedef std::vector<RegistryEntry> Registry;
        Registry registrations;

    public:
        void add(Particle* particle, IParticleForceGenerator* fg) { registrations.push_back({ particle, fg }); }
        void remove(Particle* particle, IParticleForceGenerator* fg);
        void clear() { registrations.clear(); }

        void updateForces();
    };

}

#endif //NEWTON_ENGINE_PARTICLEFORCEREGISTRY_HPP
