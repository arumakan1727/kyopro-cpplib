#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"
#include <bits/stdc++.h>

#include "../../Graph/Shortest-Path/bfs.hpp"
#include "../../Util/make-four-neighbor-enumerator.hpp"
#include "../../Util/rep-macro.hpp"
#include "../../Util/makeVec.hpp"
#include "../../Util/fillContainer.hpp"
#include "../../Util/IO/var-declaration-with-input.hpp"

int main() {
    using P = std::array<int, 2>;

    var(int, H, W, N);

    std::vector<std::string> mat(H);
    std::vector<P> cheeses(N + 1);

    rep(i, 0, H) {
        std::cin >> mat[i];
        rep(j, 0, W) {
            if (std::isdigit(mat[i][j])) {
                cheeses[mat[i][j] - '0'] = P{i, j};
            } else if (mat[i][j] == 'S') {
                cheeses[0] = P{i, j};
            }
        }
    }

    const auto enumerate4neighbor = makeFourNeighborEnumerator(H, W, [&](auto, auto to, auto f) {
        const auto [y, x] = to;
        if (mat[y][x] != 'X') f(to);
    });

    auto dist = makeVec<int>(H, W, -1);

    int ans = 0;
    rep(level, 0, N) {
        const P s = cheeses[level];
        const P g = cheeses[level + 1];
        fillContainer<int>(dist, -1);
        bfs(dist, s, enumerate4neighbor);
        ans += arumakan::at(dist, g);
    }

    std::cout << ans << std::endl;

    return 0;
}
