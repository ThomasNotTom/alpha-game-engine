#include <cmath>

#include "./orientation_ops.hpp"

namespace OrientationOps {
    void getUnitVector(const Orientation& orientation, Vector& out) {
        float yawRad = orientation.yaw * M_PI / 180.0f;
        float pitchRad = orientation.pitch * M_PI / 180.0f;

        float sinPitch, cosPitch;
        float sinYaw, cosYaw;
        sinPitch = sin(pitchRad);
        cosPitch = cos(pitchRad);

        sinYaw = sin(yawRad);
        cosYaw = cos(yawRad);

        out.x = cosPitch * cosYaw;
        out.y = sinPitch;
        out.z = cosPitch * sinYaw;
    };
};