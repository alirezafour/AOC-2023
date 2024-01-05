# Advent of Code 2023
answer to [Advent of Code 2023](https://adventofcode.com/2023/) with test and benchmark setup using C++20.

## usage
- duplicate day0 for the the day you need.  
- setup input in `inputPart1.hpp`  
- write your solution in `SolutionPart1::Solve()`  
- update `test/test.cpp`
- build and run
  
## requirement
- vcpkg
- cmake
- c++ compiler (support c++20)

## dependencies
use vcpkg to install:
- Catch2
- benchmark

` vcpkg install Catch2 `  
` vcpkg install benchmark `  

## build
` cmake -B build -DCMAKE_TOOLCHAIN_FILE={ path to your vcpkg.cmake } `  
` cmake --build build --config Release `  

## configurate
in root of day{X} you can remove benchmark or test include 
