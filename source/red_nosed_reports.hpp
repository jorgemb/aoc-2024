//
// Created by jorge on 12/3/24.
//

#ifndef RED_NOSED_REPORTS_HPP
#define RED_NOSED_REPORTS_HPP
#include <cstddef>
#include <istream>

class RedNosedReports {
public:
  static auto count_safe(std::istream& input) -> int;
  static auto count_safe_tolerate(std::istream& input) -> int;

private:
  // View for difference within constraints
  static auto pair_inside_range(std::span<int> slide) -> bool;

  // Check if a single line is safe
  static auto line_safe(std::span<int> line) -> bool;
};

#endif  // RED_NOSED_REPORTS_HPP
