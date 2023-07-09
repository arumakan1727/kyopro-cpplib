#pragma once
#include <cstdint>

/// nCk; $O(k)$
inline int64_t binom(int64_t n, int k) {
  if (k < 0 || n < k) return 0;
  if (k > n / 2) k = n - k;
  int64_t numer = 1, denom = 1;
  while (k) {
    numer *= n--;
    denom *= k--;
  }
  return numer / denom;
}
