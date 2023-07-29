#pragma once
#include <cstdint>
#include <limits>
#include <queue>
#include <vector>
#include "../../util/alias/heapq.hpp"
#include "../../util/fn/chminmax.hpp"
#include "../model/weighted_graph.hpp"

template <class WeightSum, class EdgeWeight>
auto dijkstra(uint32_t start_node, WeightedGraph<EdgeWeight> const& g) -> std::vector<WeightSum> {
  const auto num_nodes = g.size();
  MinHeap<std::pair<WeightSum, uint32_t>> pq;
  std::vector<WeightSum> dist(num_nodes, std::numeric_limits<WeightSum>::max());

  pq.emplace(WeightSum{}, start_node);
  dist[start_node] = WeightSum{};

  while (pq.size()) {
    const auto [wsum, v] = pq.top();
    pq.pop();
    if (dist[v] < wsum) continue;
    for (const auto& e : g[v]) {
      if (chmin(dist[e.to], wsum + e.w)) {
        pq.emplace(wsum + e.w, e.to);
      }
    }
  }

  return dist;
}
