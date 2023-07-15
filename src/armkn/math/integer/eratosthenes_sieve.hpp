#pragma once
#include <cassert>
#include <vector>

inline std::vector<bool> eratosthenes_sieve(int n) {
  assert(n >= 0);
  std::vector<bool> p(n + 1, false);
  if (n >= 2) p[2] = true;
  for (int i = 3; i <= n; i += 2) p[i] = true;
  for (int i = 3; i * i <= n; i += 2) {
    if (!p[i]) continue;
    for (int k = i * i; k <= n; k += i + i) p[k] = false;
  }
  return p;
}
