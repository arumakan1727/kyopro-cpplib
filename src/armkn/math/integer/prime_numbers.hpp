#pragma once
#include <cassert>
#include <vector>
#include "eratosthenes_sieve.hpp"

/// n 以下の素数を昇順で返す
auto prime_numbers(const int n) -> std::vector<int> {
  assert(n >= 0);
  if (n < 2) return {};
  auto p = eratosthenes_sieve(n);
  std::vector<int> primes;
  primes.reserve((n >> 2) | 0b1111);
  if (n >= 2) primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (p[i]) primes.push_back(i);
  }
  primes.shrink_to_fit();
  return primes;
}
