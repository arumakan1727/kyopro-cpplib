#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>

#include "../../Data-Structure/Range-Accumulate/cumulative-sum.hpp"
#include "../../Data-Structure/Range-Accumulate/foldLR.hpp"
#include "../../Data-Structure/Range-Accumulate/FenwicTree.hpp"

#include "../../Util/IO/println.hpp"
#include "../../Util/IO/read.hpp"
#include "../../Util/int-alias.hpp"
#include "../../Util/all-macro.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;

    auto a = read<int>(N);

    CumulativeSum<i64> cum(a);

    FoldLR<i64> fold(all(a), 0, [](i64 x1, i64 x2) { return x1 + x2; });

    FenwicTree<i64> ft(N);
    for (int i = 0; i < N; ++i) {
        ft.add(i, a[i]);
        assert(ft.at(i) == a[i]);
    }

    while (Q--) {
        int l, r;
        std::cin >> l >> r;

        const auto ans1 = cum.sum(l, r);
        const auto ans2 = fold.foldL(r) - fold.foldL(l);
        const auto ans3 = fold.foldR(l) - fold.foldR(r);
        const auto ans4 = ft.sum(l, r);

        assert(ans2 == ans1);
        assert(ans3 == ans1);
        assert(ans4 == ans1);

        println(ans1);
    }

    return 0;
}
