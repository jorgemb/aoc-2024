//
// Created by jorge on 12/3/24.
//

#include <filesystem>
#include <fstream>

#include <catch2/catch_test_macros.hpp>
#include <fmt/base.h>

#include "red_nosed_reports.hpp"

namespace fs = std::filesystem;

TEST_CASE("Day 2: Red-Nosed Reports") {
  auto raw_input = R"(
7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9
)";
  auto test_input_data = std::istringstream(raw_input);

  auto input_path = fs::path(DATA_PATH) / "day2.txt";
  auto input_file = std::ifstream(input_path);

  SECTION("Part 1") {
    REQUIRE(RedNosedReports::count_safe(test_input_data) == 2);

    // Answer
    fmt::println("Red-Nosed Reports - Part 1: {}",
                 RedNosedReports::count_safe(input_file));
  }

  SECTION("Part 2") {
    REQUIRE(RedNosedReports::count_safe_tolerate(test_input_data) == 4);

    // Answer
    fmt::println("Red-Nosed Reports - Part 2: {}",
                 RedNosedReports::count_safe_tolerate(input_file));
  }
}