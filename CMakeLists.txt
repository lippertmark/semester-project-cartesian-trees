cmake_minimum_required(VERSION 3.20)

# Примечание: придумайте нормальное название проекту (как это указано в Google таблице)
project(untitled3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build assignment tests." ON)

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_BUILD_TYPE BUILD_TESTS)

# статическая библиотека
add_library(${PROJECT_NAME}_lib STATIC src/cartesian_tree.cpp)
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)

# исполняемый файл
add_executable(${PROJECT_NAME} analysis.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

# Tests
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(contrib)
    add_subdirectory(tests)
endif (BUILD_TESTS)