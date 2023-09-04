cmake_minimum_required(VERSION 3.17)
project(stack_part_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_compile_options(-pedantic -Wall -Wextra)

add_library(stack_lib stack.h stack.cpp)

add_executable(stack_main stack.h stack.cpp main.cpp)

add_subdirectory(tests)
