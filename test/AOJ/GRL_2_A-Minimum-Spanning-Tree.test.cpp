#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp"
#include <iostream>

#include "../../Graph/graph-template.hpp"
#include "../../Graph/Minimum-Spanning-Tree/kruskal.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int V, E;
    std::cin >> V >> E;

    std::vector<Edge<int>> es(E);
    for (int i = 0; i < E; ++i) {
        std::cin >> es[i];
    }

    std::cout << kruskal<int>(V, es) << std::endl;

    return 0;
}
