/*****************************************************************************
ISC License

Copyright (c) 2016, Timothy Lyons

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
PERFORMANCE OF THIS SOFTWARE.

******************************************************************************/
#include "math/integer.hpp"

#include "doctest/doctest.h"

#include <chrono>

TEST_CASE("math::basic_unsigned_integer::basic_unsigned_integer()") {
   using uint24_t = math::uint24_t;
   uint24_t a; // uninitialized
   uint24_t b; // uninitialized
   uint24_t c(4UL);
   uint24_t d(c);
   uint24_t e(a);
   CHECK((a == b) != (a != b)); // Their values are uninitialized, so may or may not equal, but not both
   CHECK(c == d);
   CHECK(!(c == b));
   c = a;
   CHECK(!(c == d));
   CHECK(a == e);
}

TEST_CASE("math::basic_unsigned_integer::operator+=") {
   using uint24_t = math::uint24_t;
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

TEST_CASE("math::basic_unsigned_integer::performance::for_loop") {
   using uint24_t = math::uint24_t;
   using namespace std::chrono_literals;
   size_t forloop_limit = 1000;
   auto start = std::chrono::high_resolution_clock::now();
   for (uint24_t i = 0UL; i < forloop_limit; ++i) { static_cast<void>(i); }
   auto finish = std::chrono::high_resolution_clock::now();
   CHECK(finish - start < 70us);
   std::cout << static_cast<std::chrono::duration<double, std::micro>>(finish - start).count() << std::endl;
}

TEST_CASE("math::basic_unsigned_integer comparisons") {
   using uint56_t = math::uint56_t;
   size_t a = 0;
   for (uint56_t i = 0UL; i < 1000UL; ++i) {
      ++a;
   }
   CHECK(uint56_t(a) == uint56_t(1000UL));
   for (uint56_t i = 0UL; i < 1000UL; i += 10) {
      for (uint56_t j = i; j < 1000UL; j += 10) {
         if (i == j) {
            CHECK(i <= j);
            CHECK(i >= j);
            CHECK(!(i != j));
            CHECK(!(i < j));
            CHECK(!(i > j));
         } else {
            CHECK(i <= j);
            CHECK(!(i >= j));
            CHECK(!(i == j));
            CHECK(i != j);
            CHECK((i < j));
            CHECK(j > i);
         }
      }
   }
}

TEST_CASE("math::basic_unsigned_integer::operator<<=") {
   using uint56_t = math::uint56_t;
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
