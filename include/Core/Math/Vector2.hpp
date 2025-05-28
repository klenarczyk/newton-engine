#pragma once

#include <string>

namespace nwtn {

    /**
    * @brief A 2D vector class.
    */

    class Vector2 {
    public:
        float x, y;

        // Constructors
        Vector2() : x(0), y(0) {};
        Vector2(float x, float y) : x(x), y(y) {};

        // Operators
        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2& operator*=(float scalar);
        Vector2& operator/=(float scalar);
        Vector2 operator+(const Vector2& v2) { return *this += v2; }
        Vector2 operator-(const Vector2& v2) { return *this -= v2; }
        Vector2 operator*(float scalar) { return *this *= scalar; }
        Vector2 operator/(float scalar) { return *this /= scalar; }
        Vector2 operator-() const;
        bool operator==(const Vector2& v2) const { return (this->x == v2.x && this->y == v2.y); }

        float length() const;
        float lengthSquared() const;
        void normalize();
        Vector2 normalized() const;
        bool isZero() const;
        void invert();

        // Static methods
        static float distance(const Vector2& v1, const Vector2& v2);
        static float dot(const Vector2& v1, const Vector2& v2);
        static float cross(const Vector2& v1, const Vector2& v2);

        // Utilities
        std::string toString() const;
        void print() const;
    }; // Vector2
}
