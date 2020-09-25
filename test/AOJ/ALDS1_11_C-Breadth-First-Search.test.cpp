#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include <iostream>
#include <vector>

#include "../../Graph/graph-template.hpp"
#include "../../Graph/Shortest-Path/bfs.hpp"

#include "../../Util/IO/var-declaration-with-input.hpp"
#include "../../Util/IO/println.hpp"

int main() {
    var(int, N);

    Graph<void> G(N);
    for (int i = 0; i < N; ++i) {
        var(int, u, k);
        --u;
        while (k--) {
            var(int, v);
            --v;
            G[u].emplace_back(v);
        }
    }

    std::vector<int> dist(N, -1);
    bfs(dist, 0, [&](int v, auto push) {
        for (const int to : G[v]) push(to);
    });

    for (int i = 0; i < N; ++i) {
        println(i + 1, dist[i]);
    }

    return 0;
}
