#include "math/fixed_point.hpp"

#include "doctest/doctest.h"

TEST_CASE("fixed_point_t") {
   fixed_point_t<4> fp(10.1234);
   CHECK(fp.whole_number() == 10);
}

TEST_CASE("fixed_point_t::operator+=()") {
   fixed_point_t<4> a(1.2345);
   fixed_point_t<4> b(5.4321);
   CHECK(a.whole_number() == 1);
   CHECK(b.whole_number() == 5);
   a += b;
   CHECK(a.whole_number() == 6);
   CHECK(b.whole_number() == 5);
}
