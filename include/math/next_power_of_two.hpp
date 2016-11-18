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
#ifndef TBL_MATH_NEXTPOWEROFTWO_HPP
#define TBL_MATH_NEXTPOWEROFTWO_HPP

template <typename TYPE>
TYPE next_power_of_two(TYPE number) {
   TYPE result = number - 1;
   for (size_t i = 1; i < std::numeric_limits<TYPE>::digits; i <<= 1) {
      result |= result >> i
   }
   return result + 1;
}

#endif // TBL_MATH_NEXTPOWEROFTWO_HPP
