cmake_minimum_required (VERSION 3.0)
project(RQ-Engine)

# The version number
set (RQ-Engine_VERSION_MAJOR 0)
set (RQ-Engine_VERSION_MINOR 1)

# add SFML
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SFML/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# add the executable
add_executable(RQ-Engine src/core.cpp)
target_link_libraries (RQ-Engine sfml-system sfml-window sfml-graphics)