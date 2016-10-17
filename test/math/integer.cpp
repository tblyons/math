#include "tbl/math/integer.hpp"

#include "doctest/doctest.h"

TEST_CASE("tbl::math::basic_unsigned_integer::basic_unsigned_integer()") {
   using uint24_t = tbl::uint24_t;
   uint24_t a; // uninitialized
   uint24_t b; // uninitialized
   uint24_t c(4UL);
   uint24_t d(c);
   uint24_t e(a);
   CHECK((a == b) != (a != b)); // Their values are uninitialized, so may or may not equal, but not both
   CHECK(c == d);
   CHECK(!(c == b));
   c = a;
   CHECK(c == b);
   CHECK(!(c == d));
   CHECK(a == e);
}

TEST_CASE("tbl::math::basic_unsigned_integer::operator+=") {
   using uint24_t = tbl::uint24_t;
   uint24_t a(16UL);
   uint24_t b(a);
   for (size_t i = 0; i < 1'000'000; ++i) {
      a += b;
   }
   CHECK(a != b);
   for (size_t i = 0; i < 1'000'000; ++i) {
      a -= b;
   }
   CHECK(a == b);
}

TEST_CASE("tbl::math::basic_unsigned_integer::performance::for_loop") {
   using uint24_t = tbl::uint24_t;
   using namespace std::chrono_literals;
   auto start = std::chrono::high_resolution_clock::now();
   for (uint24_t i = 0UL; i < 10000000UL; ++i) { static_cast<void>(i); }
   auto finish = std::chrono::high_resolution_clock::now();
   CHECK(finish - start < 15us);
}

TEST_CASE("tbl::math::basic_unsigned_integer::operator<<=") {
   using uint56_t = tbl::uint56_t;
   uint56_t num("320255973501901");
   num <<= 0;
   CHECK(num == uint56_t("320255973501901"));
   num <<= 1;
   CHECK(num == uint56_t("640511947003802"));
   num <<= 8;
   CHECK(num == uint56_t("163971058432973312"));
   num <<= 7;
   CHECK(num == uint56_t("2541551405711032320"));
   num <<= 40;
   CHECK(num == uint56_t("0"));
}
