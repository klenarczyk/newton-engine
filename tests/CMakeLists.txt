file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
        "CoreTests/MathTests/*.cpp"
        "PhysicsTests/*.cpp"
        "PhysicsTests/IntegratorTests/*.cpp"
)

# Create one test executable
add_executable(NewtonTests ${TEST_SOURCES})

# Link against GoogleTest
target_link_libraries(NewtonTests gtest gtest_main NewtonEngineLib)

# Add to CTest
add_test(NAME NewtonTests COMMAND NewtonTests)

# Include necessary directories
target_include_directories(NewtonTests PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)
