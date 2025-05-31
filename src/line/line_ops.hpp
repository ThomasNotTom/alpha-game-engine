#pragma once

#include "./line.hpp"

namespace LineOps {
    /**
     * @brief Determines whether two lines are the same.
     *
     * @param a The first line.
     * @param b The second line.
     * @return true The lines are the same.
     * @return false The lines are not the same.
     */
    bool equals(const Line& a, const Line& b);

    /**
     * @brief Determines whether two lines are close.
     *
     * @param a The first line.
     * @param b The second line.
     * @return true The lines are close.
     * @return false The lines are not close.
     */
    bool isClose(const Line& a, const Line& b);

    /**
     * @brief Get the finish vector of the line.
     *
     * @param line The line.
     * @param out The output vector.
     */
    void getFinish(const Line& line, Vector& out);
};