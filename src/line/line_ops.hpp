#pragma once

#include "./line.hpp"

namespace LineOps {
    /**
     * @brief Get the finish vector of the line.
     *
     * @param line The line.
     * @param out The output vector.
     */
    void getFinish(const Line& line, Vector& out);
};