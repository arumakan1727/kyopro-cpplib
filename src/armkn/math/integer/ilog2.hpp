#pragma once
#include <cassert>

template <class Integer>
inline constexpr unsigned ilog2(Integer n) {
  if (n <= 1) return 0;
  unsigned k = 1;
  while (n > 1) n >>= 1, ++k;
  return k - 1;
}