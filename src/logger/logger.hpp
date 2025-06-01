#include <cstdint>

namespace Logger {
    enum Mode : uint8_t {
        TERMINAL,
        FILE
    };

    enum Level : uint8_t {
        LOG,
        WARNING,
        ERROR,
        SUCCESS
    };

    static Mode mode = Mode::TERMINAL;
};