#pragma once

template <class Integer>
inline constexpr unsigned ilog2(Integer n) {
  if (n <= 1) return 0;
  if constexpr (sizeof(Integer) > 4) {
    return 63 - __builtin_clzll(n);
  } else {
    return 31 - __builtin_clz(n);
  }
}
