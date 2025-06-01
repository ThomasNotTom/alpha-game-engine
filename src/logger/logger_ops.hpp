#pragma once

#include <string>

#include "./logger.hpp"

namespace Logger {
    void _prettyPrint(const char* colour, std::string prefix, std::string text);
    void _print(std::string text);
    void _printToTerminal(std::string text);
    void _printToFile(std::string text);

    void log(std::string message);
    void warning(std::string message);
    void error(std::string message);
    void success(std::string message);
};