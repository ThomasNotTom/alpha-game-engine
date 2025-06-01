#include <cstdint>

namespace Logger {
    enum Mode : uint8_t {
        TERMINAL,
        FILE
    };

    namespace Colors {
        constexpr const char* RED = "\033[31m";
        constexpr const char* GREEN = "\033[32m";
        constexpr const char* YELLOW = "\033[33m";
        constexpr const char* RESET = "\033[0m";
        constexpr const char* BOLD = "\033[1m";
    };
};