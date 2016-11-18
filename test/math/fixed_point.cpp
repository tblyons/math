#include "math/fixed_point.hpp"

#include "doctest/doctest.h"

TEST_CASE("fixed_point_t") {
   math::fixed_point_t<4> fp(10.1234);
   CHECK(fp.whole_number() == 10);
}

TEST_CASE("fixed_point_t::operator+=()") {
   math::fixed_point_t<4> a(1.2345);
   math::fixed_point_t<4> b(5.4321);
   CHECK(a.whole_number() == 1);
   CHECK(b.whole_number() == 5);
   a += b;
   CHECK(a.whole_number() == 6);
   CHECK(b.whole_number() == 5);
}
