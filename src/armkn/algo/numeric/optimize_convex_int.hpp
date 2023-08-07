#pragma once
#include <cassert>
#include <cstddef>
#include <functional>
#include <type_traits>
#include <utility>

/// 凸関数の最小値を求める; `std::greater<>()` を渡せば最大化
/// # 事前条件
/// - `xl <= xu`
/// - `f`: `Int -> T` (定義域は整数, 値域は実数でもOK)
/// # 戻り値
/// - `x` := `argmin f(x)` として  `pair{x, f(x)}`
/// - `x` の範囲は半開区間 `[xl, xu)`
template <
    class Int,
    class Fn,
    class Comparator = std::less<>,
    std::enable_if_t<std::is_integral_v<Int>, std::nullptr_t> = nullptr>
auto optimize_convex_int(Int xl, Int xu, Fn const& f, Comparator&& less = Comparator{}) {
  assert(xl <= xu);
  while (xu - xl > 1) {
    const Int mid = xl + ((xu - xl) >> 1);
    (less(f(mid - 1), f(mid)) ? xu : xl) = mid;
  }
  return std::make_pair(xl, f(xl));
}
