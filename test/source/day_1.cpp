//
// Created by jorge on 12/3/24.
//

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

#include <catch2/catch_test_macros.hpp>
#include <fmt/base.h>

#include "historian_hysteria.hpp"

namespace fs = std::filesystem;
using namespace std::string_literals;
TEST_CASE("Day 1 - Historian Hysteria") {
  // Base test
  const auto test_input = R"(
3   4
4   3
2   5
1   3
3   9
3   3)"s;
  auto input_stream = std::istringstream(test_input);

  auto path = fs::path(DATA_PATH) / "day1_1.txt";
  auto input_file = std::ifstream(path);

  SECTION("Part 1") {
    REQUIRE(HistorianHysteria::solve_p1(input_stream) == 11);

    // Actual test
    fmt::println("Historian Hysteria -- Part 1: {}",
                 HistorianHysteria::solve_p1(input_file));
  }

  SECTION("Part 2") {
    REQUIRE(HistorianHysteria::solve_p2(input_stream) == 31);

    // Actual test
    fmt::println("Historian Hysteria -- Part 2: {}",
                 HistorianHysteria::solve_p2(input_file));
  }
}