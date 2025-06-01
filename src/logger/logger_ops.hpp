#pragma once

#include <string>

#include "./logger.hpp"

namespace Logger {
    /**
     * @brief Private method for translating text with a coloured prefix to a printable string and passing it
     * to the private print method.
     *
     * @param colour The colour of the prefix.
     * @param prefix The prefix text.
     * @param text The text to print.
     */
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

    /**
     * @brief Logs a message with the LOG prefix.
     *
     * @param message The message to log.
     */
    void log(std::string message);

    /**
     * @brief Logs a message with the WARNING prefix.
     *
     * @param message The message to log.
     */
    void warning(std::string message);

    /**
     * @brief Logs a message with the ERROR prefix.
     *
     * @param message The message to log.
     */
    void error(std::string message);

    /**
     * @brief Logs a message with the SUCCESS prefix.
     *
     * @param message The message to log.
     */
    void success(std::string message);
};