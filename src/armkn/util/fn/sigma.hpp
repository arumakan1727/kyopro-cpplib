#pragma once
#include <cstddef>
#include <type_traits>
#include "../alias/stdint.hpp"

inline i64 sigma(i64 a, i64 b) {
  return (a + b) * (b - a + 1) >> 1;
}

template <
    typename T,
    std::enable_if_t<!std::is_integral_v<T> || sizeof(i64) < sizeof(T), std::nullptr_t> = nullptr>
inline T sigma(T a, T b) {
  return (a + b) * (b - a + 1) / 2;
}
