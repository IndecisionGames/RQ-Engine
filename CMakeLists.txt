cmake_minimum_required (VERSION 3.0)
project(RQ-Engine)

# The version number
set (RQ-Engine_VERSION_MAJOR 0)
set (RQ-Engine_VERSION_MINOR 1)

# add the executable
add_executable(RQ-Engine src/core.cpp)

add_subdirectory(libs/SFML)
target_link_libraries (RQ-Engine sfml-system sfml-window sfml-graphics)


add_subdirectory(libs/Box2D)
target_link_libraries (RQ-Engine Box2D)
