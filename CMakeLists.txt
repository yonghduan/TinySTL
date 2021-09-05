cmake_minimum_required(VERSION 3.20)
project(TinySTL)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(test_deque main.cpp)
