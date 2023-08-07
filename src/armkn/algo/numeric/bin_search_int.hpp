#pragma once
#include <cstddef>
#include <iostream>
#include <type_traits>
#include <utility>

/// `p(ok)` を満たし、かつ `ng_` に最も近い `ok` を二分探索で求める。
/// - 戻り値の値域は `min(ok_,ng_) - 1  <=  ok <= max(ok_,ng_) + 1`
/// - `p(x) == true`  (`∀x ∈ [ok_, ng_]`) ならば `ng_` を返す。
/// - `p(x) == false` (`∀x ∈ [ok_, ng_]`) ならば `[ok_, ng_]` の範囲外で `ok_` に最も近い値を返す。
template <
    class Int,
    class PredicateFn,
    class SignedInt = std::make_signed_t<Int>,
    std::enable_if_t<std::is_integral_v<Int>, std::nullptr_t> = nullptr>
SignedInt bin_search_int(const Int ok_, const Int ng_, PredicateFn&& p) {
  SignedInt ng, ok;
  if (ng_ < ok_) {
    ng = ng_ - 1;
    ok = ok_ + 1;
    while (ok - ng > 1) {
      auto mid = ng + ((ok - ng) >> 1);
      (p((Int)mid) ? ok : ng) = mid;
    }
  } else {
    ng = ng_ + 1;
    ok = ok_ - 1;
    while (ng - ok > 1) {
      auto mid = ok + ((ng - ok) >> 1);
      (p((Int)mid) ? ok : ng) = mid;
    }
  }

#ifdef ARMKN_DEBUG
  if (ng == (SignedInt)ok_) {
    std::clog << "\x1b[31;1m[Warn] ALL p(x) made FALSE\x1b[;m";
    std::clog << "  initial range: (ok_,ng_)=(" << ok_ << ", " << ng_ << ") / result: (ok,ng)=("
              << ok << ", " << ng << ')' << std::endl;
  }
#endif
  return ok;
}
