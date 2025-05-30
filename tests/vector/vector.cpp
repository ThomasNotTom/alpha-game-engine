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
TEST_CASE("Vector length squared works", "[vector_length_sqrd]") {
    const Vector v1 = {2, 3, 6};
    REQUIRE(VectorOps::lengthSquared(v1) == 49);
}

// Testing VectorOps::length
TEST_CASE("Vector length works", "[vector_length]") {
    const Vector v1 = {2, 3, 6};
    REQUIRE(VectorOps::length(v1) == 7);
}

// Testing VectorOps::dotProduct
TEST_CASE("Vector dot product works", "[vector_dot]") {
    const Vector v1 = {1, 1, 1};
    const Vector v2 = {1, 1, 1};
    REQUIRE(VectorOps::dotProduct(v1, v2) == 3);
}

// Testing VectorOps::rotateX
TEST_CASE("Vector rotate x works (in-place)", "[vector_rot_x, in_place]") {
    Vector v1 = {0, 1, 0};
    VectorOps::rotateX(v1, 90);
    REQUIRE(VectorOps::isClose(v1, {0, 0, 1}));
}

TEST_CASE("Vector rotate x works (out-of-place)", "[vector_rot_x, out_of_place]") {
    const Vector v1 = {0, 1, 0};
    Vector rotated;
    VectorOps::rotateX(v1, 90, rotated);
    REQUIRE(VectorOps::isClose(rotated, {0, 0, 1}));
}

// Testing VectorOps::rotateY
TEST_CASE("Vector rotate y works (in-place)", "[vector_rot_y, in_place]") {
    Vector v1 = {0, 0, 1};
    VectorOps::rotateY(v1, 90);
    REQUIRE(VectorOps::isClose(v1, {1, 0, 0}));
}

TEST_CASE("Vector rotate y works (out-of-place)", "[vector_rot_y, out_of_place]") {
    const Vector v1 = {0, 0, 1};
    Vector rotated;
    VectorOps::rotateY(v1, 90, rotated);
    REQUIRE(VectorOps::isClose(rotated, {1, 0, 0}));
}

// Testing VectorOps::rotateZ
TEST_CASE("Vector rotate z works (in-place)", "[vector_rot_z, in_place]") {
    Vector v1 = {1, 0, 0};
    VectorOps::rotateZ(v1, 90);
    REQUIRE(VectorOps::isClose(v1, {0, 1, 0}));
}

TEST_CASE("Vector rotate z works (out-of-place)", "[vector_rot_z, out_of_place]") {
    const Vector v1 = {1, 0, 0};
    Vector rotated;
    VectorOps::rotateZ(v1, 90, rotated);
    REQUIRE(VectorOps::isClose(rotated, {0, 1, 0}));
}

// Testing VectorOps::isParallel
TEST_CASE("Vector parallel check works", "[vector_is_parallel]") {
    Vector v1 = {1, 1, 1};
    Vector v2 = {2, 2, 2};
    REQUIRE(VectorOps::isParallel(v1, v2));
}

// Testing VectorOps::normalise
TEST_CASE("Vector normalise works (in-place)", "[vector_normalise, in_place]") {
    Vector v1 = {1, 1, 1};
    Vector parallel = {2, 2, 2};
    VectorOps::normalise(v1);
    REQUIRE(VectorOps::isParallel(v1, parallel) && VectorOps::length(v1) == 1);
}

TEST_CASE("Vector normalise works (out-of-place)", "[vector_normalise, out_of_place]") {
    Vector v1 = {1, 1, 1};
    Vector normalised;
    VectorOps::normalise(v1, normalised);
    REQUIRE(VectorOps::isParallel(v1, normalised) && VectorOps::length(normalised) == 1);
}