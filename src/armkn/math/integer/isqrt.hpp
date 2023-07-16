#pragma once
#include <cassert>
#include <type_traits>

template <class SignedInt>
constexpr SignedInt isqrt(SignedInt x) {
  static_assert(std::is_integral_v<SignedInt> && std::is_signed_v<SignedInt>,
                "Argument type must be signed integer!!!");
  assert(x >= 0);
  SignedInt q = 1;
  while (q <= x) q <<= 2;

  SignedInt r = 0;
  while (q > 1) {
    q >>= 2;
    SignedInt t = x - r - q;
    r >>= 1;
    if (t >= 0) {
      x = t;
      r += q;
    }
  }
  return r;
}
