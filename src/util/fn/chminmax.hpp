#pragma once

template <class T, class U>
inline bool chmin(T& self, const U& x) {
  return x < self ? (self = x, true) : false;
}

template <class T, class U>
inline bool chmax(T& self, const U& x) {
  return x > self ? (self = x, true) : false;
}
