#include "SolutionPart2.hpp"

#include <algorithm>
#include <iterator>
#include <ranges>
#include <array>
#include <cstdint>

constexpr std::array<std::string_view, 19> digits =
  {"0",
   "1",
   "2",
   "3",
   "4",
   "5",
   "6",
   "7",
   "8",
   "9",
   "one",
   "two",
   "three",
   "four",
   "five",
   "six",
   "seven",
   "eight",
   "nine"};

std::string SolutionPart2::Solve(std::string_view input)
{
  auto lines = input | std::views::split('\n');

  int32_t sum = 0;
  for (auto line : lines)
  {
    int32_t firstDigit = -1;
    int32_t lastDigit  = -1;
    for (auto pos : std::views::iota(line.begin(), line.end()))
    {
      auto substr = std::string_view(pos, line.end());
      firstDigit  = FindDigit(substr);
      if (firstDigit != -1)
      {
        break;
      }
    }
    for (auto pos = line.end() - 1;; --pos)
    {
      auto substr = std::string_view(pos, line.end());
      lastDigit   = FindDigit(substr);
      if (lastDigit != -1 || pos == line.begin())
      {
        break;
      }
    }

    sum += firstDigit * 10 + lastDigit;
  }

  return std::to_string(sum);
}

int32_t SolutionPart2::FindDigit(std::string_view input)
{
  auto match = std::ranges::find_if(digits, [&](auto&& digit) { return input.starts_with(digit); });
  if (match == digits.end())
  {
    return -1;
  }

  auto digit = static_cast<int32_t>(std::distance(digits.begin(), match));
  if (digit >= 10)
  {
    return digit - 9;
  }
  return digit;
}
