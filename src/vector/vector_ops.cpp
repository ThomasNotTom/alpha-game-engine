#include <cmath>

#include "./vector_ops.hpp"

namespace VectorOps {
    /**
     * @brief Checks whether two floats are within a small amount of each other.
     *
     * @param a The first float.
     * @param b The second float.
     * @return true The floats are close.
     * @return false The floats are not close.
     */
    bool _floatClose(float a, float b) {
        float diff = std::abs(a - b);
        return diff <= EPSILON;
    }

    /**
     * @brief Calculates the dot product of two vectors.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return float The dot product.
     */
    float dotProduct(const Vector& a, const Vector& b) {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    };

    /**
     * @brief Adds two vectors, and places it into another vector.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @param out The output vector.
     */
    void add(const Vector& a, const Vector& b, Vector& out) {
        out.x = a.x + b.x;
        out.y = a.y + b.y;
        out.z = a.z + b.z;
    };

    void add(Vector& a, const Vector& b) {
        a.x += b.x;
        a.y += b.y;
        a.z += b.z;
    };

    void subtract(const Vector& a, const Vector& b, Vector& out) {
        out.x = a.x - b.x;
        out.y = a.y - b.y;
        out.z = a.z - b.z;
    };

    void subtract(Vector& a, const Vector& b) {
        a.x -= b.x;
        a.y -= b.y;
        a.z -= b.z;
    };

    void multiply(const Vector& a, float k, Vector& out) {
        out.x = a.x * k;
        out.y = a.y * k;
        out.z = a.z * k;
    };

    void multiply(Vector& a, float k) {
        a.x *= k;
        a.y *= k;
        a.z *= k;
    };

    float isParallel(const Vector& a, const Vector& b) {
        float dot = dotProduct(a, b);
        float product = length(a) * length(b);
        return _floatClose(dot, product);
    };

    void crossProduct(const Vector& a, const Vector& b, Vector& out) {
        out.x = (a.y * b.z) - (a.z * b.y);
        out.y = (a.z * b.x) - (a.x * b.z);
        out.z = (a.x * b.y) - (a.y * b.x);
    };

    void crossProduct(Vector& a, const Vector& b) {
        float tempX = a.x;
        float tempY = a.y;
        float tempZ = a.z;

        a.x = (tempY * b.z) - (tempZ * b.y);
        a.y = (tempZ * b.x) - (tempX * b.z);
        a.z = (tempX * b.y) - (tempY * b.x);
    };

    void rotateX(const Vector& a, float theta, Vector& out) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        out.x = a.x;
        out.y = a.y * cos - a.z * sin;
        out.z = a.y * sin + a.z * cos;
    };

    void rotateX(Vector& a, float theta) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);
        float tempY, tempZ;
        tempY = a.y;
        tempZ = a.z;

        a.y = tempY * cos - tempZ * sin;
        a.z = tempY * sin + tempZ * cos;
    };

    void rotateY(const Vector& a, float theta, Vector& out) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        out.x = a.x * cos + a.z * sin;
        out.y = a.y;
        out.z = -a.x * sin + a.z * cos;
    };

    void rotateY(Vector& a, float theta) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        float tempX, tempZ;
        tempX = a.x;
        tempZ = a.z;

        a.x = tempX * cos + tempZ * sin;
        a.z = -tempX * sin + tempZ * cos;
    };

    void rotateZ(const Vector& a, float theta, Vector& out) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        out.x = a.x * cos - a.y * sin;
        out.y = a.x * sin + a.y * cos;
        out.z = a.z;
    };

    void rotateZ(Vector& a, float theta) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        float tempX, tempY;
        tempX = a.x;
        tempY = a.y;

        a.x = tempX * cos - tempY * sin;
        a.y = tempX * sin + tempY * cos;
    };

    float lengthSquared(const Vector& a) {
        return (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
    }

    float length(const Vector& a) {
        return sqrtf(lengthSquared(a));
    };

    void normalise(const Vector& a, Vector& out) {
        multiply(a, 1 / length(a), out);
    };

    void normalise(Vector& a) {
        multiply(a, 1 / length(a), a);
    };

    bool equals(const Vector& a, const Vector& b) {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }

    bool isClose(const Vector& a, const Vector& b) {
        return _floatClose(a.x, b.x) &&
               _floatClose(a.y, b.y) &&
               _floatClose(a.z, b.z);
    }
};