find_package(benchmark CONFIG REQUIRED)


add_executable(benchmark
  benchmark.cpp
)

target_link_libraries(benchmark PRIVATE benchmark::benchmark benchmark::benchmark_main solution1 solution2 input)
