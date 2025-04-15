cmake_minimum_required(VERSION 3.16)

# Project Information
project(NewtonEngine
        DESCRIPTION "A 2D physics engine project"
        VERSION 0.0.1
        LANGUAGES CXX
)

# Include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

include(FetchContent)

# Compiler options
if(MSVC)
    add_compile_options(/W4 /WX /MP /EHsc)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    # GCC / Clang
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Enable testing
option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
    enable_testing()
    
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/heads/main.zip
    )
    FetchContent_MakeAvailable(googletest)

    add_subdirectory(tests)
endif()

# Add source directory
add_subdirectory(src)

# Print build configuration summary
message(STATUS "")
message(STATUS "Newton Engine Configuration Summary")
message(STATUS "================================")
message(STATUS "Version:             ${PROJECT_VERSION}")
message(STATUS "Build type:          Development")
message(STATUS "C++ Compiler:        ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Building tests:      ${BUILD_TESTS}")
message(STATUS "")