cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp src/cartesian_tree.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)

