#pragma once
#include <algorithm>
#include <vector>

#include "../graph-template.hpp"
#include "../../Data-Structure/Disjoint-Set/union-find.hpp"

/**
 * @brief kruskal() (クラスカル法)
 */
template <class ResultType, class WeightType>
ResultType kruskal(int V, std::vector<Edge<WeightType>>& edges) {
    ResultType weightSum{};
    UnionFind uf(V);
    std::sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
        return e1.weight < e2.weight;
    });
    for (const auto &e : edges) {
        if (uf.same(e.from, e.to)) continue;
        uf.unite(e.from, e.to);
        weightSum += e.weight;
    }
    return weightSum;
}
