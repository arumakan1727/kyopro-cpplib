#pragma once
#include <cstdint>
#include <vector>

/// リュカの定理に基づいて nCk % MOD を計算する; MODが小さい場合に有効
///   - 前計算: O(MOD^2)
///   - nCk:    O(log n)
class LucasBinomial {
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;
  std::vector<std::vector<uint32_t>> c;

 public:
  const uint32_t MOD;

  explicit LucasBinomial(u32 mod) : MOD(mod) {
    c[0][0] = 1;
    for (u32 i = 1; i < MOD; ++i) {
      c[i][0] = c[i][i] = 1;
      for (u32 j = 1; j < i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  uint32_t C(const int64_t n_, const int64_t k_) const {
    if (n_ < 0 || n_ < k_) return 0;
    u64 n(n_), k(k_), ret(1);
    while (n > 0) {
      (ret *= c[n % MOD][k % MOD]) %= MOD;
      n /= MOD, k /= MOD;
    }
    return (uint32_t)ret;
  }
};
