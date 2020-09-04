#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include <bits/stdc++.h>

#include "../include/data-structure/union-find.hpp"
#include "../include/template-parts/io-setup.hpp"
using namespace std;

int main() {
    ioSetup();
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
