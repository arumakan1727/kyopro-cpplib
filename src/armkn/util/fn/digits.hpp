#pragma once
#include <vector>
#include "../alias/stdint.hpp"

/// 実際の表記と順序が逆になるので注意;
/// `digits(123)` => `{3, 2, 1}`
template <u32 BASE = 10>
inline auto digits(u64 n) -> std::vector<int> {
  static_assert(BASE >= 2);
  if (n == 0) return {0};
  std::vector<int> d;
  d.reserve(64);
  while (n > 0) {
    d.push_back(n % BASE);
    n /= BASE;
  }
  d.shrink_to_fit();
  return d;
}
