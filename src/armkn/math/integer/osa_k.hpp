#pragma once
#include <cassert>
#include <map>
#include <numeric>
#include <vector>

class OsaK {
 private:
  std::vector<int> _min_factor;

 public:
  OsaK() = default;

  /// [0, n] の範囲で篩を構築
  explicit OsaK(int n) : _min_factor(n + 1) {
    iota(std::begin(_min_factor), std::end(_min_factor), 0);
    for (int i = 4; i <= n; i += 2) _min_factor[i] = 2;
    for (int i = 3; i * i <= n; i += 2) {
      if (_min_factor[i] != i) continue;
      for (int k = i * i; k <= n; k += i + i) {
        if (_min_factor[k] == k) _min_factor[k] = i;
      }
    }
  }

  bool is_prime(int i) const {
    assert(i < (int)_min_factor.size());
    return i > 1 && _min_factor[i] == i;
  }

  auto min_factor(int i) const {
    assert(0 <= i && i < (int)_min_factor.size());
    return _min_factor[i];
  }

  /// map<素因数, 指数>
  auto prime_factorize(int n) const {
    assert(0 <= n && n < (int)_min_factor.size());
    std::map<int, int> ret;
    while (n > 1) {
      ++ret[_min_factor[n]];
      n /= _min_factor[n];
    }
    return ret;
  }
};
