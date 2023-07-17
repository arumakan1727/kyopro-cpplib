#pragma once
#include <type_traits>

template <class Integer>
inline constexpr Integer floor_pow2(Integer x_) {
  if (x_ <= 0) return 0;
  std::make_unsigned_t<Integer> x(x_), y{1};
  if (sizeof(Integer) > 4 && (y << 32) <= x) y <<= 32;
  if (sizeof(Integer) > 2 && (y << 16) <= x) y <<= 16;
  if (sizeof(Integer) > 1 && (y << 8) <= x) y <<= 8;
  if ((y << 4) <= x) y <<= 4;
  if ((y << 2) <= x) y <<= 2;
  if ((y << 1) <= x) y <<= 1;
  return y;
}
