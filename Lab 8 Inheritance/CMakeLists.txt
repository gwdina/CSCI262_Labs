cmake_minimum_required(VERSION 3.17)
project(inheritance)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_compile_options(-pedantic -Wall -Wextra)

add_executable(run main.cpp int_counter.h mod_counter.h)
