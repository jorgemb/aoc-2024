#ifndef SOURCE_CERES_SEARCH
#define SOURCE_CERES_SEARCH

#include <istream>

class CeresSearch {
public:
  static auto solve(std::istream& input) -> int;

private:
  /**
   * Counts the number of times an element appears in a string
   */
  static auto count_element_in(std::string_view data,
                               std::string_view element) -> int;
};

#endif  // SOURCE_CERES_SEARCH
