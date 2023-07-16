#pragma once
#include <vector>
#include "eratosthenes_sieve.hpp"
#include "ilog2.hpp"

auto prime_numbers(const std::vector<bool>& sieve) -> std::vector<int> {
  if (sieve.size() <= 2) return {};
  auto n = sieve.size() - 1;
  std::vector<int> primes;
  primes.reserve((n / ilog2(n)) * 7 >> 2);
  if (n >= 2) primes.push_back(2);
  for (unsigned i = 3; i <= n; i += 2) {
    if (sieve[i]) primes.push_back(i);
  }
  primes.shrink_to_fit();
  return primes;
}

/// n 以下の素数を昇順で返す
auto prime_numbers(const unsigned n) -> std::vector<int> {
  if (n < 2) return {};
  auto sieve = eratosthenes_sieve(n);
  return prime_numbers(sieve);
}
