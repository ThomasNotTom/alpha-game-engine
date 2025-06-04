#include "../catch_amalgamated.hpp"

#include "../../src/logger/logger_ops.hpp"

#include "../../src/orientation/orientation_ops.hpp"
#include "../../src/vector/vector_ops.hpp"

// Testing OrientationOps::getUnitVector
TEST_CASE("Orientation get unit vector equals works", "[orientation_get_unit_vec, in_place]") {
    const float HALF = 1.0f / 2.0f;
    const float ONE_OVER_SQRT_TWO = 1.0f / sqrtf(2.0f);
    const int DIAGONAL_ANGLE = 45;

    const Orientation orientation = {DIAGONAL_ANGLE, DIAGONAL_ANGLE};
    Vector unitVector;
    OrientationOps::getUnitVector(orientation, unitVector);
    REQUIRE(VectorOps::isClose(unitVector, {HALF, ONE_OVER_SQRT_TWO, HALF}));
}