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
     * @brief Adds two vectors, and places the result into another vector.
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

    /**
     * @brief Adds a vector to another vector.
     *
     * @param a The vector being added to.
     * @param b The other vector.
     */
    void add(Vector& a, const Vector& b) {
        a.x += b.x;
        a.y += b.y;
        a.z += b.z;
    };

    /**
     * @brief Subtracts two vectors, and places the result into another vector.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @param out The output vector.
     */
    void subtract(const Vector& a, const Vector& b, Vector& out) {
        out.x = a.x - b.x;
        out.y = a.y - b.y;
        out.z = a.z - b.z;
    };

    /**
     * @brief Subtracts a vector from another vector.
     *
     * @param a The vector being subtraced from.
     * @param b The other vector.
     */
    void subtract(Vector& a, const Vector& b) {
        a.x -= b.x;
        a.y -= b.y;
        a.z -= b.z;
    };

    /**
     * @brief Multiplies a vector and a scalar, and places the result into another vector.
     *
     * @param a The vector being multiplied.
     * @param k The scalar.
     * @param out The output vector.
     */
    void multiply(const Vector& a, float k, Vector& out) {
        out.x = a.x * k;
        out.y = a.y * k;
        out.z = a.z * k;
    };

    /**
     * @brief Multiplies a vector by a scalar.
     *
     * @param a The vector being multiplied.
     * @param k The scalar.
     */
    void multiply(Vector& a, float k) {
        a.x *= k;
        a.y *= k;
        a.z *= k;
    };

    /**
     * @brief Determines whether two vectors are parallel.
     *
     * @param a The first vector.
     * @param b The second vector.
     *
     * @return true The vectors are parallel.
     * @return false The vectors are not parallel.
     */
    bool isParallel(const Vector& a, const Vector& b) {
        float dot = dotProduct(a, b);
        float product = length(a) * length(b);
        return _floatClose(dot, product);
    };

    /**
     * @brief Calculates the cross product of two vectors, and places the result into another vector.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @param out The output vector.
     */
    void crossProduct(const Vector& a, const Vector& b, Vector& out) {
        out.x = (a.y * b.z) - (a.z * b.y);
        out.y = (a.z * b.x) - (a.x * b.z);
        out.z = (a.x * b.y) - (a.y * b.x);
    };

    /**
     * @brief Calculates the cross product of a vector onto another vector.
     *
     * @param a The first vector.
     * @param b The second vector.
     */
    void crossProduct(Vector& a, const Vector& b) {
        float tempX = a.x;
        float tempY = a.y;
        float tempZ = a.z;

        a.x = (tempY * b.z) - (tempZ * b.y);
        a.y = (tempZ * b.x) - (tempX * b.z);
        a.z = (tempX * b.y) - (tempY * b.x);
    };

    /**
     * @brief Calculates a vector rotated about the x-axis, and places the result into another vector.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     * @param out The output vector.
     */
    void rotateX(const Vector& a, float theta, Vector& out) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        out.x = a.x;
        out.y = a.y * cos - a.z * sin;
        out.z = a.y * sin + a.z * cos;
    };

    /**
     * @brief Rotates a vector about the x-axis.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     */
    void rotateX(Vector& a, float theta) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);
        float tempY, tempZ;
        tempY = a.y;
        tempZ = a.z;

        a.y = tempY * cos - tempZ * sin;
        a.z = tempY * sin + tempZ * cos;
    };

    /**
     * @brief Calculates a vector rotated about the y-axis, and places the result into another vector.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     * @param out The output vector.
     */
    void rotateY(const Vector& a, float theta, Vector& out) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        out.x = a.x * cos + a.z * sin;
        out.y = a.y;
        out.z = -a.x * sin + a.z * cos;
    };

    /**
     * @brief Rotates a vector about the y-axis.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     */
    void rotateY(Vector& a, float theta) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        float tempX, tempZ;
        tempX = a.x;
        tempZ = a.z;

        a.x = tempX * cos + tempZ * sin;
        a.z = -tempX * sin + tempZ * cos;
    };

    /**
     * @brief Calculates a vector rotated about the z-axis, and places the result into another vector.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     * @param out The output vector.
     */
    void rotateZ(const Vector& a, float theta, Vector& out) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        out.x = a.x * cos - a.y * sin;
        out.y = a.x * sin + a.y * cos;
        out.z = a.z;
    };

    /**
     * @brief Rotates a vector about the z-axis.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     */
    void rotateZ(Vector& a, float theta) {
        float sin = sinf(theta * M_PI / 180);
        float cos = cosf(theta * M_PI / 180);

        float tempX, tempY;
        tempX = a.x;
        tempY = a.y;

        a.x = tempX * cos - tempY * sin;
        a.y = tempX * sin + tempY * cos;
    };

    /**
     * @brief Calculates the length squared of a vector.
     *
     * @param a The vector.
     * @return float The length squared of the vector.
     */
    float lengthSquared(const Vector& a) {
        return (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
    }

    /**
     * @brief Calculates the length of a vector.
     *
     * @param a The vector.
     * @return float The length of the vector.
     */
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