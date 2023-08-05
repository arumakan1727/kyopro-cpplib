#pragma once
#include <cassert>
#include <iterator>

template <class Iterable1, class Iterable2>
inline int hamming_distance(Iterable1 const& xs, Iterable2 const& ys) {
  assert(xs.size() == ys.size());
  auto it1 = std::begin(xs);
  auto it2 = std::begin(ys);
  const auto end = std::end(xs);
  int d = 0;
  while (it1 != end) {
    d += (*it1++ != *it2++);
  }
  return d;
}
