#pragma once

template <class Integer>
inline constexpr Integer floor_pow2(Integer x) {
  if (x <= 0) return 0;
  if constexpr (sizeof(Integer) > 4) {
    return Integer(1ull << (63 - __builtin_clzll(x)));
  } else {
    return Integer(1u << (31 - __builtin_clz(x)));
  }
}
