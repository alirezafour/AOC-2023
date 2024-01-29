find_package(benchmark CONFIG REQUIRED)

include_directories(
  ${CMAKE_SOURCE_DIR}/part1
  ${CMAKE_SOURCE_DIR}/part2
)

add_executable(benchmark
  benchmark.cpp
  ${CMAKE_SOURCE_DIR}/part1/SolutionPart1.cpp
  ${CMAKE_SOURCE_DIR}/part2/SolutionPart2.cpp
)

target_link_libraries(benchmark PRIVATE benchmark::benchmark benchmark::benchmark_main)
