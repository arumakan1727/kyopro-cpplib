#pragma once
#include "../alias/stdint.hpp"

inline i64 choose2(i64 n) {
  return n * (n - 1) >> 1;
}
