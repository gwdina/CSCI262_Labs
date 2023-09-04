cmake_minimum_required(VERSION 3.17)
project(stack_part_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_compile_options(-pedantic -Wall -Wextra)

add_executable(stack_main stack.h main.cpp)

add_subdirectory(tests)
