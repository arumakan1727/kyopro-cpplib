#pragma once
#include <cstddef>
#include <vector>

template <class T>
class PowArray {
  std::vector<T> _a;
  T _base;

 public:
  PowArray() = default;

  inline explicit PowArray(T const& base) : _base(base) {
    _a.reserve(2'000'010);
    _a.push_back(T(1));
  }

  inline T const& operator[](size_t k) const noexcept {
    while (_a.size() <= k) _a.push_back(_a.back() * _base);
    return _a[k];
  }

  inline T const& base() const noexcept {
    return _base;
  }
};
