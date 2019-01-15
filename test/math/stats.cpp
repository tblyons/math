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
#include "math/stats.hpp"

#include "doctest/doctest.h"

TEST_CASE("math::stats") {
   math::stats accum;
   for (long i = 0; i < 100; ++i) {
      accum.include(i);
      accum.include(-i);
      CHECK(accum.mean() < 0.000001);
   }
   CHECK(accum.minimum() == -99);
   CHECK(accum.maximum() == 99);
}
