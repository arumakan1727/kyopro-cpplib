#pragma once
#include <type_traits>
#include <vector>

/// 時計周りへの90度回転を `(cycle % 4)` 回繰り返した結果を返す。
/// `cycle` が負数の場合は反時計周りとみなす。
template <class Row>
std::vector<Row> rotate_matrix(const std::vector<Row>& m, int cycle) {
  using T = std::decay_t<decltype(m[0][0])>;
  const auto h = m.size();
  const auto w = m[0].size();
  ((cycle %= 4) += 4) %= 4;

  if (cycle == 1) {
    auto res = std::vector(w, Row(h, T{}));
    for (size_t y = 0; y < h; ++y) {
      for (size_t x = 0; x < w; ++x) res[x][h - y - 1] = m[y][x];
    }
    return res;
  }

  if (cycle == 2) {
    auto res = std::vector(h, Row(w, T{}));
    for (size_t y = 0; y < h; ++y) {
      for (size_t x = 0; x < w; ++x) res[h - y - 1][w - x - 1] = m[y][x];
    }
    return res;
  }

  if (cycle == 3) {
    auto res = std::vector(w, Row(h, T{}));
    for (auto& row : res) row.resize(h);
    for (size_t y = 0; y < h; ++y) {
      for (size_t x = 0; x < w; ++x) res[w - x - 1][y] = m[y][x];
    }
    return res;
  }

  return m;  // cycle == 0
}
