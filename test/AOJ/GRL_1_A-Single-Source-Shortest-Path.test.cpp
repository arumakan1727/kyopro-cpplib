#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"

#include <iostream>
#include <vector>

#include "../../Graph/graph-template.hpp"
#include "../../Graph/Shortest-Path/dijkstra.hpp"
#include "../../Util/IO/read-directed-graph.hpp"

#include "../../Util/int-alias.hpp"
#include "../../Util/int-infinity.hpp"
#include "../../Util/IO/println.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int V, E, r;
    std::cin >> V >> E >> r;

    auto G = readDirectedGraph<int>(V, E, 0);

    std::vector<i64> dist(V, LINF);
    dijkstra(dist, r, [&](int v, auto push) {
        for (Edge e : G[v]) {
            push(e.to, e.weight);
        }
    });

    for (const auto d : dist) {
        if (d >= LINF) {
            println("INF");
        } else {
            println(d);
        }
    }

    return 0;
}
