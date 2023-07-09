#pragma once
#include <cstdint>
#include <vector>
using namespace std;

/**
 * リュカの定理に基づいて nCk % MOD を計算する; MODが小さい場合に有効
 *   - 前計算: O(MOD^2)
 *   - nCk:    O(log n)
 */
class LucasBinomial {
  const uint32_t MOD;
  std::vector<std::vector<uint32_t>> c;

 public:
  explicit LucasBinomial(uint32_t mod) : MOD(mod) {
    c[0][0] = 1;
    for (uint32_t i = 1; i < MOD; ++i) {
      c[i][0] = c[i][i] = 1;
      for (uint32_t j = 1; j < i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  uint32_t C(int64_t n_, int64_t k_) {
    if (n_ < 0 || n_ < k_) return 0;
    auto n = uint64_t(n_);
    auto k = uint64_t(k_);
    uint64_t ret = 1;
    while (n > 0) {
      (ret *= c[n % MOD][k % MOD]) %= MOD;
      n /= MOD, k /= MOD;
    }
    return ret;
  }
};
