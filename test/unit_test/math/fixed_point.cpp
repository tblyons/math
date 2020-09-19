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
#include "math/fixed_point.hpp"

#include "doctest/doctest.h"

TEST_CASE("fixed_point_t") {
   math::fixed_point_t<std::ratio<1, 10000>> fp(10.1234);
   CHECK(fp.whole_number() == 10);
   CHECK(fp.fraction().m_numerator == 1234);
   CHECK(fp.fraction().m_denominator == 10000);
   CHECK(fp.significand() == 101234);
}

TEST_CASE("fixed_point_t::operator+=()") {
   math::fixed_point_t<std::ratio<1, 10000>> a(1.2345);
   math::fixed_point_t<std::ratio<1, 10000>> b(5.4321);
   CHECK(a.whole_number() == 1);
   CHECK(a.fraction().m_numerator == 2345);
   CHECK(a.fraction().m_denominator == 10000);
   CHECK(a.significand() == 12345);
   CHECK(b.whole_number() == 5);
   CHECK(b.fraction().m_numerator == 4321);
   CHECK(b.fraction().m_denominator == 10000);
   CHECK(b.significand() == 54321);
   a += b;
   CHECK(a.whole_number() == 6);
   CHECK(a.fraction().m_numerator == 6666);
   CHECK(a.fraction().m_denominator == 10000);
   CHECK(a.significand() == 66666);
   CHECK(b.whole_number() == 5);
   CHECK(b.fraction().m_numerator == 4321);
   CHECK(b.fraction().m_denominator == 10000);
   CHECK(b.significand() == 54321);
}
