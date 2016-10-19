#include "tbl/containers/array_stack.hpp"

#include "doctest/doctest.h"

TEST_CASE("tbl::containers::array_stack") {
   tbl::containers::array_stack_t<int> stack;
   CHECK(0 == stack.size());
   stack.add(0, 5);
   CHECK(1 == stack.size());
   CHECK(5 == stack.get(0));
   stack.remove(0);
   CHECK(0 == stack.size());
   for (int i = 0; i < 10; ++i) {
      stack.add(static_cast<size_t>(i), i);
   }
   CHECK(10 == stack.size());
   for (int i = 0; i < 10; ++i) {
      CHECK(i == stack.get(static_cast<size_t>(i)));
   }
   for (size_t i = 0; i < 5; ++i) {
      stack.remove(i);
   }
   CHECK(5 == stack.size());
   for (size_t i = 0; i < stack.size(); ++i) {
      CHECK(i == stack.get(i) / 2);
      CHECK(1 == stack.get(i) % 2);
   }
}
