#pragma once
#include "../alias/stdint.hpp"

inline i64 sigma(i64 a, i64 b) {
  return (a + b) * (b - a + 1) >> 1;
}
