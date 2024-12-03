//
// Created by jorge on 12/3/24.
//

#include <algorithm>
#include <cassert>
#include <functional>
#include <istream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

#include "historian_hysteria.hpp"

#include "common.hpp"
#include <cmath>

namespace rng = std::ranges;
namespace vws = std::views;

auto HistorianHysteria::read_lists(std::istream& input)
    -> std::pair<IntList, IntList> {
  // Get raw information
  auto raw_input = common::simple_parse<int>(input);
  assert(raw_input.size() % 2 == 0 && "Input must be evenly divisible by 2");

  // Make into two lists
  auto left = std::vector<int> {};
  rng::copy(raw_input | vws::stride(2), std::back_inserter(left));
  rng::sort(left);

  auto right = std::vector<int> {};
  rng::copy(raw_input | vws::drop(1) | vws::stride(2),
            std::back_inserter(right));
  rng::sort(right);
  assert(left.size() == right.size() && "Both lists should be the same size");

  return std::make_pair(left, right);
}
auto HistorianHysteria::solve_p1(std::istream& input) -> int {
  auto [left, right] = read_lists(input);

  // Calculate distances
  auto result =
      std::inner_product(left.begin(),
                         left.end(),
                         right.begin(),
                         0,
                         std::plus {},
                         [](int lhs, int rhs) { return std::abs(lhs - rhs); });

  return result;
}
auto HistorianHysteria::solve_p2(std::istream& input) -> int {
  auto [left, right] = read_lists(input);
  auto result = int {};

  rng::for_each(left, [&result, &right](int value) {
    result += value * rng::count(right, value);
  });
  return result;
}