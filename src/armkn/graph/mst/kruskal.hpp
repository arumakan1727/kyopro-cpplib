#pragma once
#include <algorithm>
#include <cstddef>
#include <numeric>
#include <vector>
#include "../../dsu/union_find.hpp"
#include "../../util/macro/iter_all.hpp"
#include "../model/Edge3.hpp"

/// 最小全域木として辺 e が採用されるときに hook(e) を呼び出す
template <class CostSum, class Cost, class Func>
CostSum kruskal(size_t num_nodes, std::vector<Edge3<Cost>>& edges_mut, Func&& hook) {
  std::sort(ALL(edges_mut));
  UnionFind uf(num_nodes);
  CostSum sum{};
  for (const auto& e : edges_mut) {
    if (uf.unite(e.from, e.to)) {
      sum += e.w;
      hook(e);
    }
  }
  return sum;
}

template <class CostSum, class Cost>
inline CostSum kruskal(size_t num_nodes, std::vector<Edge3<Cost>>& edges_mut) {
  return kruskal<CostSum>(num_nodes, edges_mut, [](const auto&) {});
}
