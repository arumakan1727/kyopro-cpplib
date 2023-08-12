#pragma once
#include <cmath>
#include <type_traits>

template <class T>
inline T diff(T a, T b) {
  using S = std::make_signed_t<T>;
  return std::abs((S)a - (S)b);
}
