#include "../catch_amalgamated.hpp"

#include "../../src/line/line.hpp"
#include "../../src/line/line_ops.hpp"

#include "../../src/vector/vector_ops.hpp"

// Testing LineOps::getFinish
TEST_CASE("Line get finish works", "[line_get_finish]") {
    const Line l1 = {{1, 1, 1}, {2, 2, 2}};
    Vector finish;
    LineOps::getFinish(l1, finish);
    REQUIRE(VectorOps::equals(finish, {3, 3, 3}));
}