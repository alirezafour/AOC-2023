cmake_minimum_required(VERSION 3.24)

#project setup
project(day0
        VERSION 0.0.1
        LANGUAGES CXX
)


set(CMAKE_CXX_COMPILER Clang++)
set(CMAKE_C_COMPILER Clang)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(
  ${CMAKE_SOURCE_DIR}
)

add_subdirectory(part1)
add_subdirectory(part2)
# add_subdirectory(test)
add_subdirectory(benchmark)
