#include <cstdint>

inline constexpr uint64_t pow10(uint32_t exponent) {
   return (exponent == 0) ? 1 : (10ULL * pow10(exponent - 1));
}

template <uint32_t DECIMAL_PLACES>
struct fixed_point_t {

   static constexpr uint64_t exponent = pow10(DECIMAL_PLACES);

   constexpr fixed_point_t()
      : m_value() {}

   constexpr fixed_point_t(double value)
      : m_value(value * exponent) {}

   fixed_point_t& operator+=(const fixed_point_t& other) {
      m_value += other.m_value;
      return *this;
   }

   fixed_point_t& operator-=(const fixed_point_t& other) {
      m_value -= other.m_value;
      return *this;
   }

   int64_t whole_number() const {
      return m_value / exponent;
   }


private:
   int64_t m_value;
}; // struct fixed_point_t
