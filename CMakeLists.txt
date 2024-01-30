cmake_minimum_required(VERSION 3.15)
project(home3.1)

add_executable(prog src/main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)