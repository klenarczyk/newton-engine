file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/Core/Math/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Physics/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Memory/*.cpp"
)

# Create a static library for reusable engine components
add_library(NewtonEngineLib STATIC ${ENGINE_SOURCES})

# Expose public include directories
target_include_directories(NewtonEngineLib PUBLIC ${CMAKE_SOURCE_DIR}/include)