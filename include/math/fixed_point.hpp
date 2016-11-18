#ifndef MATH_FIXEDPOINT_HPP
#define MATH_FIXEDPOINT_HPP

#include <cstdint>

namespace math {

inline constexpr int64_t pow10(uint32_t exponent) {
   return (exponent == 0) ? 1 : (10 * pow10(exponent - 1));
}

template <uint32_t DECIMAL_PLACES>
struct fixed_point_t {

   static constexpr uint64_t exponent = pow10(DECIMAL_PLACES);

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

   int64_t significand() const {
      return m_value;
   }

private:
   int64_t m_value;
}; // struct fixed_point_t

} // namespace math

#endif // MATH_FIXEDPOINT_HPP
