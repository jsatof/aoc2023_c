set(WAVESCAPE_TEST_SOURCES
    test.cpp)

add_executable(wavescape_test ${WAVESCAPE_TEST_SOURCES})
target_include_directories(wavescape_test PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/microui/src
    ${PROJECT_SOURCE_DIR}/miniaudio)

target_link_directories(wavescape_test PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(wavescape_test PRIVATE wavescape_shared fmt::fmt boost_unit_test_framework) # boost isnt properly checked on system

add_custom_target(test COMMAND wavescape_test)
