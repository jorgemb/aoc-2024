//
// Created by jorge on 12/3/24.
//

#ifndef COMMON_HPP
#define COMMON_HPP
#include <istream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace common {
/**
 * Does a simple parsing of the data into a vector
 */
template<typename T>
auto simple_parse(std::istream& istream) -> std::vector<T> {
  auto parsed_data = std::vector<T> {};
  std::copy(std::istream_iterator<T> {istream},
            std::istream_iterator<T> {},
            std::back_inserter(parsed_data));
  return parsed_data;
}

/**
 * Parses a series of lines into vectors. Returns a vector of vectors.
 */
template<typename T>
auto parse_lines(std::istream& input) -> std::vector<std::vector<T>> {
  auto parsed_lines = std::vector<std::vector<T>> {};

  auto line = std::string {};
  while (std::getline(input, line)) {
    auto stream = std::istringstream {line};
    parsed_lines.emplace_back(simple_parse<T>(stream));
  }

  return parsed_lines;
}

template<typename T>
using TMatrix = std::vector<std::vector<T>>;

using IntMatrix = std::vector<std::vector<int>>;

}  // namespace common
#endif  // COMMON_HPP
