find_package(Catch2 REQUIRED)

add_executable(test
  test.cpp
)

target_link_libraries(test PRIVATE Catch2::Catch2WithMain solution1 solution2 input)
