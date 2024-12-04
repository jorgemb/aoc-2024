#include <algorithm>
#include <cassert>
#include <cstdint>
#include <functional>
#include <numeric>
#include <ranges>
#include <string>
#include <string_view>

#include "ceres_search.hpp"

#include "common.hpp"

namespace rng = std::ranges;
namespace vws = std::views;

using namespace std::string_literals;

auto CeresSearch::solve(std::istream& input) -> int {
  auto raw_lines = common::raw_lines(input);
  auto lines = raw_lines | vws::filter(common::filters::line_is_not_empty);
  auto columns = lines.front().size();
  auto rows = rng::distance(lines);

  assert(rows > 0 && "There should be at least 1 line");

  assert(rng::all_of(lines,
                     [columns](auto& line) { return line.size() == columns; })
         && "All lines should be the same size");

  // Get as a single line
  auto as_line = lines | vws::join;
  const auto target = "XMAS"s;

  // Horizontal
  auto total = int {};
  auto horizontal =
      as_line | vws::chunk(columns) | vws::transform([&target](auto line) {
        return count_element_in(line, target);
      });

  return 0;
}

auto CeresSearch::count_element_in(std::string_view data,
                                   std::string_view element) -> int {
  auto result = int {};
  auto position = std::size_t {};

  while (position < data.size()) {
    auto found_pos = data.find(element, position);
    if (found_pos != std::string_view::npos) {
      ++result;
      position = found_pos + element.size();
    } else {
      break;
    }
  }

  return result;
}
