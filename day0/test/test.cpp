#include <catch2/catch_test_macros.hpp>
#include "SolutionPart1.hpp"
#include "inputPart1.hpp"
#include "SolutionPart2.hpp"
#include "inputPart2.hpp"

TEST_CASE("part1")
{
  SolutionPart1 solution;
  REQUIRE(solution.Solve(part1::get_input()) == "temp");
  REQUIRE(solution.Solve(part1::get_final_input()) == "temp");
}

TEST_CASE("part2")
{
  SolutionPart2 solution;
  REQUIRE(solution.Solve(part2::get_input()) == "temp");
  REQUIRE(solution.Solve(part2::get_final_input()) == "temp");
}
