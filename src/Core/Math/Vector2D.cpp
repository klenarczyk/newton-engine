#include "../../../include/Core/Math/Vector2D.hpp"
#include <iostream>
#include <cmath>

namespace nwtn::Math {

// Operators
    Vector2D& Vector2D::operator+=(const Vector2D &other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2D& Vector2D::operator-=(const Vector2D &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Vector2D& Vector2D::operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    Vector2D& Vector2D::operator/=(float scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero");
        }
        x /= scalar;
        y /= scalar;
        return *this;
    }
    Vector2D Vector2D::operator-() const {
        return Vector2D(-x, -y);
    }

    Vector2D operator+(const Vector2D &v1, const Vector2D &v2) {
        Vector2D res = v1;
        return res += v2;
    }
    Vector2D operator-(const Vector2D &v1, const Vector2D &v2) {
        Vector2D res = v1;
        return res -= v2;
    }
    Vector2D operator*(const Vector2D &v, float scalar) {
        Vector2D res = v;
        return res *= scalar;
    }
    Vector2D operator*(float scalar, const Vector2D &v) {
        Vector2D res = v;
        return res *= scalar;
    }
    Vector2D operator/(const Vector2D &v, float scalar) {
        Vector2D res = v;
        return res /= scalar;
    }

// Vector Math
    float Vector2D::length() const {
        return std::sqrt(x * x + y * y);
    }
    float Vector2D::lengthSquared() const {
        return x * x + y * y;
    }
    void Vector2D::normalize() {
        float len = length();
        if (len == 0) {
            throw std::invalid_argument("Cannot normalize a zero-length vector");
        }
        x /= len;
        y /= len;
    }
    float Vector2D::distance(const Vector2D& v1, const Vector2D& v2) {
        return std::sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
    }
    float Vector2D::dot(const Vector2D& v1, const Vector2D& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }
    float Vector2D::cross(const Vector2D& v1, const Vector2D& v2) {
        return (v1.x * v2.y) - (v1.y * v2.x);
    }

// Utility Methods
    std::string Vector2D::toString() const {
        return "Vector2D(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
    void Vector2D::print() const {
        std::cout << this->toString() << std::endl;
    }

}