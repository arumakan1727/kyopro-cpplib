#pragma once
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../util/macro/iter_all.hpp"

class UnionFind {
  using u32 = uint32_t;
  struct Node {
    u32 parent, size;
  };
  mutable std::vector<Node> t;

 public:
  UnionFind() = default;

  explicit UnionFind(size_t n) : t(n) {
    for (u32 i = 0; i < n; ++i) t[i] = {i, 1};
  }

  inline size_t size() const {
    return t.size();
  }
  inline u32 size(u32 i) const {
    assert(i < t.size());
    return t[root(i)].size;
  }
  inline bool is_same(u32 a, u32 b) const {
    return root(a) == root(b);
  }

  inline u32 root(u32 i) const {
    assert(i < t.size());
    while (i != t[i].parent) i = t[i].parent = t[t[i].parent].parent;
    return i;
  }

  /// Calls hook(parent, child) after unite
  template <class Func>
  bool unite(u32 a, u32 b, Func&& hook) {
    if ((a = root(a)) == (b = root(b))) return false;
    if (t[a].size < t[b].size) std::swap(a, b);
    t[a].size += t[b].size;
    t[b].parent = (u32)a;
    hook(a, b);
    return true;
  }

  /// return true if only and if a and b was united
  inline bool unite(u32 a, u32 b) {
    return unite(a, b, [](u32, u32) {});
  }

  auto groups() const {
    using std::vector;
    const auto n = size();
    vector<u32> roots(n), group_size(n);
    for (u32 i = 0; i < n; ++i) ++group_size[roots[i] = root(i)];

    vector<vector<u32>> res(n);
    for (u32 i = 0; i < n; ++i) res[i].reserve(group_size[i]);
    for (u32 i = 0; i < n; ++i) res[roots[i]].push_back(i);
    res.erase(std::remove_if(ALL(res), [](auto&& v) { return v.empty(); }), res.end());
    return res;
  }
};
