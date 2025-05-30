#include "./vector_ops.hpp"

namespace VectorOps {
    float dotProduct(const Vector& a, const Vector& b) {
        return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    };

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
};