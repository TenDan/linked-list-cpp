cmake_minimum_required(VERSION 3.24)

project(linked_list_tests)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b796f7d44681514f58a683a3a71ff17c94edb0c1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

get_filename_component(TEST_SOURCES_DIR .
        REALPATH)

set(TEST_SOURCES
        ${TEST_SOURCES_DIR}/all_tests.cpp
        ${TEST_SOURCES_DIR}/linked_list_test.cpp
        )

add_executable(
        all_tests
        ${SOURCE_FILES}
        ${TEST_SOURCES}
)

target_link_libraries(
        all_tests
        GTest::gtest_main
)

gtest_discover_tests(all_tests)