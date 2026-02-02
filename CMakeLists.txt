cmake_minimum_required(VERSION 3.7)
project(SDL3_Shmup)

# 1. Use CONFIG mode to ensure CMake finds the official SDL3 package config
find_package(SDL3 REQUIRED CONFIG)

file(GLOB SOURCES "src/*.cpp")
add_executable(SDL3_Shmup ${SOURCES})

# 2. Add your local project headers
target_include_directories(SDL3_Shmup PRIVATE include)

# 3. Link against the SDL3 Target instead of global variables
# This automatically handles include paths and library flags for you
target_link_libraries(SDL3_Shmup PRIVATE SDL3::SDL3)

# Optional: Clean up output name
set_target_properties(SDL3_Shmup PROPERTIES OUTPUT_NAME "game")
