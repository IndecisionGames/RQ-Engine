cmake_minimum_required (VERSION 3.0)

project(RQ-Engine)
set (RQ-Engine_VERSION_MAJOR 0)
set (RQ-Engine_VERSION_MINOR 1)

set (CMAKE_CXX_STANDARD 14)

# libs
add_subdirectory(libs/SFML)
add_subdirectory(libs/Box2D)

# engine
file(GLOB BASE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
file(GLOB CORE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/core/*.cpp)

set(RQ_SOURCES
${BASE_SOURCES}
${CORE_SOURCES})

add_library(RQ-Engine
${RQ_SOURCES})

target_include_directories(RQ-Engine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src)

# linking
target_link_libraries (RQ-Engine sfml-system sfml-window sfml-graphics sfml-audio)
target_link_libraries (RQ-Engine Box2D)
