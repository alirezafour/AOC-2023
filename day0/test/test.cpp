#include <catch2/catch_test_macros.hpp>
import input;
import SolutionPart1;
import SolutionPart2;

TEST_CASE("part1")
{
  SolutionPart1 solution;
  REQUIRE(solution.Solve(part1::input) == "temp");
  REQUIRE(solution.Solve(final_input) == "temp");
}

TEST_CASE("part2")
{
  SolutionPart2 solution;
  REQUIRE(solution.Solve(part2::input) == "temp");
  REQUIRE(solution.Solve(final_input) == "temp");
}
