set(AOC2023_SOURCES
    # sources
    main.c
	day01.c

    # headers
    day01.h
)

add_executable(${PROJECT_NAME} ${AOC2023_SOURCES})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_library(${PROJECT_NAME}_shared SHARED day01.c day01.h)
install(TARGETS ${PROJECT_NAME}_shared LIBRARY DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Prepend the full path to each source file
# Create custom target for running clang tidy
list(TRANSFORM AOC2023_SOURCES PREPEND ${CMAKE_SOURCE_DIR}/src/)

set(CLANG_TIDY_OPTIONS ${CLANG_TIDY_OPTIONS}
    -extra-arg=-Wno-unknown-warning-option
    -extra-arg=-Wno-ignored-optimization-argument
    -extra-arg=-Wno-unused-command-line-argument
    -warning-as-errors=*)

if("${CLANG_TIDY_OPTIONS_DRIVER_MODE}" STREQUAL "cl")
    set(CLANG_TIDY_OPTIONS ${CLANG_TIDY_OPTIONS} -extra-arg=/std:c++${CMAKE_CXX_STANDARD})
else()
    set(CLANG_TIDY_OPTIONS ${CLANG_TIDY_OPTIONS} -extra-arg=-std=c++${CMAKE_CXX_STANDARD})
endif()

add_custom_target(tidy
    COMMAND clang-tidy -p ${CMAKE_BINARY_DIR} --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy --use-color ${WAVESCAPE_SOURCES}
    COMMENT "Running tidy checks"
    VERBATIM)

add_custom_target(format
    COMMAND clang-format --Werror --sort-includes --verbose ${WAVESCAPE_SOURCES}
    COMMENT "Running formatting checks"
    VERBATIM)
