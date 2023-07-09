#pragma once
#include <cassert>
#include <cstdint>
#include <vector>

/// B[k] = binomial(n, k) を O(k) で前計算して返す
template <class T>
std::vector<T> binom_table_const_n(int64_t n, int k) {
  assert(0 < n);
  assert(0 <= k && k <= n);
  const auto N = uint64_t(n);
  const auto K = uint32_t(k);
  std::vector<T> b(K + 1);
  b[0] = 1;
  for (uint32_t i = 1; i <= K; ++i) {
    b[i] = b[i - 1] * (N - i + 1) / i;
  }
  return b;
}
