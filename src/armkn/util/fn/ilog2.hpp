#pragma once
#include <type_traits>

template <class Integer>
inline constexpr unsigned ilog2(Integer n_) {
  if (n_ <= 1) return 0;
  unsigned k = 0;
  std::make_unsigned_t<Integer> n(n_), one{1};
  if (sizeof(Integer) > 4 && (one << (k + 32)) <= n) k += 32;
  if (sizeof(Integer) > 2 && (one << (k + 16)) <= n) k += 16;
  if (sizeof(Integer) > 1 && (one << (k + 8)) <= n) k += 8;
  if ((one << (k + 4)) <= n) k += 4;
  if ((one << (k + 2)) <= n) k += 2;
  if ((one << (k + 1)) <= n) k += 1;
  return k;
}
