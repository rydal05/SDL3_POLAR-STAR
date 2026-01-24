cmake_minimum_required(VERSION 3.7)

project(SDL3_Shmup)

find_package(SDL3 REQUIRED)
include_directories(${SDL3_INCLUDE_DIRS})

add_executable(SDL3_Shmup ./src/main.cpp)
set_target_properties(SDL3_Shmup PROPERTIES OUTPUT_NAME "game")	

target_link_libraries(SDL3_Shmup ${SDL3_LIBRARIES})