#pragma once

#include <string>

#include "./logger.hpp"

namespace Logger {
    void _prettyPrint(const char* colour, std::string prefix, std::string text);
    void _print(std::string text);
    void _printToTerminal(std::string text);
    void _printToFile(std::string text);

    /**
     * @brief Initialisation method that creates a folder and file if mode is set to Mode::FILE mode.
     *
     * @param mode The mode the logger will be set to.
     */
    void init(Mode mode);

    void log(std::string message);
    void warning(std::string message);
    void error(std::string message);
    void success(std::string message);
};