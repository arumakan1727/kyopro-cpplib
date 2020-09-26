#pragma once
#include <cstdint>
#include <iostream>

#include "../../Graph/graph-template.hpp"

/**
 * @brief readDirectedGraph() (有向グラフの入力)
 */
template <class T>
Graph<T> readDirectedGraph(size_t V, size_t E, int padding = -1, std::istream& is = std::cin) {
    Graph<T> G(V);
    for (size_t i = 0; i < E; ++i) {
        Edge<T> e;
        is >> e;
        e.from += padding, e.to += padding;
        e.id = static_cast<int>(i);
        G[e.from].emplace_back(e);
    }
    return G;
}

