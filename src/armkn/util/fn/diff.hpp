#pragma once
#include <cstdlib>

template <class T>
inline T diff(T a, T b) {
  return std::abs(b - a);
}
