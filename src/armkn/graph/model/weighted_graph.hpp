#pragma once
#include <cstdint>
#include <ostream>
#include <vector>

template <class Weight>
struct Edge {
  uint32_t to;
  Weight w;

  Edge() : to(0), w(0){};
  explicit Edge(uint32_t to_, Weight w_ = 1) : to(to_), w(w_) {}

  inline bool operator<(const Edge& rhs) const {
    return w < rhs.w;
  }
};

template <class Weight>
using WeightedGraph = std::vector<std::vector<Edge<Weight>>>;
