#pragma once

template <class T>
inline T divup(T a, T b) {
  return (a + b - 1) / b;
}
