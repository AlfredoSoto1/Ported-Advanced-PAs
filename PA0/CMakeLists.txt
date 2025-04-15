cmake_minimum_required(VERSION 3.22)

# Set the name of the project
project(pa0)

# We'll go with C++ 20.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add external dependencies directory
set(EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/external")

# Download Raylib if not found
if (NOT EXISTS "${EXTERNAL_DIR}/raylib")
    message(STATUS "Raylib not found, downloading...")
    file(DOWNLOAD https://github.com/raysan5/raylib/archive/refs/tags/5.5.zip ${EXTERNAL_DIR}/raylib.zip)
    execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${EXTERNAL_DIR}/raylib.zip WORKING_DIRECTORY ${EXTERNAL_DIR})
    execute_process(COMMAND ${CMAKE_COMMAND} -E rename ${EXTERNAL_DIR}/raylib-5.5 ${EXTERNAL_DIR}/raylib)
    execute_process(COMMAND ${CMAKE_COMMAND} -E remove ${EXTERNAL_DIR}/raylib.zip)

    file(DOWNLOAD https://github.com/RobLoach/raylib-cpp/archive/refs/tags/v5.5.0.zip ${EXTERNAL_DIR}/raylib.zip)
    execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${EXTERNAL_DIR}/raylib.zip WORKING_DIRECTORY ${EXTERNAL_DIR})
    execute_process(COMMAND ${CMAKE_COMMAND} -E rename ${EXTERNAL_DIR}/raylib-cpp-5.5.0 ${EXTERNAL_DIR}/raylib-cpp)
    execute_process(COMMAND ${CMAKE_COMMAND} -E remove ${EXTERNAL_DIR}/raylib.zip)
endif()

# Add preprocessor definitions based on the build type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DUR_DEBUG)
    add_definitions(-DASSETS_DIR=\"../../../assets/\")
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DUR_RELEASE)
    add_definitions(-DASSETS_DIR)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug-Unix")
    add_definitions(-DUR_DEBUG)
    add_definitions(-DASSETS_DIR=\"../../assets/\")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release-Unix")
    add_definitions(-DUR_RELEASE)
    add_definitions(-DASSETS_DIR)
endif()

# Define Latest OpenGL version before building Raylib
add_definitions(-DGRAPHICS_API_OPENGL_33)

# Add Raylib
add_subdirectory(${EXTERNAL_DIR}/raylib)
include_directories(${EXTERNAL_DIR}/raylib/src)
include_directories(${EXTERNAL_DIR}/raylib-cpp/include)

# Define all source files
file(GLOB_RECURSE GAME_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Create the game executable
add_executable(pa0 ${GAME_SOURCES})
target_include_directories(pa0 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Link Raylib
target_link_libraries(pa0 raylib)

# Platform-specific configurations
if (WIN32)
    target_link_libraries(pa0 winmm gdi32 opengl32)
elseif (UNIX AND NOT APPLE)
    target_link_libraries(pa0 m pthread dl rt X11)
elseif (APPLE)
    target_link_libraries(pa0 "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreFoundation" "-framework CoreAudio" "-framework CoreVideo" "-framework AudioToolbox")
endif()