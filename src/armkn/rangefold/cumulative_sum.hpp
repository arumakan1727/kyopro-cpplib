#pragma once
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>

template <class T>
struct CumulativeSum {
  std::vector<T> data;

  CumulativeSum() = default;

  template <class Container>
  explicit CumulativeSum(const Container& a) : CumulativeSum(a.begin(), a.end()) {}

  template <class InputItr>
  CumulativeSum(InputItr begin, InputItr end) : data(std::distance(begin, end) + 1) {
    for (unsigned i = 0; begin != end; ++i, ++begin) data[i + 1] = data[i] + *begin;
  }

  /// [0, i)
  inline const T sum(size_t i) const {
    assert(i < data.size());
    return data[i];
  }

  /// [l, r)
  inline const T sum(size_t l, size_t r) const {
    assert(l <= r && r < data.size());
    return data[r] - data[l];
  }

  /// `sum(l, r) >= v` となる最小の r を求める
  inline size_t lower_bound(const T& v, size_t l) const {
    assert(l < data.size());
    return std::distance(data.begin(), std::lower_bound(data.begin(), data.end(), v + data[l]));
  }
};
