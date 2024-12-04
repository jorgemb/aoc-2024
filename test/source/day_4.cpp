
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

#include <catch2/catch_test_macros.hpp>
#include <fmt/base.h>

#include "ceres_search.hpp"

using namespace std::string_literals;
namespace fs = std::filesystem;

TEST_CASE("Day4: Ceres Search") {
  // Testing data
  auto test_raw_input = R"(
MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX)"s;
  auto test_input = std::istringstream(test_raw_input);

  // Real data
  auto input_path = fs::path(DATA_PATH) / "day4.txt";
  auto input_file = std::ifstream(input_path);

  SECTION("Part 1") {
    REQUIRE(CeresSearch::solve(test_input) == 18);

    fmt::println("Ceres Search - Part 1: {}", CeresSearch::solve(input_file));
  }

  //   SECTION("Part 2") {
  //     REQUIRE(CeresSearch::solve_with_logic(test_input) == 48);

  //     fmt::println("Ceres Search - Part 2: {}",
  //                  CeresSearch::solve_with_logic(input_file));
  //   }
}