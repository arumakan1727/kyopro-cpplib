#pragma once
#include <algorithm>
#include <vector>

class UnionFind {
  struct Node {
    uint32_t parent, size;
  };
  mutable std::vector<Node> t;

 public:
  UnionFind() = default;

  explicit UnionFind(size_t n) : t(n) {
    for (uint32_t i = 0; i < n; ++i) t[i] = {i, 1};
  }

  inline uint32_t size() const {
    return t.size();
  }
  inline uint32_t size(uint32_t i) const {
    assert(i < t.size());
    return t[root(i)].size;
  }
  inline bool is_same(uint32_t a, uint32_t b) const {
    return root(a) == root(b);
  }

  inline uint32_t root(uint32_t i) const {
    assert(i < t.size());
    while (i != t[i].parent) i = t[i].parent = t[t[i].parent].parent;
    return i;
  }

  /// Calls fn(parent, child) after unite
  template <class Func>
  bool unite(uint32_t a, uint32_t b, Func&& fn) {
    if ((a = root(a)) == (b = root(b))) return false;
    if (t[a].size < t[b].size) std::swap(a, b);
    t[a].size += t[b].size;
    t[b].parent = (uint32_t)a;
    fn(a, b);
    return true;
  }

  /// return true if only and if a and b was united
  inline bool unite(uint32_t a, uint32_t b) {
    return unite(a, b, [](auto, auto) {});
  }

  auto groups() const -> std::vector<std::vector<uint32_t>> {
    const auto n = size();
    using uvec = std::vector<uint32_t>;
    uvec roots(n), group_size(n);
    for (uint32_t i = 0; i < n; ++i) ++group_size[roots[i] = root(i)];

    std::vector<uvec> res(n);
    for (uint32_t i = 0; i < n; ++i) res[i].reserve(group_size[i]);
    for (uint32_t i = 0; i < n; ++i) res[roots[i]].push_back(i);
    res.erase(remove_if(res.begin(), res.end(), &uvec::empty), res.end());
    return res;
  }
};
