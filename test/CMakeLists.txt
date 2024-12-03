# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(aoc2024Tests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_compile_definitions(DATA_PATH="${CMAKE_SOURCE_DIR}/test/data")
add_executable(aoc2024_test source/aoc2024_test.cpp
        source/day_1.cpp)
target_link_libraries(
    aoc2024_test PRIVATE
    aoc2024_lib
    Catch2::Catch2WithMain
)
target_compile_features(aoc2024_test PRIVATE cxx_std_23)

catch_discover_tests(aoc2024_test)

# ---- End-of-file commands ----

add_folders(Test)
