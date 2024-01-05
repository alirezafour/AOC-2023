find_package(Catch2 REQUIRED)

include_directories(
  ${CMAKE_SOURCE_DIR}/part1
  ${CMAKE_SOURCE_DIR}/part2
)

add_executable(test
  test.cpp
  ${CMAKE_SOURCE_DIR}/part1/SolutionPart1.cpp
  ${CMAKE_SOURCE_DIR}/part2/SolutionPart2.cpp
)

target_link_libraries(test PRIVATE Catch2::Catch2WithMain)
