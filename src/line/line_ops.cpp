#include "./line_ops.hpp"
#include "../vector/vector_ops.hpp"

namespace LineOps {
    void getFinish(const Line& line, Vector& out) {
        VectorOps::add(line.base, line.extension, out);
    };
};