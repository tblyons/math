#include "tbl/containers/array_stack.hpp"

#include "doctest/doctest.h"

TEST_CASE("tbl::containers::array_stack") {
   tbl::containers::array_stack_t<int> stack;
   stack.add(0, 5);
}
