#include "SolutionPart1.hpp"
#include <cctype>
#include <numeric>
#include <ranges>

std::string SolutionPart1::Solve(const std::string& input)
{
  // helper views and lambda
  constexpr auto isNotDigit = [](char c) { return isdigit(c) == 0; };
  constexpr auto firstDigit = std::views::drop_while(isNotDigit);
  constexpr auto lastDigit  = std::views::reverse | firstDigit;
  constexpr auto decimal    = [](auto&& rng) -> int32_t { return *rng.begin() - '0'; };

  // split each lines
  auto result = input | std::views::split('\n');

  // found numbers in each line and add them together
  int32_t sum = 0;
  for (auto each : result)
  {
    sum += decimal(each | firstDigit) * 10 + decimal(each | lastDigit);
  }

  return std::to_string(sum);
}
