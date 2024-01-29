#include "SolutionPart1.hpp"
#include "Game.hpp"
#include <ranges>
#include <sstream>
#include <xutility>
#include <numeric>

/** return 0 if not valid game */
template <std::ranges::input_range R>
int64_t get_id_if_valid_game(R&& rng)
{
  constexpr int  RedLimit   = 12;
  constexpr int  GreenLimit = 13;
  constexpr int  Bluelimit  = 14;
  constexpr auto calculate  = [](Game& game) -> int64_t
  {
    if (game.max[Cube::CubeType::RED] <= RedLimit && game.max[Cube::CubeType::GREEN] <= GreenLimit &&
        game.max[Cube::CubeType::BLUE] <= Bluelimit)
    {

      return game.id;
    }
    return 0;
  };

  std::string       s(rng.begin(), rng.end());
  std::stringstream stream(s);
  Game              game;
  stream >> game;
  return calculate(game);
}


std::string SolutionPart1::Solve(std::string_view input)
{
  int64_t sum = 0;
  for (auto row : input | std::views::split('\n'))
  {
    sum += get_id_if_valid_game(row);
  }

  return std::to_string(sum);
}
