cmake_minimum_required(VERSION 3.20)

project(proj)

add_executable(prog thovarua/pseudoRandomNumberGenerator2.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
