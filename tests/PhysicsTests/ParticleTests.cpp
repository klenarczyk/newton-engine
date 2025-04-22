#include <gtest/gtest.h>
#include "../../include/Physics/Dynamics/Particle.hpp"
#include "../../include/Core/Math/Vector2.hpp"

using namespace nwtn;

TEST(ParticleBehavior, SetAndGetMass) {
Particle particle;
particle.setMass(2.0f);
EXPECT_FLOAT_EQ(particle.getMass(), 2.0f);
EXPECT_FLOAT_EQ(particle.getInverseMass(), 0.5f);

particle.setMass(0.0f); // Edge case: infinite mass
EXPECT_FLOAT_EQ(particle.getMass(), 0.0f);
EXPECT_FLOAT_EQ(particle.getInverseMass(), 0.0f);
}

TEST(ParticleBehavior, SetPositionUpdatesCorrectly) {
Particle particle;
particle.setPosition(Vector2(7.0f, 8.0f));
EXPECT_EQ(particle.getPosition(), Vector2(7.0f, 8.0f));

particle.setPosition(9.0f, 10.0f);
EXPECT_EQ(particle.getPosition(), Vector2(9.0f, 10.0f));
}

TEST(ParticleBehavior, SetVelocityUpdatesCorrectly) {
Particle particle;
particle.setVelocity(Vector2(1.0f, 2.0f));
EXPECT_EQ(particle.getVelocity(), Vector2(1.0f, 2.0f));

particle.setVelocity(3.0f, 4.0f);
EXPECT_EQ(particle.getVelocity(), Vector2(3.0f, 4.0f));
}

TEST(ParticleBehavior, SetAccelerationUpdatesCorrectly) {
Particle particle;
particle.setAcceleration(Vector2(0.5f, 0.6f));
EXPECT_EQ(particle.getAcceleration(), Vector2(0.5f, 0.6f));

particle.setAcceleration(0.7f, 0.8f);
EXPECT_EQ(particle.getAcceleration(), Vector2(0.7f, 0.8f));
}

TEST(ParticleBehavior, SetDampingUpdatesCorrectly) {
Particle particle;
particle.setDamping(1.5f);
EXPECT_FLOAT_EQ(particle.getDamping(), 1.0f);
}

TEST(ParticleBehavior, SetInverseMassUpdatesCorrectly) {
Particle particle;
particle.setInverseMass(0.25f);
EXPECT_FLOAT_EQ(particle.getInverseMass(), 0.25f);
EXPECT_FLOAT_EQ(particle.getMass(), 4.0f);
}