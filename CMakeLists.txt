cmake_minimum_required (VERSION 3.0)

project(RQ-Engine)
set (RQ-Engine_VERSION_MAJOR 0)
set (RQ-Engine_VERSION_MINOR 1)

# RQ-Engine
add_executable(RQ-Engine src/main.cpp)
# SFML
add_subdirectory(libs/SFML)
target_link_libraries (RQ-Engine sfml-system sfml-window sfml-graphics sfml-audio)
# Box2D
add_subdirectory(libs/Box2D)
target_link_libraries (RQ-Engine Box2D)

# Files
file(GLOB BASE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/*.cpp)
file(GLOB CORE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/core/*.cpp)

set(RQ_SOURCES
${BASE_SOURCES}
${CORE_SOURCES})

# add_library(RQ_ENGINE
#   ${RQ_SOURCES})
