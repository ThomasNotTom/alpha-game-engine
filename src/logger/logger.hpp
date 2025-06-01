#include <cstdint>
#include <string>

namespace Logger {
    enum Mode : uint8_t {
        TERMINAL,
        FILE
    };

    static Mode mode = Mode::TERMINAL;

    void log(std::string message);
    void warning(std::string message);
    void error(std::string message);
    void success(std::string message);
};