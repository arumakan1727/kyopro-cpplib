#pragma once
#include <cassert>
#include <cstdint>
#include <vector>

template <class T>
struct CumulativeSum2D {
  std::vector<std::vector<T>> data;

  CumulativeSum2D() = default;

  template <class U>
  explicit CumulativeSum2D(std::vector<std::vector<U>> const& a)
      : data(a.size() + 1, std::vector<T>(a.empty() ? 0 : a.front().size() + 1)) {
    for (unsigned i = 1; i < data.size(); ++i) {
      for (unsigned j = 1; j < data[i].size(); ++j) {
        data[i][j] = a[i - 1][j - 1] + data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  /// Returns sum(a[y][x]) for y ∈ [sy, gy), x ∈ [sx, gx)
  /// 0 <= sy <= gy <= H;  0 <= sx <= gx <= W;
  inline const T sum(unsigned sy, unsigned sx, unsigned gy, unsigned gx) const noexcept {
    assert(sy <= gy && gy <= data.size());
    assert(sx <= gx && gx <= data[0].size());
    return data[gy][gx] - data[sy][gx] - data[gy][sx] + data[sy][sx];
  }
};
