#pragma once
#include <cassert>
#include <type_traits>

template <class Integer, class = std::enable_if_t<std::is_integral_v<Integer>>>
constexpr Integer isqrt(Integer x) {
  assert(x >= 0);
  Integer q = 1;
  while (q <= x) q <<= 2;

  Integer r = 0;
  while (q > 1) {
    q >>= 2;
    Integer t = x - r - q;
    r >>= 1;
    if (t >= 0) {
      x = t;
      r += q;
    }
  }
  return r;
}
