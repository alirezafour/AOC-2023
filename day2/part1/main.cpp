#include <iostream>
#include "input.hpp"
#include "SolutionPart1.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  std::cout << "part1:\n";
  {
    SolutionPart1 solution;
    std::cout << "test input result: " << solution.Solve(part1::input) << '\n';
  }

  {
    SolutionPart1 solution;
    std::cout << "final input result: " << solution.Solve(final_input) << '\n';
  }
  return 0;
}
