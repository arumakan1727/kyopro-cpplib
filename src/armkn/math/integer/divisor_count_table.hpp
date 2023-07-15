#pragma once
#include <vector>

/// Calc array `A` s.t. `A[i]` = `num of divisors of i` (0 <= i <= n); $O(n \log n)$
inline std::vector<int> divisor_count_table(int n_) {
  auto n = unsigned(n_);
  std::vector<int> a(n + 1);
  for (unsigned d = 1; d <= n; ++d) {
    for (unsigned i = d; i <= n; i += d) ++a[i];
  }
  return a;
}
