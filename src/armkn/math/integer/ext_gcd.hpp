#pragma once
#include <cstdint>
#include <utility>

/// ax + by = gcd(a, b) の解を引数 x, y に格納する。 戻り値は gcd(a, b)。
int64_t ext_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    auto g = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
  }
}

/// ax + by = gcd(a, b) の解 (x, y) をペアで返す。
inline auto ext_gcd(int64_t a, int64_t b) -> std::pair<int64_t, int64_t> {
  int64_t x, y;
  ext_gcd(a, b, x, y);
  return {x, y};
}
