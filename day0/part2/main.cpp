import input;
import SolutionPart2;

#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  std::cout << "part2:\n";
  {
    SolutionPart2 solution;
    std::cout << "test input result: " << solution.Solve(part2::input) << '\n';
  }

  {
    SolutionPart2 solution;
    std::cout << "final input result: " << solution.Solve(final_input) << '\n';
  }
  return 0;
}
