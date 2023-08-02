#pragma once
#include <cassert>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <vector>
#include "../../util/alias/stdint.hpp"

template <class Monoid, class OpFn>
class DoublingWithMonoid {
  OpFn op;
  std::vector<std::vector<std::pair<u32, Monoid>>> t;

 public:
  DoublingWithMonoid() = default;

  /// f[i] := iの遷移先;  g[i] := iがf[i]へ遷移するときの重み
  template <class UInt, std::enable_if_t<std::is_integral_v<UInt>, std::nullptr_t> = nullptr>
  DoublingWithMonoid(
      std::vector<UInt> const& f,
      std::vector<Monoid> const& g,
      OpFn&& op_,
      u32 log2_k = 62
  )
      : op(op_), t(log2_k) {
    assert(f.size() == g.size());
    const auto n = f.size();
    t[0].resize(n);
    for (u32 i = 0; i < n; ++i) {
      assert((u32)f[i] < n);
      t[0][i] = {(u32)f[i], g[i]};
    }

    for (u32 k = 0; k < t.size() - 1; ++k) {
      t[k + 1].resize(n);
      for (u32 i = 0; i < n; ++i) {
        const auto& [to1, acc1] = t[k][i];
        const auto& [to2, acc2] = t[k][to1];
        t[k + 1][i] = {to2, op(acc1, acc2)};
      }
    }
  }

  inline std::pair<u32, Monoid> apply_repeat(u32 x, Monoid const& init, u64 count) const {
    assert(count >> t.size() == 0);
    Monoid acc = init;
    for (u32 k = 0; count > 0; ++k) {
      if (count & 1) {
        const auto& [i, w] = t[k][x];
        x = i;
        acc = op(acc, w);
      }
      count >>= 1;
    }
    return {x, acc};
  }
};
