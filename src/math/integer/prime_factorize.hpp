#pragma once
#include <map>

template <class Integer>
std::map<Integer, int> prime_factorize(Integer n) {
  assert(n > 0);
  std::map<Integer, int> res;
  for (Integer i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}
