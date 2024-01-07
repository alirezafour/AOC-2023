#pragma once

#include <string>
#include <string_view>

class SolutionPart2
{
public:
  explicit SolutionPart2() = default;
  std::string Solve(std::string_view input);

private:
  int32_t FindDigit(std::string_view input);
};
