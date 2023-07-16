#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

template <class ModInt>
class Factorials {
  inline static std::vector<ModInt> _fac, _finv;

 public:
  using value_type = ModInt;

  explicit Factorials(int precalc_num = 5000) {
    _fac.reserve(std::max(precalc_num, 2'000'010));
    _finv.reserve(std::max(precalc_num, 2'000'010));
    if (_fac.empty()) {
      _fac.push_back(1);
      _fac.push_back(1);
      _finv.push_back(1);
      _finv.push_back(1);
    }
    pre_calc(precalc_num);
  }

  inline static void pre_calc(uint32_t n) {
    if (n < _fac.size()) return;

    const auto l = (uint32_t)_fac.size(), r = n + 1;
    _fac.resize(r, value_type(1));
    _finv.resize(r, value_type(1));

    for (uint32_t i = l; i < r; ++i) _fac[i] = _fac[i - 1] * i;

    _finv[r - 1] = value_type(1) / _fac[r - 1];
    for (uint32_t i = r - 1; i > l; --i) _finv[i - 1] = _finv[i] * i;
  }

  inline static size_t size() {
    return _fac.size();
  }
  inline static size_t capacity() {
    return _fac.capacity();
  }

  inline static const value_type fac(int i) {
    assert(i >= 0);
    return pre_calc(i), _fac[i];
  }
  inline static const value_type finv(int i) {
    assert(i >= 0);
    return pre_calc(i), _finv[i];
  }
  inline static const value_type C(int n, int k) {
    if (k < 0 || n < k) return value_type(0);
    return pre_calc(n), _fac[n] * _finv[k] * _finv[n - k];
  }
  inline static const value_type P(int n, int k) {
    if (k < 0 || n < k) return value_type(0);
    return pre_calc(n), _fac[n] * _finv[n - k];
  }
  inline static const value_type H(int n, int k) {
    if (n < 0 || k < 0) return value_type(0);
    return k == 0 ? value_type(1) : C(n + k - 1, k);
  }
};
