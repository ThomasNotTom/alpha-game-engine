#include "./vector_ops.hpp"

namespace VectorOps {
    float dotProduct(const Vector& a, const Vector& b) {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }

    void add(const Vector& a, const Vector& b, Vector& out) {
        out.x = a.x + b.x;
        out.y = a.y + b.y;
        out.z = a.z + b.z;
    }

    void add(Vector& a, const Vector& b) {
        a.x += b.x;
        a.y += b.y;
        a.z += b.z;
    };
}