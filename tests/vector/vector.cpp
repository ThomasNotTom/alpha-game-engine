#include "../catch_amalgamated.hpp"

#include "../../src/vector/vector.hpp"
#include "../../src/vector/vector_ops.hpp"

TEST_CASE("Vector addition works (in-place)", "[vector_add, in_place]") {
    Vector v1 = {1, 1, 1};
    const Vector v2 = {2, 2, 2};
    VectorOps::add(v1, v2);
    REQUIRE(VectorOps::equals(v1, {3, 3, 3}));
}

TEST_CASE("Vector addition works (out-of-place)", "[vector_add, out_of_place]") {
    const Vector v1 = {1, 1, 1};
    const Vector v2 = {2, 2, 2};
    Vector v3;
    VectorOps::add(v1, v2, v3);
    REQUIRE(VectorOps::equals(v3, {3, 3, 3}));
}