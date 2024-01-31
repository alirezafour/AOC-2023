#include "SolutionPart2.hpp"
#include <ranges>
#include <vector>
#include <xutility>

std::string SolutionPart2::Solve(std::string_view input)
{
  const auto     row_count = std::distance(input.begin(), std::find(input.begin(), input.end(), '\n')) + 1;
  constexpr auto is_gear   = [](char cc) { return cc == '*'; };
  constexpr auto is_digit  = [](char cc) { return static_cast<bool>(std::isdigit(cc)); };

  /** generate the number from its first iter */
  const auto generate_num = [&](std::string_view::iterator iter) -> int64_t
  {
    int64_t num = 0;
    while (iter != input.end() && is_digit(*iter))
    {
      num *= 10;
      num += *iter - '0';
      ++iter;
    }
    return num;
  };

  /** get iter to first of the number */
  const auto get_digit_start_iter = [&](std::string_view::iterator iter) -> std::string_view::iterator
  {
    if (iter == input.begin())
    {
      return iter;
    }
    while (iter >= input.begin() && is_digit(*iter))
    {
      --iter;
    }
    return iter + 1;
  };

  /** get the complete number or 0 if not a valid */
  const auto get_num = [&](std::vector<bool>& is_visited, std::string_view::iterator iter) -> std::tuple<bool, int64_t>
  {
    if (iter < input.begin() || iter >= input.end() || !is_digit(*iter))
    {
      return {false, 0};
    }

    iter        = get_digit_start_iter(iter);
    int64_t idx = std::distance(input.begin(), iter);
    if (is_visited[idx])
    {
      return {false, 0};
    }
    is_visited[idx] = true;
    return {true, generate_num(iter)};
  };

  int64_t sum = 0;
  // track visited numbers
  std::vector<bool> is_visited(input.size(), false);

  // find symbols and look for number around it
  for (auto iter = input.begin(); iter != input.end(); ++iter)
  {
    if (is_gear(*iter))
    {
      int64_t multi = 1;
      int8_t  count = 0;
      // check left
      if (auto [isvalid, num] = get_num(is_visited, iter - 1); isvalid)
      {
        ++count;
        multi *= num;
      }
      // check right
      if (auto [isvalid, num] = get_num(is_visited, iter + 1); isvalid)
      {
        ++count;
        multi *= num;
      }
      // check top
      if (auto [isvalid, num] = get_num(is_visited, iter - row_count); isvalid)
      {
        ++count;
        multi *= num;
      }
      // check topleft
      if (auto [isvalid, num] = get_num(is_visited, iter - row_count - 1); isvalid)
      {
        ++count;
        multi *= num;
      }
      // check topright
      if (auto [isvalid, num] = get_num(is_visited, iter - row_count + 1); isvalid)
      {
        ++count;
        multi *= num;
      }
      // check down
      if (auto [isvalid, num] = get_num(is_visited, iter + row_count); isvalid)
      {
        ++count;
        multi *= num;
      }
      // check downleft
      if (auto [isvalid, num] = get_num(is_visited, iter + row_count - 1); isvalid)
      {
        ++count;
        multi *= num;
      }
      // check downright
      if (auto [isvalid, num] = get_num(is_visited, iter + row_count + 1); isvalid)
      {
        ++count;
        multi *= num;
      }
      if (count == 2)
      {
        sum += multi;
      }
    }
  }

  return std::to_string(sum);
}
