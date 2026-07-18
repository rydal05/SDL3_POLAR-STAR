cmake_minimum_required(VERSION 3.10)
project(SDL3_Shmup CXX)

find_package(SDL3 REQUIRED CONFIG)

file(GLOB_RECURSE SOURCES "src/src/*.cpp" "src/src/*.h")
add_executable(SDL3_Shmup ${SOURCES})

target_include_directories(SDL3_Shmup PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include/Managers>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include/Players>
)


target_link_libraries(SDL3_Shmup PRIVATE SDL3::SDL3)

set_target_properties(SDL3_Shmup PROPERTIES OUTPUT_NAME "game")

message(STATUS "CMAKE_CURRENT_SOURCE_DIR: :${CMAKE_CURRENT_SOURCE_DIR}")