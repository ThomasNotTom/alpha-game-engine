#include "./vector.hpp"

namespace VectorOps {
    const float EPSILON = 0.0001;

    bool _floatClose(float a, float b);

    float dotProduct(const Vector& a, const Vector& b);

    void add(const Vector& a, const Vector& b, Vector& out);
    void add(Vector& a, const Vector& b);

    void subtract(const Vector& a, const Vector& b, Vector& out);
    void subtract(Vector& a, const Vector& b);

    void multiply(const Vector& a, float k, Vector& out);
    void multiply(Vector& a, float k);

    float isParallel(const Vector& a, const Vector& b);

    void crossProduct(const Vector& a, const Vector& b, Vector& out);
    void crossProduct(Vector& a, const Vector& b);

    void rotateX(const Vector& a, float theta, Vector& out);
    void rotateX(Vector& a, float theta);

    void rotateY(const Vector& a, float theta, Vector& out);
    void rotateY(Vector& a, float theta);

    void rotateZ(const Vector& a, float theta, Vector& out);
    void rotateZ(Vector& a, float theta);

    float lengthSquared(const Vector& a);
    float length(const Vector& a);

    void normalise(const Vector& a, Vector& out);
    void normalise(Vector& a);

    bool equals(const Vector& a, const Vector& b);
    bool isClose(const Vector& a, const Vector& b);
};