#pragma once
#include <algorithm>
#include <cassert>
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
  inline const T sum(int i) const {
    assert(0 <= i && i < (int)data.size());
    return data[i];
  }

  /// [l, r)
  inline const T sum(int l, int r) const {
    assert(0 <= l && l <= r && r < (int)data.size());
    return data[r] - data[l];
  }

  /// `sum(l, r) >= v` となる最小の r を求める
  inline std::size_t lower_bound(const T& v, int l) const {
    assert(0 <= l && l < (int)data.size());
    return std::distance(data.begin(), std::lower_bound(data.begin(), data.end(), v + data[l]));
  }
};
