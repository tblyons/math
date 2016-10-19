#include "tbl/containers/array.hpp"

#include "doctest/doctest.h"

TEST_CASE("tbl::containers::array") {
   tbl::containers::array_t<int> arr(10);
   arr[4] = 42;
   CHECK(42 == arr[4]);
}
