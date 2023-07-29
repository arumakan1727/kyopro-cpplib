#pragma once
#include <utility>
#include "../alias/stdint.hpp"

/// m の (top, left) を左上として pat の全マスとマッチするかチェックする。
///
/// 厳密には `f(top + i, left + j, i, j) (0 <= i < pat.size(), 0 <= j < pat[i].size())`
/// が全て true になるか判定する。
/// f の型は `(u32, u32, u32, u32) -> bool` を期待する。
template <class Matrix, class PatternMatrix, class MatcherFn>
bool match_2d(const Matrix& m, const PatternMatrix& pat, u32 top, u32 left, MatcherFn&& f) {
  if (top < 0 || left < 0) return false;
  for (u32 i = 0; i < pat.size(); ++i) {
    for (u32 j = 0; j < pat[i].size(); ++j) {
      if (top + i >= m.size() || left + j >= m[top + i].size()) return false;
      if (!f(top + i, left + j, i, j)) return false;
    }
  }
  return true;
}

template <class Matrix, class PatternMatrix>
bool match_2d(const Matrix& m, const PatternMatrix& pat, u32 top, u32 left) {
  return match_2d(m, pat, top, left, [&](u32 r, u32 c, u32 i, u32 j) {
    return m[r][c] == pat[i][j];
  });
}

template <class Matrix, class PatternMatrix, class PatChar>
bool match_2d_with_special_char(
    const Matrix& m,
    const PatternMatrix& pat,
    u32 top,
    u32 left,
    PatChar&& anything_match_char
) {
  return match_2d(m, pat, top, left, [&](u32 r, u32 c, u32 i, u32 j) {
    return pat[i][j] == anything_match_char || m[r][c] == pat[i][j];
  });
}
