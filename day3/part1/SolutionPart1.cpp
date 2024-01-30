#include "SolutionPart1.hpp"
#include <ranges>
#include <vector>
#include <xutility>

std::string SolutionPart1::Solve(std::string_view input)
{
  const auto     row_count = std::distance(input.begin(), std::find(input.begin(), input.end(), '\n')) + 1;
  constexpr auto is_symbol = [](char cc) { return static_cast<bool>(std::ispunct(cc)) && cc != '.'; };
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
  const auto get_num = [&](std::vector<bool>& is_visited, std::string_view::iterator iter) -> int64_t
  {
    if (iter < input.begin() || iter >= input.end() || !is_digit(*iter))
    {
      return 0;
    }

    iter        = get_digit_start_iter(iter);
    int64_t idx = std::distance(input.begin(), iter);
    if (is_visited[idx])
    {
      return 0;
    }
    is_visited[idx] = true;
    return generate_num(iter);
  };

  int64_t sum = 0;
  // track visited numbers
  std::vector<bool> is_visited(input.size(), false);

  // find symbols and look for number around it
  for (auto iter = input.begin(); iter != input.end(); ++iter)
  {
    if (is_symbol(*iter))
    {
      // check left
      sum += get_num(is_visited, iter - 1);
      // check right
      sum += get_num(is_visited, iter + 1);
      // check top
      sum += get_num(is_visited, iter - row_count);
      // check topleft
      sum += get_num(is_visited, iter - row_count - 1);
      // check topright
      sum += get_num(is_visited, iter - row_count + 1);
      // check down
      sum += get_num(is_visited, iter + row_count);
      // check downleft
      sum += get_num(is_visited, iter + row_count - 1);
      // check downright
      sum += get_num(is_visited, iter + row_count + 1);
    }
  }

  return std::to_string(sum);
}
