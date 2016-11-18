#ifndef MATH_FIXEDPOINT_HPP
#define MATH_FIXEDPOINT_HPP

#include "math/pow10.hpp"

#include <cstdint>

namespace math {

template <uint32_t DECIMAL_PLACES>
struct fixed_point_t {

   static constexpr uint32_t decimal_places = DECIMAL_PLACES;
   static constexpr uint64_t exponent = pow10(decimal_places);

   constexpr fixed_point_t()
      : m_value() {}

   explicit constexpr fixed_point_t(double value)
      : m_value(static_cast<int64_t>(value * exponent)) {}

   constexpr fixed_point_t& operator+=(const fixed_point_t& other) {
      m_value += other.m_value;
      return *this;
   }

   constexpr fixed_point_t& operator-=(const fixed_point_t& other) {
      m_value -= other.m_value;
      return *this;
   }

   constexpr int64_t whole_number() const {
      return m_value / exponent;
   }

   int64_t& significand() {
      return m_value;
   }

   constexpr int64_t significand() const {
      return m_value;
   }

   struct rational_t {

      constexpr rational_t(int64_t numerator, uint64_t denominator)
         : m_numerator(numerator)
         , m_denominator(denominator) {}

      int64_t m_numerator;
      uint64_t m_denominator;
   };

   constexpr rational_t fraction() const {
      return rational_t(m_value % exponent, exponent);
   }

private:
   int64_t m_value;
}; // struct fixed_point_t

} // namespace math

#endif // MATH_FIXEDPOINT_HPP
