#include "../catch_amalgamated.hpp"

#include "../../src/logger/logger_ops.hpp"

#include "../../src/orientation/orientation_ops.hpp"
#include "../../src/vector/vector_ops.hpp"

// Testing OrientationOps::getUnitVector
TEST_CASE("Orientation get unit vector equals works", "[orientation_get_unit_vec, in_place]") {
    const Orientation orientation = {45, 45};
    Vector unitVector;
    OrientationOps::getUnitVector(orientation, unitVector);
    REQUIRE(VectorOps::isClose(unitVector, {0.5f, 0.70710678118f, 0.5f}));
}