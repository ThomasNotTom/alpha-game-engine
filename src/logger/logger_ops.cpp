#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <filesystem>

#include "./logger_ops.hpp"
#include "./logger.hpp"

namespace Logger {
    void _prettyPrint(const char* colour, std::string prefix, std::string text) {
        auto now = std::chrono::system_clock::now();
        std::time_t nowTime = std::chrono::system_clock::to_time_t(now);

        std::ostringstream oss;
        oss << "[";
        if (mode == Mode::TERMINAL) {
            oss << colour << Colours::BOLD;
        }
        oss << prefix;
        if (mode == Mode::TERMINAL) {
            oss << Colours::RESET;
        }
        oss << "] (" << std::put_time(std::localtime(&nowTime), "%H:%M:%S") << "): ";
        if (mode == Mode::TERMINAL) {
            oss << colour;
        }
        oss << text;
        if (mode == Logger::TERMINAL) {
            oss << Colours::RESET;
        }

        Logger::_print(oss.str());
    };

    void _print(std::string text) {
        switch (mode) {
        case Mode::TERMINAL:
            _printToTerminal(text);
            break;

        case Mode::FILE:
            _printToFile(text);
            break;
        }
    }

    void _printToTerminal(std::string text) {
        std::cout << text << std::endl;
    }

    void _printToFile(std::string text) {
        outputFile << text << '\n';
    }

    void _init(Mode m) {
        mode = m;

        if (mode == Mode::TERMINAL) {
            return;
        }

        std::filesystem::create_directories("../logs");
        auto now = std::chrono::system_clock::now();
        std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
        std::ostringstream name;
        name << std::put_time(std::localtime(&nowTime), "%Y-%m-%d_%H:%M:%S");
        outputFile.open("../logs/" + name.str() + ".txt", std::ios::app);
    }

    void init(Mode m) {
        if (initialised) {
            return;
        }

        _init(m);

        initialised = true;
    }

    void log(std::string text) {
        _prettyPrint(Colours::RESET, "LOG", text);
    }

    void warning(std::string text) {
        _prettyPrint(Colours::YELLOW, "WARNING", text);
    }

    void error(std::string text) {
        _prettyPrint(Colours::RED, "ERROR", text);
    }

    void success(std::string text) {
        _prettyPrint(Colours::GREEN, "SUCCESS", text);
    }
};