#pragma once
#include <iterator>
#include <utility>
#include <vector>

template <class Iter>
auto runlength(Iter const begin, Iter const end) -> std::vector<std::pair<Iter, int>> {
  std::vector<std::pair<Iter, int>> ret;
  ret.reserve(std::distance(begin, end));

  for (auto itr = begin; itr != end;) {
    unsigned cnt = 1;
    const auto head = itr++;
    while (itr != end && *itr == *head) ++itr, ++cnt;
    ret.emplace_back(head, cnt);
  }
  ret.shrink_to_fit();
  return ret;
}
