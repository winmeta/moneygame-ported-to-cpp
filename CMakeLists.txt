set(CMAKE_EXE_LINKER_FLAGS "-static")
cmake_minimum_required(VERSION 3.23)
project(moneygame_ported_to_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(moneygame_ported_to_cpp main.cpp)
