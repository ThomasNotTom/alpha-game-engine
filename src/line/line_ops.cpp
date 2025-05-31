#include "./line_ops.hpp"
#include "../vector/vector_ops.hpp"

namespace LineOps {
    bool equals(const Line& a, const Line& b) {
        return VectorOps::equals(a.base, b.base) && VectorOps::equals(a.extension, b.extension);
    }

    void getFinish(const Line& line, Vector& out) {
        VectorOps::add(line.base, line.extension, out);
    };
};