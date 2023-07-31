#pragma once
#include <vector>

/// dp[k][i] := a[0..<i] の中から k 要素 a[i_1], ..., a[i_k] 選ぶ全ての組合せ (i_1 < ... < i_k)
/// についての、 その総積 a[i_1] * ... * a[i_k] の総和。
///
/// dp[][] のサイズは (m + 1, a.size() + 1) 。
/// dp[0] は全要素ゼロ。
/// dp[1] は累積和配列に等しい。
template <class ProdSumT, class T>
auto k_choose_prod_sum(std::vector<T> const& a, unsigned const m)
    -> std::vector<std::vector<ProdSumT>> {
  const auto n = a.size();
  auto dp = std::vector(m + 1, std::vector(n + 1, ProdSumT(0)));

  for (unsigned i = 0; i < n; ++i) {
    dp[1][i + 1] = dp[1][i] + a[i];
  }

  for (unsigned k = 2; k <= m; ++k) {
    for (unsigned i = 1; i <= n; ++i) {
      dp[k][i] = dp[k][i - 1] + (dp[k - 1][i - 1] * a[i - 1]);
    }
  }

  return dp;
}
