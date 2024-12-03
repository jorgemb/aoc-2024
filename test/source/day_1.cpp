//
// Created by jorge on 12/3/24.
//

#include <string>

#include <catch2/catch_test_macros.hpp>

#include "historian_hysteria.hpp"

using namespace std::string_literals;
TEST_CASE("Day1 - Historian Hysteria")
{
  // Base test
  const auto test_input = R"(
3   4
4   3
2   5
1   3
3   9
3   3)";

  auto input_stream = std::istringstream(test_input);
  REQUIRE(HistorianHysteria::solve(input_stream) == 11);
}