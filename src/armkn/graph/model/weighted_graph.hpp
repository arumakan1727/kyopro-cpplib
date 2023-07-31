#pragma once
#include <cstdint>
#include <ostream>
#include <vector>

template <class Weight>
struct Edge {
  uint32_t to;
  Weight w;

  inline Edge() : to(0), w(0){};

  inline explicit Edge(uint32_t to_, Weight w_) : to(to_), w(w_) {}

  inline explicit operator uint32_t() const {
    return to;
  }

  inline bool operator==(const Edge& rhs) const {
    return to == rhs.to && w == rhs.w;
  }

  inline bool operator<(const Edge& rhs) const {
    return w < rhs.w;
  }
};

template <class Weight>
using WeightedGraph = std::vector<std::vector<Edge<Weight>>>;
