#pragma once

#include "../vector/vector.hpp"
#include "./orientation.hpp"

namespace OrientationOps {
    void getUnitVector(const Orientation& orientation, Vector& out);
};