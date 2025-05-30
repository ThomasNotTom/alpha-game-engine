#include "../catch_amalgamated.hpp"

#include "../../src/vector/vector.hpp"
#include "../../src/vector/vector_ops.hpp"

// Testing VectorOps::equals
TEST_CASE("Vector equals works", "[vector_eq]") {
    const Vector v1 = {1, 1, 1};
    const Vector v2 = {1, 1, 1};
    REQUIRE(VectorOps::equals(v1, v2));
}