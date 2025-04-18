#include "../../../include/Core/Math/Vector2.hpp"
#include <iostream>
#include <cmath>

namespace nwtn {

// Operators
    Vector2& Vector2::operator+=(const Vector2 &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2 &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2& Vector2::operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2& Vector2::operator/=(float scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero");
        }
        x /= scalar;
        y /= scalar;
        return *this;
    }

    Vector2 Vector2::operator-() const {
        return Vector2(-x, -y);
    }

    Vector2 operator+(const Vector2 &v1, const Vector2 &v2) {
        Vector2 res = v1;
        return res += v2;
    }

    Vector2 operator-(const Vector2 &v1, const Vector2 &v2) {
        Vector2 res = v1;
        return res -= v2;
    }

    Vector2 operator*(const Vector2 &v, float scalar) {
        Vector2 res = v;
        return res *= scalar;
    }

    Vector2 operator*(float scalar, const Vector2 &v) {
        Vector2 res = v;
        return res *= scalar;
    }

    Vector2 operator/(const Vector2 &v, float scalar) {
        Vector2 res = v;
        return res /= scalar;
    }

// Vector Math
    float Vector2::length() const {
        return std::sqrt(x * x + y * y);
    }

    float Vector2::lengthSquared() const {
        return x * x + y * y;
    }

    void Vector2::normalize() {
        float len = length();
        if (len == 0) {
            throw std::invalid_argument("Cannot normalize a zero-length vector");
        }
        x /= len;
        y /= len;
    }

    float Vector2::distance(const Vector2& v1, const Vector2& v2) {
        return std::sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
    }

    float Vector2::dot(const Vector2& v1, const Vector2& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    float Vector2::cross(const Vector2& v1, const Vector2& v2) {
        return (v1.x * v2.y) - (v1.y * v2.x);
    }

// Utility Methods
    std::string Vector2::toString() const {
        return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    void Vector2::print() const {
        std::cout << this->toString() << std::endl;
    }
}