set(AOC2023_DAY1_TEST_SOURCES
    day1_test.c)

add_executable(aoc2023_day1_test ${AOC2023_DAY1_TEST_SOURCES} ${PROJECT_SOURCE_DIR}/src/day01.c ${PROJECT_SOURCE_DIR}/src/day01.h)
target_include_directories(aoc2023_day1_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src)

target_link_directories(aoc2023_day1_test PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(aoc2023_day1_test PRIVATE aoc2023_shared criterion)

add_custom_target(test COMMAND aoc2023_day1_test)
