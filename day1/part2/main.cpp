#include <iostream>
#include "inputPart2.hpp"
#include "SolutionPart2.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  std::cout << "part2:\n";
  {
    SolutionPart2 solution;
    std::cout << "test input result: " << solution.Solve(part2::get_input()) << '\n';
  }

  {
    SolutionPart2 solution;
    std::cout << "final input result: " << solution.Solve(part2::get_final_input()) << '\n';
  }
  return 0;
}
