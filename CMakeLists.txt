cmake_minimum_required(VERSION 3.24)
project(linked_list)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(USE_ASAN true)
if ((DEFINED USE_ASAN) AND (USE_ASAN STREQUAL "true"))
    message(STATUS "Using AddressSanitizer (ASan).")
    if (UNIX)
        # message(STATUS "ASAN_OPTIONS = $ENV{ASAN_OPTIONS}")
        # set(ENV{ASAN_OPTIONS} allocator_may_return_null=1)
        add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address)
    endif(UNIX)
endif()

include_directories(include)

get_filename_component(SOURCE_FILES_DIR ./src/
        REALPATH BASE_DIR "${PROJECT_SOURCE_DIR}")

set(SOURCE_FILES
        ${SOURCE_FILES_DIR}/linked_list.cpp
        )

add_executable(linked_list
        main.cpp
        ${SOURCE_FILES}
        )

add_subdirectory(tests)
