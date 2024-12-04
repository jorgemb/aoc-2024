//
// Created by jorge on 12/3/24.
//

#include "common.hpp"

auto common::raw_lines(std::istream& input) -> std::vector<std::string> {
  auto lines = std::vector<std::string> {};
  auto current_line = std::string {};
  while (std::getline(input, current_line)) {
    lines.push_back(std::move(current_line));
  }

  return lines;
}