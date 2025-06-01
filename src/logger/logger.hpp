#include <cstdint>

namespace Logger {
    enum Mode : uint8_t {
        TERMINAL,
        FILE
    };

    static Mode mode = Mode::TERMINAL;
};