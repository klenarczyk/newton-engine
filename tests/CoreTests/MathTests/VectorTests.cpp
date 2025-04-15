#include <gtest/gtest.h>
#include "../../../include/Core/Math/Vector2D.hpp"

using namespace nwtn::Math;

TEST(Vector2DTests, AdditionOfTwoVectors) {
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(3.0f, 4.0f);
    Vector2D result = v1 + v2;
    EXPECT_FLOAT_EQ(result.getX(), 4.0f);
    EXPECT_FLOAT_EQ(result.getY(), 6.0f);
}

TEST(Vector2DTests, SubtractionOfTwoVectors) {
    Vector2D v1(5.0f, 7.0f);
    Vector2D v2(2.0f, 3.0f);
    Vector2D result = v1 - v2;
    EXPECT_FLOAT_EQ(result.getX(), 3.0f);
    EXPECT_FLOAT_EQ(result.getY(), 4.0f);
}

TEST(Vector2DTests, ScalarMultiplication) {
    Vector2D v(2.0f, 3.0f);
    Vector2D result = v * 2.0f;
    EXPECT_FLOAT_EQ(result.getX(), 4.0f);
    EXPECT_FLOAT_EQ(result.getY(), 6.0f);
}

TEST(Vector2DTests, ScalarDivision) {
    Vector2D v(6.0f, 8.0f);
    Vector2D result = v / 2.0f;
    EXPECT_FLOAT_EQ(result.getX(), 3.0f);
    EXPECT_FLOAT_EQ(result.getY(), 4.0f);
}

TEST(Vector2DTests, ScalarDivisionByZeroThrows) {
    Vector2D v(1.0f, 1.0f);
    EXPECT_THROW(v / 0.0f, std::invalid_argument);
}

TEST(Vector2DTests, NegationOfVector) {
    Vector2D v(3.0f, -4.0f);
    Vector2D result = -v;
    EXPECT_FLOAT_EQ(result.getX(), -3.0f);
    EXPECT_FLOAT_EQ(result.getY(), 4.0f);
}

TEST(Vector2DTests, LengthOfVector) {
    Vector2D v(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.length(), 5.0f);
}

TEST(Vector2DTests, LengthSquaredOfVector) {
    Vector2D v(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.lengthSquared(), 25.0f);
}

TEST(Vector2DTests, NormalizeVector) {
    Vector2D v(3.0f, 4.0f);
    v.normalize();
    EXPECT_FLOAT_EQ(v.length(), 1.0f);
    EXPECT_FLOAT_EQ(v.getX(), 0.6f);
    EXPECT_FLOAT_EQ(v.getY(), 0.8f);
}

TEST(Vector2DTests, DistanceBetweenTwoVectors) {
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(4.0f, 6.0f);
    EXPECT_FLOAT_EQ(Vector2D::distance(v1, v2), 5.0f);
}

TEST(Vector2DTests, DotProductOfTwoVectors) {
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(Vector2D::dot(v1, v2), 11.0f);
}

TEST(Vector2DTests, CrossProductOfTwoVectors) {
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(Vector2D::cross(v1, v2), -2.0f);
}