#include "SolutionPart2.hpp"
#include "Game.hpp"
#include <ranges>
#include <sstream>
#include <xutility>
#include <numeric>

/** return 0 if not valid game */
template <std::ranges::input_range R>
int64_t power_of_min_valid_cube(R&& rng)
{
  constexpr int  RedLimit   = 12;
  constexpr int  GreenLimit = 13;
  constexpr int  Bluelimit  = 14;
  constexpr auto calculate  = [](Game& game) -> int64_t
  { return game.max[Cube::CubeType::RED] * game.max[Cube::CubeType::GREEN] * game.max[Cube::CubeType::BLUE]; };

  std::string       s(rng.begin(), rng.end());
  std::stringstream stream(s);
  Game              game;
  stream >> game;
  return calculate(game);
}

std::string SolutionPart2::Solve(std::string_view input)
{
  int64_t sum = 0;
  for (auto row : input | std::views::split('\n'))
  {
    sum += power_of_min_valid_cube(row);
  }

  return std::to_string(sum);
}
