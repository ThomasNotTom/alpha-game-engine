#include "./vector.hpp"

namespace VectorOps {
    float dotProduct(const Vector& a, const Vector& b);

    void add(const Vector& a, const Vector& b, Vector& out);
    void add(Vector& a, const Vector& b);

    void multiply(const Vector& a, float k, Vector& out);
    void multiply(Vector& a, float k);
}