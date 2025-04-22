#include <gtest/gtest.h>
#include "../../../include/Physics/Integration/EulerIntegrator.hpp"
#include "../../../include/Physics/Dynamics/Particle.hpp"

using namespace nwtn;

class EulerIntegratorTests : public ::testing::Test {
protected:
    EulerIntegrator integrator;
    Particle particle;

    void SetUp() override {
        particle.setPosition(Vector2(0.0f, 0.0f));
        particle.setVelocity(Vector2(1.0f, 1.0f));
        particle.setAcceleration(Vector2(0.0f, -10.0f));
        particle.setDamping(0.98f);
    }
};

TEST_F(EulerIntegratorTests, UpdatesPositionAndVelocityCorrectly) {
integrator.integrate(particle, 1.0f);
EXPECT_NEAR(particle.getPosition().x, 0.98f, 1e-5);
EXPECT_NEAR(particle.getPosition().y, -8.82f, 1e-5);
EXPECT_NEAR(particle.getVelocity().x, 0.98f, 1e-5);
EXPECT_NEAR(particle.getVelocity().y, -8.82f, 1e-5);
}

TEST_F(EulerIntegratorTests, DoesNotUpdateForZeroDeltaTime) {
Vector2 initialPosition = particle.getPosition();
Vector2 initialVelocity = particle.getVelocity();
integrator.integrate(particle, 0.0f);
EXPECT_EQ(particle.getPosition(), initialPosition);
EXPECT_EQ(particle.getVelocity(), initialVelocity);
}

TEST_F(EulerIntegratorTests, DoesNotUpdateForNegativeDeltaTime) {
Vector2 initialPosition = particle.getPosition();
Vector2 initialVelocity = particle.getVelocity();
integrator.integrate(particle, -1.0f);
EXPECT_EQ(particle.getPosition(), initialPosition);
EXPECT_EQ(particle.getVelocity(), initialVelocity);
}

TEST_F(EulerIntegratorTests, HandlesSmallDeltaTime) {
integrator.integrate(particle, 0.01f);
EXPECT_NEAR(particle.getPosition().x, 0.009998f, 1e-5);
EXPECT_NEAR(particle.getPosition().y, 0.008991f, 1e-5);
EXPECT_NEAR(particle.getVelocity().x, 0.999798f, 1e-5);
EXPECT_NEAR(particle.getVelocity().y, 0.899818f, 1e-5);
}

TEST_F(EulerIntegratorTests, HandlesHighDamping) {
particle.setDamping(1.0f);
integrator.integrate(particle, 1.0f);
EXPECT_NEAR(particle.getVelocity().x, 1.0f, 1e-5);
EXPECT_NEAR(particle.getVelocity().y, -9.0f, 1e-5);
}