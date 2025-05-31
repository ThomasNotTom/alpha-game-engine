#include "../catch_amalgamated.hpp"

#include "../../src/line/line.hpp"
#include "../../src/line/line_ops.hpp"

#include "../../src/vector/vector_ops.hpp"

// Testing LineOps::equals
TEST_CASE("Line equals works", "[line_eq]") {
    const Line l1 = {{1, 1, 1}, {2, 2, 2}};
    const Line l2 = {{1, 1, 1}, {2, 2, 2}};
    REQUIRE(LineOps::equals(l1, l2));
}

// Testing LineOps::getFinish
TEST_CASE("Line get finish works", "[line_get_finish]") {
    const Line l1 = {{1, 1, 1}, {2, 2, 2}};
    Vector finish;
    LineOps::getFinish(l1, finish);
    REQUIRE(VectorOps::equals(finish, {3, 3, 3}));
}