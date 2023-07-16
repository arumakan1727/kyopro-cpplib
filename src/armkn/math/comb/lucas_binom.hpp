#pragma once
#include <cassert>
#include <cstdint>
#include <vector>
#include "../../util/alias/i32_i64.hpp"
#include "../../util/alias/u32_u64.hpp"
#include "../integer/is_prime.hpp"

/// リュカの定理に基づいて nCk % MOD を計算する; MODが小さい素数の場合に有効
///   - 前計算: O(MOD^2)
///   - nCk:    O(log n)
class LucasBinomial {
  std::vector<std::vector<u32>> c;

 public:
  const u32 MOD;

  explicit LucasBinomial(u32 mod) : c(mod, std::vector<u32>(mod)), MOD(mod) {
    assert(mod < 100000);
    assert(is_prime(mod));
    c[0][0] = 1;
    for (u32 i = 1; i < MOD; ++i) {
      c[i].resize(MOD);
      c[i][0] = c[i][i] = 1;
      for (u32 j = 1; j < i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  u32 C(const i64 n_, const i64 k_) const {
    if (k_ < 0 || n_ < k_) return 0;
    u64 n(n_), k(k_), ret(1);
    while (n > 0) {
      (ret *= c[n % MOD][k % MOD]) %= MOD;
      n /= MOD, k /= MOD;
    }
    return (u32)ret;
  }
};
