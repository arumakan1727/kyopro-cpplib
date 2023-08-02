#pragma once
#include <array>
#include <cassert>
#include <vector>
#include "../../util/alias/stdint.hpp"

template <unsigned LOG2_K = 62>
class Doubling {
  std::array<std::vector<u32>, LOG2_K> t;

 public:
  Doubling() = default;

  template <class T>
  explicit Doubling(std::vector<T> const& f) {
    const auto n = f.size();
    t[0].resize(n);
    for (u32 i = 0; i < n; ++i) {
      assert((u32)f[i] < n);
      t[0][i] = f[i];
    }

    for (u32 k = 0; k < LOG2_K - 1; ++k) {
      t[k + 1].resize(n);
      for (u32 i = 0; i < n; ++i) t[k + 1][i] = t[k][t[k][i]];
    }
  }

  inline u32 apply_repeat(u32 x, u64 count) const {
    for (u32 k = 0; count > 0; ++k) {
      if (count & 1) x = t[k][x];
      count >>= 1;
    }
    return x;
  }
};
