#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include <bits/stdc++.h>

#include "../../Data-Structure/Disjoint-Set/union-find.hpp"
using namespace std;

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    constexpr char LF = '\n';

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << uf.same(x, y) << LF;
        }
    }

    return 0;
}
