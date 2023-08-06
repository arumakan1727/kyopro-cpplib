#pragma once
#include <iterator>
#include <utility>
#include <vector>

template <class Iter, class Elem = typename std::iterator_traits<Iter>::value_type>
auto runlength(Iter const begin, Iter const end) -> std::vector<std::pair<Elem, int>> {
  std::vector<std::pair<Elem, int>> ret;
  ret.reserve(std::distance(begin, end));

  for (auto itr = begin; itr != end;) {
    unsigned cnt = 1;
    const auto value = *itr++;
    while (itr != end && *itr == value) ++itr, ++cnt;
    ret.emplace_back(value, cnt);
  }
  ret.shrink_to_fit();
  return ret;
}
