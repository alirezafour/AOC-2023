add_library(solution1)
target_sources(solution1 PUBLIC FILE_SET CXX_MODULES FILES SolutionPart1.cc)

add_executable(part1 main.cpp)
target_link_libraries(part1 solution1 input)
