# cmake_minimum_required(VERSION <specify CMake version here>)
project(cube)

set(CMAKE_CXX_STANDARD 14)

add_executable(main.cpp constants.h utilities.cpp utilities.h Hash_table.cpp Hash_table.h Key.h hash_func.cpp hash_func.h data_point.h Value.h)