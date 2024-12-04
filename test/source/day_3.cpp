#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

#include <catch2/catch_test_macros.hpp>
#include <fmt/base.h>

#include "mull_it_over.hpp"

using namespace std::string_literals;
namespace fs = std::filesystem;

TEST_CASE("Day3: Mull It Over") {
  // Real data
  auto input_path = fs::path(DATA_PATH) / "day3.txt";
  auto input_file = std::ifstream(input_path);

  SECTION("Part 1") {
    // Testing data
    auto test_raw_input =
        R"(xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"s;
    auto test_input = std::istringstream(test_raw_input);
    REQUIRE(MullItOver::solve(test_input) == 161);

    fmt::println("Mull it Over - Part 1: {}", MullItOver::solve(input_file));
  }

  SECTION("Part 2") {
    // Testing data
    auto test_raw_input =
        R"(xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5)))"s;
    auto test_input = std::istringstream(test_raw_input);
    REQUIRE(MullItOver::solve_with_logic(test_input) == 48);

    fmt::println("Mull it Over - Part 2: {}",
                 MullItOver::solve_with_logic(input_file));
  }
}