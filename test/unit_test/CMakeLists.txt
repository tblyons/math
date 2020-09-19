################################################################################
# License: The Unlicense (https://unlicense.org)
################################################################################
cmake_minimum_required(VERSION 3.14) # FetchContent_MakeAvailable

# Use doctest as unit test framework
FetchContent_Declare(doctest
  GIT_REPOSITORY https://github.com/onqtam/doctest.git
  GIT_TAG        "2.4.0")
FetchContent_MakeAvailable(doctest)

# Define unittests executable target
add_executable(unit_test)
target_link_libraries(unit_test PRIVATE math compiler_settings doctest::doctest)
target_sources(unit_test
  PRIVATE
    main.cpp
    math/fixed_point.cpp
    math/integer.cpp
    math/stats.cpp)

add_test(NAME unit_test_t COMMAND unit_test)
