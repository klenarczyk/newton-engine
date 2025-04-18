#ifndef NEWTON_ENGINE_Vector2_HPP
#define NEWTON_ENGINE_Vector2_HPP

#include <string>

namespace nwtn::Math {

    /**
    * @brief A 2D vector class.
    */

    class Vector2 {
    private:
        float x, y;

    public:
        // Constructors
        Vector2() : x(0), y(0) {};
        Vector2(float x, float y) : x(x), y(y) {};

        // Getters and Setters
        float getX() const { return x; }
        float getY() const { return y; }
        void setX(float new_x) { x = new_x; }
        void setY(float new_y) { y = new_y; }

        // Operators
        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2& operator*=(float scalar);
        Vector2& operator/=(float scalar);
        Vector2 operator-() const;

        float length() const;
        float lengthSquared() const;
        void normalize();

        // Static methods
        static float distance(const Vector2& v1, const Vector2& v2);
        static float dot(const Vector2& v1, const Vector2& v2);
        static float cross(const Vector2& v1, const Vector2& v2);

        // Utilities
        std::string toString() const;
        void print() const;
    }; // Vector2

    // Non-member operators
    Vector2 operator+(const Vector2& v1, const Vector2& v2);
    Vector2 operator-(const Vector2& v1, const Vector2& v2);
    Vector2 operator*(const Vector2& v, float scalar);
    Vector2 operator*(float scalar, const Vector2& v);
    Vector2 operator/(const Vector2& v, float scalar);
}

#endif //NEWTON_ENGINE_Vector2_HPP
