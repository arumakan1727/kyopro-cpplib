#pragma once
#include <vector>
#include "eratosthenes_sieve.hpp"
#include "ilog2.hpp"

/// n 以下の素数を昇順で返す
auto prime_numbers(const unsigned n) -> std::vector<int> {
  if (n < 2) return {};
  auto p = eratosthenes_sieve(n);
  std::vector<int> primes;
  primes.reserve((n / ilog2(n)) * 7 >> 2);
  if (n >= 2) primes.push_back(2);
  for (unsigned i = 3; i <= n; i += 2) {
    if (p[i]) primes.push_back(i);
  }
  primes.shrink_to_fit();
  return primes;
}
