//
// Created by jorge on 12/3/24.
//

#ifndef HISTORIAN_HYSTERIA_HPP
#define HISTORIAN_HYSTERIA_HPP

#include <istream>
#include <utility>
#include <vector>

/**
 * https://adventofcode.com/2024/day/1
 */
class HistorianHysteria {
public:
  static auto solve_p1(std::istream& input) -> int;
  static auto solve_p2(std::istream& input) -> int;

private:
  using IntList = std::vector<int>;
  static auto read_lists(std::istream& input) -> std::pair<IntList, IntList>;
};

#endif  // HISTORIAN_HYSTERIA_HPP
