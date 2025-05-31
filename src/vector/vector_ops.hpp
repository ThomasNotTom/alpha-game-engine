#include "./vector.hpp"

namespace VectorOps {
    /**
     * @brief A small threshold value.
     */
    const float EPSILON = 0.0001;

    /**
     * @brief Checks whether two floats are within a small amount of each other.
     *
     * @param a The first float.
     * @param b The second float.
     * @return true The floats are close.
     * @return false The floats are not close.
     */
    bool _floatClose(float a, float b);

    /**
     * @brief Calculates the dot product of two vectors.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return float The dot product.
     */
    float dotProduct(const Vector& a, const Vector& b);

    /**
     * @brief Adds two vectors, and places the result into another vector.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @param out The output vector.
     */
    void add(const Vector& a, const Vector& b, Vector& out);

    /**
     * @brief Adds a vector to another vector.
     *
     * @param a The vector being added to.
     * @param b The other vector.
     */
    void add(Vector& a, const Vector& b);

    /**
     * @brief Subtracts two vectors, and places the result into another vector.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @param out The output vector.
     */
    void subtract(const Vector& a, const Vector& b, Vector& out);

    /**
     * @brief Subtracts a vector from another vector.
     *
     * @param a The vector being subtraced from.
     * @param b The other vector.
     */
    void subtract(Vector& a, const Vector& b);

    /**
     * @brief Multiplies a vector and a scalar, and places the result into another vector.
     *
     * @param a The vector being multiplied.
     * @param k The scalar.
     * @param out The output vector.
     */
    void multiply(const Vector& a, float k, Vector& out);

    /**
     * @brief Multiplies a vector by a scalar.
     *
     * @param a The vector being multiplied.
     * @param k The scalar.
     */
    void multiply(Vector& a, float k);

    /**
     * @brief Determines whether two vectors are parallel.
     *
     * @param a The first vector.
     * @param b The second vector.
     *
     * @return true The vectors are parallel.
     * @return false The vectors are not parallel.
     */
    bool isParallel(const Vector& a, const Vector& b);

    /**
     * @brief Calculates the cross product of two vectors, and places the result into another vector.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @param out The output vector.
     */
    void crossProduct(const Vector& a, const Vector& b, Vector& out);

    /**
     * @brief Calculates the cross product of a vector onto another vector.
     *
     * @param a The first vector.
     * @param b The second vector.
     */
    void crossProduct(Vector& a, const Vector& b);

    /**
     * @brief Calculates a vector rotated about the x-axis, and places the result into another vector.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     * @param out The output vector.
     */
    void rotateX(const Vector& a, float theta, Vector& out);

    /**
     * @brief Rotates a vector about the x-axis.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     */
    void rotateX(Vector& a, float theta);

    /**
     * @brief Calculates a vector rotated about the y-axis, and places the result into another vector.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     * @param out The output vector.
     */
    void rotateY(const Vector& a, float theta, Vector& out);

    /**
     * @brief Rotates a vector about the y-axis.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     */
    void rotateY(Vector& a, float theta);

    /**
     * @brief Calculates a vector rotated about the z-axis, and places the result into another vector.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     * @param out The output vector.
     */
    void rotateZ(const Vector& a, float theta, Vector& out);

    /**
     * @brief Rotates a vector about the z-axis.
     *
     * @param a The vector to be rotated.
     * @param theta The angle (degrees) to rotate.
     */
    void rotateZ(Vector& a, float theta);

    /**
     * @brief Calculates the length squared of a vector.
     *
     * @param a The vector.
     * @return float The length squared of the vector.
     */
    float lengthSquared(const Vector& a);

    /**
     * @brief Calculates the length of a vector.
     *
     * @param a The vector.
     * @return float The length of the vector.
     */
    float length(const Vector& a);

    /**
     * @brief Calculate the normal of a vector, and places the result into another vector.
     *
     * @param a The vector.
     * @param out The output vector.
     */
    void normalise(const Vector& a, Vector& out);

    /**
     * @brief Normalise a vector.
     *
     * @param a The vector.
     */
    void normalise(Vector& a);

    /**
     * @brief Determines whether two vectors are equal.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return true The vectors are equal.
     * @return false The vectors are not equal.
     */
    bool equals(const Vector& a, const Vector& b);

    /**
     * @brief Determines whether two vectors are nearly the same.
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return true The vectors are close.
     * @return false The vectors are not close.
     */
    bool isClose(const Vector& a, const Vector& b);
};