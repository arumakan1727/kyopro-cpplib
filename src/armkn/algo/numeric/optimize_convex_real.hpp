#pragma once
#include <cassert>
#include <cmath>
#include <cstddef>
#include <functional>
#include <type_traits>

/// 黄金比分割探索により凸関数の最小値を求める; `std::greater<>()` を渡せば最大化
template <
    class T,
    class Fn,
    class Comparator = std::less<>,
    std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
auto optimize_convex_real(T xl, T xu, T err, Fn const& f, Comparator&& less = Comparator{}) {
  assert(xl < xu);
  const T phi = (1 + std::sqrt(T(5))) / 2;
  auto iter = static_cast<unsigned int>((std::log(xu - xl) - std::log(err)) / std::log(phi)) + 5;
  T xml = (phi * xl + xu) / (1 + phi);
  T xmu = (xl + phi * xu) / (1 + phi);
  T yml = f(xml);
  T ymu = f(xmu);
  while (iter--) {
    if (less(yml, ymu)) {
      xu = xmu;
      xmu = xml;
      ymu = yml;
      xml = (phi * xl + xu) / (1 + phi);
      yml = f(xml);
    } else {
      xl = xml;
      xml = xmu;
      yml = ymu;
      xmu = (xl + phi * xu) / (1 + phi);
      ymu = f(xmu);
    }
  }
  return std::make_pair(xml, yml);
}
