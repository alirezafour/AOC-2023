cmake_minimum_required(VERSION 3.28)

#project setup
project(day0
        VERSION 0.0.1
        LANGUAGES CXX
)

# specify the C++ standard and generator
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_GENERATOR "Ninja")

add_library(input)
target_sources(input PUBLIC FILE_SET CXX_MODULES FILES input.cc)

add_subdirectory(part1)
add_subdirectory(part2)
# add_subdirectory(test)
add_subdirectory(benchmark)
