#pragma once
#include <vector>

/// Pascal's triangle; $(O^2)$
inline auto binom_table(int n) {
  std::vector<std::vector<int64_t>> c(n + 1);
  for (int i = 0; i <= n; ++i) {
    c[i].resize(i + 1);
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  return c;
}
