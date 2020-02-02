cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SnakesAbound)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

file(GLOB project_SRCS src/*.cpp) #src/*.h
add_executable(SnakesAbound ${project_SRCS})
target_link_libraries(SnakesAbound ${SDL2_LIBRARIES})
