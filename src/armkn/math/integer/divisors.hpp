#pragma once
#include <cassert>
#include <type_traits>
#include <vector>
#include "../../util/fn/isqrt.hpp"

/// Calc sorted divisors of `n`; $O(\sqrt(N))$
template <class Integer>
std::vector<Integer> divisors(Integer n) {
  assert(n >= 0);
  if (n == 0) return {};
  using UInt = std::make_unsigned_t<Integer>;
  using SInt = std::make_signed_t<Integer>;
  const UInt sqrt_n = isqrt((SInt)n);
  std::vector<Integer> res1, res2;
  res1.reserve(sqrt_n * 2), res2.reserve(sqrt_n);
  UInt i;
  for (i = 1; i <= sqrt_n; ++i) {
    if (n % i == 0) res1.push_back(i), res2.push_back(n / i);
  }
  if (--i, i * i == UInt(n)) res1.pop_back();
  std::move(res2.rbegin(), res2.rend(), std::back_inserter(res1));
  res1.shrink_to_fit();
  return res1;
}
