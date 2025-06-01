#include <string>

#include "./logger.hpp"

namespace Logger {
    static Mode mode = Mode::TERMINAL;

    void log(std::string message);
    void warning(std::string message);
    void error(std::string message);
    void success(std::string message);
};