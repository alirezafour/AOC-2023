#include <benchmark/benchmark.h>
#include "SolutionPart1.hpp"
#include "SolutionPart2.hpp"
#include "input.hpp"

// Define part1 benchmark
static void BM_Part1(benchmark::State& state)
{
  SolutionPart1 solution;
  for (auto _ : state)
    auto result = solution.Solve(final_input);
}
// Register the function as a benchmark
BENCHMARK(BM_Part1);

// Define part2 benchmark
static void BM_Part2(benchmark::State& state)
{
  SolutionPart2 solution;
  for (auto _ : state)
    auto result = solution.Solve(final_input);
}

// Register the function as a benchmark
BENCHMARK(BM_Part2);

// BENCHMARK_MAIN();
