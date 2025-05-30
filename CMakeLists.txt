cmake_minimum_required(VERSION 3.10)
project(alpha)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

option(BUILD_TESTS "Build test suite" ON)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)
list(FILTER SRC_FILES EXCLUDE REGEX ".*/main\\.cpp$")


if(BUILD_TESTS)
    enable_testing()

    file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/tests/vector/vector.cpp"
    )

    add_executable(runTests
        "${CMAKE_CURRENT_SOURCE_DIR}/tests/catch_amalgamated.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/tests/catch_amalgamated.cpp"
        ${TEST_FILES}
        ${SRC_FILES}
    )

    target_include_directories(runTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/tests
    )

    add_test(NAME AllTests COMMAND runTests)

    set_target_properties(runTests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif()

add_executable(alpha ${SRC_FILES} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_libraries(alpha PRIVATE SDL2)

set_target_properties(alpha PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/temp)
