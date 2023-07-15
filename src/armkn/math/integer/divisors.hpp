#pragma once
#include <vector>
#include "isqrt.hpp"

/// Calc sorted divisors of `n`; $O(\sqrt(N))$
template <class T>
std::vector<T> divisors(T n) {
  const auto sqrt_n = isqrt(uint32_t(n));
  std::vector<T> res1, res2;
  res1.reserve(sqrt_n * 2), res2.reserve(sqrt_n);
  T i;
  for (i = 1; i < sqrt_n; ++i) {
    if (n % i == 0) res1.push_back(i), res2.push_back(n / i);
  }
  if (i * i == n) res1.push_back(i);
  std::move(res2.rbegin(), res2.rend(), std::back_inserter(res1));
  res1.shrink_to_fit();
  return res1;
}
