#pragma once
#include <vector>
#include "eratosthenes_sieve.hpp"

/// n 以下の素数を昇順で返す
auto prime_numbers(const int n) -> std::vector<int> {
  assert(n >= 0);
  auto p = eratosthenes_sieve(n + 2);
  std::vector<int> primes;
  primes.reserve((n >> 2) | 0b1111);
  if (n >= 2) primes.push_back(2);
  if (n >= 3) primes.push_back(3);
  for (int i = 6; i < n; i += 6) {
    if (p[i - 1]) primes.push_back(i - 1);
    if (p[i + 1]) primes.push_back(i + 1);
  }
  primes.shrink_to_fit();
  return primes;
}
