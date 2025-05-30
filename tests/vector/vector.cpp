#include "../catch_amalgamated.hpp"

#include "../../src/vector/vector.hpp"
#include "../../src/vector/vector_ops.hpp"

// Testing VectorOps::equals
TEST_CASE("Vector equals works", "[vector_eq]") {
    const Vector v1 = {1, 1, 1};
    const Vector v2 = {1, 1, 1};
    REQUIRE(VectorOps::equals(v1, v2));
}

// Testing VectorOps::isClose
TEST_CASE("Vector closeness works (in-place)", "[vector_sub, in_place]") {
    Vector v1 = {1, 1, 1};
    const Vector v2 = {1 + (VectorOps::EPSILON / 10), 1 + (VectorOps::EPSILON / 10), 1 + (VectorOps::EPSILON / 10)};
    REQUIRE(VectorOps::isClose(v1, v2));
}

// Testing VectorOps::add
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

// Testing VectorOps::subtract
TEST_CASE("Vector subtraction works (in-place)", "[vector_sub, in_place]") {
    Vector v1 = {3, 3, 3};
    const Vector v2 = {2, 2, 2};
    VectorOps::subtract(v1, v2);
    REQUIRE(VectorOps::equals(v1, {1, 1, 1}));
}

TEST_CASE("Vector subtraction works (out-of-place)", "[vector_sub, out_of_place]") {
    const Vector v1 = {3, 3, 3};
    const Vector v2 = {2, 2, 2};
    Vector v3;
    VectorOps::subtract(v1, v2, v3);
    REQUIRE(VectorOps::equals(v3, {1, 1, 1}));
}

// Testing VectorOps::lengthSquared
TEST_CASE("Vector length squared works (in-place)", "[vector_length_sqrd]") {
    const Vector v1 = {2, 3, 6};
    REQUIRE(VectorOps::lengthSquared(v1) == 49);
}