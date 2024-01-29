#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <unordered_map>

struct Cube
{
  enum CubeType
  {
    RED,
    GREEN,
    BLUE
  };
  CubeType type;
  int32_t  count;

  friend std::istream& operator>>(std::istream& stream, Cube& cube);
};

inline std::istream& operator>>(std::istream& s, Cube& cube)
{
  // Number of cubes
  if (not(s >> cube.count))
    return s;

  // Ignore whitespace
  while (s.peek() == ' ')
    s.get();

  // Based on the first letter set the color and ignore the appropriate
  // number of characters.
  switch (s.peek())
  {
    case 'b':
      cube.type = Cube::CubeType::BLUE;
      s.ignore(4);
      break;
    case 'g':
      cube.type = Cube::CubeType::GREEN;
      s.ignore(5);
      break;
    case 'r':
      cube.type = Cube::CubeType::RED;
      s.ignore(3);
      break;
    default:
      throw std::runtime_error("Parsing error, unexpected color.");
  }
  return s;
}

struct Game
{
  using MapType = std::unordered_map<Cube::CubeType, int32_t>;

  int32_t id;
  MapType max;

  friend std::istream& operator>>(std::istream& stream, Game& game);
  friend std::ostream& operator<<(std::ostream& stream, Game& game);
};

inline std::istream& operator>>(std::istream& s, Game& game)
{
  if (s.peek() != 'G' || not s.ignore(5))
  {
    // Peeking does not set a fail flag, we have to do that manually
    s.setstate(std::ios_base::failbit);
    return s;
  }
  if (not(s >> game.id))
    return s;
  s.ignore(1); // ':'

  // We have a game, now read the sets of cubes.
  game.max.clear();
  Cube cube;
  while (s >> cube)
  {
    game.max[cube.type] = std::max(game.max[cube.type], cube.count);

    auto delim = s.get();
    // Next cube or set of cubes (it actually doesn't matter)
    if (delim == ',' || delim == ';')
      continue;
    // End of this game
    if (delim == '\n')
      break;
    // End of input
    if (delim == std::char_traits<char>::eof())
    {
      // This is the last game, we need to clear the eof flag, otherwise it
      // would be ignored. We want the failure to be detected when we attempt
      // reading the next game.
      s.clear();
      break;
    }
  }
  return s;
}
