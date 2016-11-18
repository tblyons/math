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
#ifndef TBL_MATH_DECIMAL_HPP
#define TBL_MATH_DECIMAL_HPP

namespace math {

template <typename mantissa, typename exponent>
struct decimal_t {
   decimal_t();
   bool operator==(const decimal_t &other) const {
      return ((m_value == other.m_value) && (m_factor == other.m_factor));
   }
   bool operator!=(const decimal_t &other) const {
      return !operator==(other);
   }
   bool operator<=(const decimal_t &other) const;
   bool operator>=(const decimal_t &other) const;
   bool operator<(const decimal_t &other) const;
   bool operator>(const decimal_t &other) const;
   decimal_t& operator+=(decimal_t other) {
      const bool fewer = (m_factor < other.m_factor);
      m_value = m_value * (fewer ? other.m_factor / m_factor : 1)
        + other.m_value * (fewer ? 1 : m_factor / other.m_factor);
      m_factor = (fewer ? other.m_factor : m_factor);
      return *this;
   }
   decimal_t& operator-=(decimal_t other) {
      const bool fewer = (m_factor < other.m_factor);
      m_value = m_value * (fewer ? other.m_factor / m_factor : 1)
        - other.m_value * (fewer ? 1 : m_factor / other.m_factor);
      m_factor = (fewer ? other.m_factor : m_factor);
      return *this;
   }
   decimal_t& operator*=(const decimal_t &other) {
      m_value *= other.m_value;
      m_factor *= other.m_factor;
      return *this;
   }
private:
   mantissa m_value;
   exponent m_factor;
};

} // namespace math

#endif // TBL_MATH_DECIMAL_HPP
