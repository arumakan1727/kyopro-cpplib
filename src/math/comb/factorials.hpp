#pragma once
#include <cassert>
#include <cstdint>
#include <vector>

template <class ModInt>
class Factorials {
 public:
  using value_type = ModInt;

 private:
  inline static std::vector<value_type> _fac, _finv;

  inline static void grow(size_t n) {
    if (n < _fac.size()) return;

    const uint32_t l = _fac.size(), r = n + 1;
    _fac.resize(r, value_type(1));
    _finv.resize(r, value_type(1));

    for (uint32_t i = l; i < r; ++i) _fac[i] = _fac[i - 1] * i;

    _finv[r - 1] = value_type(1) / _fac[r - 1];
    for (uint32_t i = r - 1; i > l; --i) _finv[i - 1] = _finv[i] * i;
  }

 public:
  explicit Factorials(int precalc_num = 5'000'00) {
    _fac.reserve(2'000'010);
    _finv.reserve(2'000'010);
    _fac.push_back(1);
    _fac.push_back(1);
    _finv.push_back(1);
    _finv.push_back(1);
    grow(precalc_num);
  }

  inline static const value_type fac(int i) {
    assert(i >= 0);
    return grow(i), _fac[i];
  }
  inline static const value_type finv(int i) {
    assert(i >= 0);
    return grow(i), _finv[i];
  }

  inline static const value_type C(int n, int k) {
    if (k < 0 || n < k) return value_type(0);
    return grow(n), _fac[n] * _finv[k] * _finv[n - k];
  }
  inline static const value_type P(int n, int k) {
    if (k < 0 || n < k) return value_type(0);
    return grow(n), _fac[n] * _finv[n - k];
  }
  inline static const value_type H(int n, int k) {
    if (n < 0 || k < 0) return value_type(0);
    return k == 0 ? value_type(1) : C(n + k - 1, k);
  }
};
