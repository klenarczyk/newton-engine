#ifndef NEWTON_ENGINE_VECTOR2D_HPP
#define NEWTON_ENGINE_VECTOR2D_HPP

#include <string>

namespace nwtn::Math {

    /**
    * @brief A 2D vector class.
    */

    class Vector2D {
    private:
        float x, y;

    public:
        // Constructors
        Vector2D() : x(0), y(0) {};
        Vector2D(float x, float y) : x(x), y(y) {};

        // Getters and Setters
        float getX() const { return x; }
        float getY() const { return y; }
        void setX(float new_x) { x = new_x; }
        void setY(float new_y) { y = new_y; }

        // Operators
        Vector2D& operator+=(const Vector2D& other);
        Vector2D& operator-=(const Vector2D& other);
        Vector2D& operator*=(float scalar);
        Vector2D& operator/=(float scalar);
        Vector2D operator-() const;

        float length() const;
        float lengthSquared() const;
        void normalize();

        // Static methods
        static float distance(const Vector2D& v1, const Vector2D& v2);
        static float dot(const Vector2D& v1, const Vector2D& v2);
        static float cross(const Vector2D& v1, const Vector2D& v2);

        // Utilities
        std::string toString() const;
        void print() const;
    }; // Vector2D

    // Non-member operators
    Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
    Vector2D operator-(const Vector2D& v1, const Vector2D& v2);
    Vector2D operator*(const Vector2D& v, float scalar);
    Vector2D operator*(float scalar, const Vector2D& v);
    Vector2D operator/(const Vector2D& v, float scalar);
}

#endif //NEWTON_ENGINE_VECTOR2D_HPP
