#pragma once

#include "../vector/vector.hpp"
#include "../orientation/orientation.hpp"

struct Camera {
    Vector position;
    Orientation orientation;
    float fieldOfView;
};