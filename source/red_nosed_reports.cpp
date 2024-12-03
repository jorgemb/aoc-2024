//
// Created by jorge on 12/3/24.
//

#include <algorithm>
#include <cassert>
#include <cmath>
#include <istream>
#include <iterator>
#include <ranges>
#include <span>
#include <vector>

#include "red_nosed_reports.hpp"

namespace rng = std::ranges;
namespace vws = std::views;

#include "common.hpp"
auto RedNosedReports::count_safe(std::istream& input) -> int {
  auto all_lines = common::parse_lines<int>(input);

  // Filter empty lines
  auto lines =
      all_lines | vws::filter([](auto& line) { return !line.empty(); });

  // Check which lines are safe
  return rng::count_if(lines, line_safe);
}
auto RedNosedReports::count_safe_tolerate(std::istream& input) -> int {
  auto all_lines = common::parse_lines<int>(input);

  // Filter empty lines
  auto lines =
      all_lines | vws::filter([](auto& line) { return !line.empty(); });

  auto result = int {};
  for (auto& line : lines) {
    // Generate permutations
    auto possibilities = std::vector<std::vector<int>> {};
    rng::transform(vws::iota(0U, line.size()),
                   std::back_inserter(possibilities),
                   [&line](auto n) {
                     auto copy = line;
                     copy.erase(copy.begin() + n);
                     return copy;
                   });

    if (rng::any_of(possibilities, line_safe)) {
      ++result;
    }
  }

  return result;
}

auto RedNosedReports::line_safe(std::span<int> line) -> bool {
  auto ascending = rng::is_sorted(line);
  auto descending = rng::is_sorted(vws::reverse(line));
  auto within_constraints =
      rng::all_of(line | vws::slide(2), pair_inside_range);
  return (ascending || descending) && within_constraints;
}

auto RedNosedReports::pair_inside_range(std::span<int> slide) -> bool {
  assert(slide.size() == 2 && "Expecting pairs of elements");
  auto diff = std::abs(slide[0] - slide[1]);
  return diff >= 1 && diff <= 3;
}