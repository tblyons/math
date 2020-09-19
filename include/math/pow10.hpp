// License: The Unlicense (https://unlicense.org)
#ifndef MATH_POW10_HPP
#define MATH_POW10_HPP

#include <cstdint>

namespace math {

inline constexpr int64_t pow10(uint32_t exponent) {
   return (exponent == 0) ? 1 : (10 * pow10(exponent - 1));
}

} // namespace math

#endif // MATH_POW10_HPP
