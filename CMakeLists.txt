cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(aoc2023 VERSION 0.1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

option(UNIT_TESTS ON)

# Finding System Deps

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -Wextra -Werror=deprecated-declarations -fdiagnostics-color=always")
if (CMAKE_BUILD_TYPE EQUAL Debug)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_DEBUG} -0g")
endif()
if (CMAKE_BUILD_TYPE EQUAL Release)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wpedantic -O3")
endif()

# for use with clang tidy and clang format
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(CLANG_TIDY NAMES "clang-tidy")
set(CLANG_TIDY_COMMAND "${CLANG_TIDY}" "--config-file=${PROJECT_SOURCE_DIR}/.clang-tidy")

find_program(CLANG_FORMAT NAMES "clang-format")
set(CLANG_FORMAT_COMMAND "${CLANG_FORMAT}") # default is `--style=file`, where it looks for `.clang-format` in parent dir

add_subdirectory(src)
if (UNIT_TESTS)
    add_subdirectory(test)
endif()

message("")
message("========================")
message("CONFIG")
message("========================")
message("CMAKE_SYSTEM_NAME:       ${CMAKE_SYSTEM_NAME}")
message("CMAKE_SYSTEM_VERSION:    ${CMAKE_SYSTEM_VERSION}")
message("CMAKE_BINARY_DIR:        ${CMAKE_BINARY_DIR}")
message("CMAKE_INSTALL_PREFIX:    ${CMAKE_INSTALL_PREFIX}")
message("CMAKE_SYSTEM_PROCESSOR:  ${CMAKE_SYSTEM_PROCESSOR}")
message("CMAKE_C_COMPILER:        ${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER:      ${CMAKE_CXX_COMPILER}")
message("CMAKE_BUILD_TYPE:        ${CMAKE_BUILD_TYPE}")
message("CMAKE_INSTALL_BINDIR:    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("CMAKE_INSTALL_LIBDIR:    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("CMAKE_INSTALL_ARCHIVE::  ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("TESTING ENABLED:		  ${UNIT_TESTS}")
message("")
 
