add_library(solution2)
target_sources(solution2 PUBLIC FILE_SET CXX_MODULES FILES SolutionPart2.cc)

add_executable(part2 main.cpp)
target_link_libraries(part2 solution2 input)

