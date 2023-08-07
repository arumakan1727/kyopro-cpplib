#pragma once
#include <ostream>
#include <utility>

template <class T1, class T2>
std::ostream& operator<<(std::ostream& o, const std::pair<T1, T2>& p) {
  return o << '(' << p.first << ", " << p.second << ')';
}
