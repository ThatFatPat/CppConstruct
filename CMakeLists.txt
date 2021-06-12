cmake_minimum_required(VERSION 3.18)
project(CppConstruct CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(CppConstruct STATIC src/bufferreadable.cpp src/parser.cpp)
target_include_directories(CppConstruct PUBLIC src/include)

add_executable(CppConstructTest src/main.cpp)
target_link_libraries(CppConstructTest CppConstruct)