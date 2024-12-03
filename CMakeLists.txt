cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    aoc2024
    VERSION 0.1.0
    DESCRIPTION "Advent of Code 2024 in C++!"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1) # hack to prevent CTest added targets
include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    aoc2024_lib OBJECT
    source/lib.cpp
        source/historian_hysteria.cpp
        source/historian_hysteria.hpp
        source/common.cpp
        source/common.hpp
        source/red_nosed_reports.cpp
        source/red_nosed_reports.hpp
)

target_include_directories(
    aoc2024_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(aoc2024_lib PUBLIC cxx_std_23)

find_package(fmt REQUIRED)
target_link_libraries(aoc2024_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(aoc2024_exe source/main.cpp)
add_executable(aoc2024::exe ALIAS aoc2024_exe)

set_property(TARGET aoc2024_exe PROPERTY OUTPUT_NAME aoc2024)

target_compile_features(aoc2024_exe PRIVATE cxx_std_20)

target_link_libraries(aoc2024_exe PRIVATE aoc2024_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT aoc2024_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of aoc2024"
  )
endif()

include(cmake/dev-mode.cmake)
