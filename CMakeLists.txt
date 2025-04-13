cmake_minimum_required(VERSION 3.16)

# Project Information
project(NewtonEngine
        DESCRIPTION "A 2D physics engine project"
        VERSION 0.0.1
        LANGUAGES CXX)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
endif()

# Include directories
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

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
endif()

# Options
option(USE_DOUBLE_PRECISION "Use double precision for calculations" OFF)
# option(BUILD_EXAMPLES "Build the examples" OFF) # Future examples

if(USE_DOUBLE_PRECISION)
    add_definitions(-DPHYS_USE_DOUBLE_PRECISION)
endif()

# Add source directory
add_subdirectory(src)

# Add tests (if enabled)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

# Add examples (if enabled)
#if(BUILD_EXAMPLES)
#    add_subdirectory(examples)
#endif()

# Print build configuration summary
message(STATUS "")
message(STATUS "Newton Engine Configuration Summary")
message(STATUS "================================")
message(STATUS "Version:             ${PROJECT_VERSION}")
message(STATUS "Build type:          ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Compiler:        ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Double precision:    ${USE_DOUBLE_PRECISION}")
message(STATUS "Profiling enabled:   ${ENABLE_PROFILING}")
message(STATUS "Building tests:      ${BUILD_TESTS}")
message(STATUS "Building examples:   ${BUILD_EXAMPLES}")
message(STATUS "")