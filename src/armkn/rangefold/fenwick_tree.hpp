#pragma once
#include <cassert>
#include <cstdint>
#include <vector>
#include <cstddef>
#include "../util/fn/floor_pow2.hpp"

template <class Abel>
class FenwickTree {
  std::vector<Abel> data;
  uint32_t n_floor_pow2;

 public:
  FenwickTree() : n_floor_pow2(0) {}

  explicit FenwickTree(size_t n) : data(n + 1), n_floor_pow2((uint32_t)floor_pow2(n)) {}

  template <class T>
  explicit FenwickTree(const std::vector<T>& a) : FenwickTree(a.size()) {
    for (unsigned i = 1; i < data.size(); ++i) {
      data[i] += a[i - 1];
      const auto k = i + (i & -i);
      if (k < data.size()) data[k] += data[i];
    }
  }

  /// 0-indexed
  void add(size_t i, const Abel& value) {
    ++i;
    assert(i < data.size());
    for (; i < data.size(); i += i & -i) data[i] += value;
  }

  /// 0-indexed
  void set(size_t i, const Abel& value) {
    add(i, value - (*this)[i]);
  }

  /// Ragne sum [0, i); 0-indexed
  const Abel sum(size_t i) const {
    assert(i < data.size());
    Abel acc{};
    while (i > 0) acc += data[i], i -= i & -i;
    return acc;
  }

  /// Range sum [l, r); 0-indexed
  const Abel sum(size_t l, size_t r) const {
    assert(l <= r);
    return sum(r) - sum(l);
  }

  const Abel operator[](size_t i) const {
    return sum(i + 1) - sum(i);
  }

  size_t size() const {
    return data.empty() ? 0 : data.size() - 1;
  }

  /// Returns leftmost `k` s.t. `sum(k) >= x`;
  /// If such `k` doesn't exists, returns `size() + 1`
  size_t lower_bound(Abel x) const {
    if (x == data[0] && data[1] >= 0) return 0;
    unsigned k = 0;
    for (unsigned w = n_floor_pow2; w > 0; w >>= 1) {
      if (k + w < data.size() && data[k + w] < x) {
        x -= data[k + w];
        k += w;
      }
    }
    return k + 1;
  }
};
