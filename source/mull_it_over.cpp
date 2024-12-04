#include <algorithm>
#include <istream>
#include <ranges>
#include <regex>
#include <string>

#include "mull_it_over.hpp"

#include <fmt/base.h>

#include "common.hpp"

namespace rng = std::ranges;
namespace vws = std::views;
using namespace std::string_literals;

auto MullItOver::solve(std::istream& input) -> int {
  auto raw_lines = common::raw_lines(input);
  auto lines = raw_lines | vws::filter(common::filters::line_is_not_empty);

  auto total = int {};
  auto regex = std::regex(R"(mul\((\d+),(\d+)\))"s);

  for (auto& current_line : lines) {
    auto regex_begin =
        std::sregex_iterator(current_line.begin(), current_line.end(), regex);
    auto regex_end = std::sregex_iterator();
    std::for_each(regex_begin, regex_end, [&total](auto match) {
      const auto num1 = std::stoi(match[1].str());
      const auto num2 = std::stoi(match[2].str());
      total += num1 * num2;
    });
  }

  return total;
}

auto MullItOver::solve_with_logic(std::istream& input) -> int {
  auto raw_lines = common::raw_lines(input);
  auto lines = raw_lines | vws::filter(common::filters::line_is_not_empty);

  auto total = int {};
  auto consider_instruction = true;
  auto regex = std::regex(R"(mul\((\d+),(\d+)\)|do(n't)?\(\))"s);

  for (auto& current_line : lines) {
    auto regex_begin =
        std::sregex_iterator(current_line.begin(), current_line.end(), regex);
    auto regex_end = std::sregex_iterator();
    std::for_each(
        regex_begin, regex_end, [&total, &consider_instruction](auto match) {
          if (match.str().contains("don't(")) {
            consider_instruction = false;
          } else if (match.str().contains("do(")) {
            consider_instruction = true;
          } else if (consider_instruction) {
            const auto num1 = std::stoi(match[1].str());
            const auto num2 = std::stoi(match[2].str());
            total += num1 * num2;
          }
        });
  }

  return total;
}