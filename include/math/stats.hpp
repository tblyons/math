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
#ifndef TBL_MATH_STATS_HPP
#define TBL_MATH_STATS_HPP

#include <limits>

namespace math {

struct stats {

   stats()
      : m_count(0)
      , m_mean(0.0)
      , m_m_2(0.0)
      , m_max(std::numeric_limits<double>::lowest())
      , m_min(std::numeric_limits<double>::max()) { }

   void include(double x) {
      m_count += 1;
      double delta = x - m_mean;
      m_mean += delta / m_count;
      m_m_2 += delta * (x - m_mean);
      m_max = (m_max < x) ? x : m_max;
      m_min = (m_min > x) ? x : m_min;
   }

   double count() const {
      return m_count;
   }

   double mean() const {
      return m_mean;
   }

   double variance() const {
      return ((m_count < 2) ? std::numeric_limits<double>::quiet_NaN() : (m_m_2 / (m_count - 1)));
   }

   double maximum() const {
      return m_max;
   }

   double minimum() const {
      return m_min;
   }

private:
   std::size_t m_count;
   double m_mean;
   double m_m_2;
   double m_max;
   double m_min;
}; // struct stats

} // namespace math

#endif // TBL_MATH_STATS_HPP
