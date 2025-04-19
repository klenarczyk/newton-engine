#include <gtest/gtest.h>
#include "../../../include/Core/Math/Vector2.hpp"

using namespace nwtn;

TEST(Vector2Tests, AdditionOfTwoVectors) {
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(3.0f, 4.0f);
    Vector2 result = v1 + v2;
    EXPECT_FLOAT_EQ(result.x, 4.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
}

TEST(Vector2Tests, SubtractionOfTwoVectors) {
    Vector2 v1(5.0f, 7.0f);
    Vector2 v2(2.0f, 3.0f);
    Vector2 result = v1 - v2;
    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(Vector2Tests, ScalarMultiplication) {
    Vector2 v(2.0f, 3.0f);
    Vector2 result = v * 2.0f;
    EXPECT_FLOAT_EQ(result.x, 4.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
}

TEST(Vector2Tests, ScalarDivision) {
    Vector2 v(6.0f, 8.0f);
    Vector2 result = v / 2.0f;
    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(Vector2Tests, ScalarDivisionByZeroThrows) {
    Vector2 v(1.0f, 1.0f);
    EXPECT_THROW(v / 0.0f, std::invalid_argument);
}

TEST(Vector2Tests, NegationOfVector) {
    Vector2 v(3.0f, -4.0f);
    Vector2 result = -v;
    EXPECT_FLOAT_EQ(result.x, -3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(Vector2Tests, LengthOfVector) {
    Vector2 v(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.length(), 5.0f);
}

TEST(Vector2Tests, LengthSquaredOfVector) {
    Vector2 v(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.lengthSquared(), 25.0f);
}

TEST(Vector2Tests, NormalizeVector) {
    Vector2 v(3.0f, 4.0f);
    v.normalize();
    EXPECT_FLOAT_EQ(v.length(), 1.0f);
    EXPECT_FLOAT_EQ(v.x, 0.6f);
    EXPECT_FLOAT_EQ(v.y, 0.8f);
}

TEST(Vector2Tests, DistanceBetweenTwoVectors) {
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(4.0f, 6.0f);
    EXPECT_FLOAT_EQ(Vector2::distance(v1, v2), 5.0f);
}

TEST(Vector2Tests, DotProductOfTwoVectors) {
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(Vector2::dot(v1, v2), 11.0f);
}

TEST(Vector2Tests, CrossProductOfTwoVectors) {
    Vector2 v1(1.0f, 2.0f);
    Vector2 v2(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(Vector2::cross(v1, v2), -2.0f);
}