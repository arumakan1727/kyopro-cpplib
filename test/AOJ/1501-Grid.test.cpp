#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"
#include <bits/stdc++.h>

#include "../../Math/Modulo/mod-int.hpp"

#include "../../Math/Combinatorics/factorials.hpp"
#include "../../Math/Combinatorics/binomial-O(K).cpp"
#include "../../Math/Combinatorics/binomial-table-O(NN).cpp"
#include "../../Math/Combinatorics/binomial-table-const-N.cpp"

#include "../../Util/IO/var-declaration-with-input.hpp"
#include "../../Util/chminmax.hpp"
#include "../../Util/int-infinity.hpp"
#include "../../Util/Debug/debug.hpp"

using namespace std;

int main() {
    constexpr int OFFSET = 2000;
    constexpr int MOD = int(1e8) + 7;
    using Mint = StaticModInt<MOD>;
    const auto F = Factorials<Mint::mod()>();

    var(int, H, W, sy, sx, gy, gx);
    sx += OFFSET;
    sy += OFFSET;
    gx += OFFSET;
    gy += OFFSET;

    const auto manhattan = [](auto y1, auto x1, auto y2, auto x2) { return abs(y1 - y2) + abs(x1 - x2); };

    int minDist = INF;

    for (const int ay : {-H, 0, +H}) {
        for (const int ax : {-W, 0, +W}) {
            chmin(minDist, manhattan(sy, sx, gy + ay, gx + ax));
        }
    }

    const auto allEqual = [](std::initializer_list<Mint> xs) {
        for (const auto& e : xs)
            if (e != *begin(xs)) return false;
        return true;
    };

    Mint ans = 0;
    for (const int ay : {-H, 0, +H}) {
        for (const int ax : {-W, 0, +W}) {
            if (manhattan(sy, sx, gy + ay, gx + ax) != minDist) continue;

            const int h = abs(sy - (gy + ay));
            const int w = abs(sx - (gx + ax));

            const auto res1 = F.fact(h + w) * F.finv(h) * F.finv(w);
            const auto res2 = F.fact(h + w) / (F.fact(h) * F.fact(w));
            const auto res3 = F.C(h + w, h);
            const auto res4 = F.C(h + w, w);
            const auto res5 = binomial<Mint>(h + w, h);
            const auto res6 = binomialTable<Mint>(h + w)[h + w][h];
            const auto res7 = binomialTable_constN<Mint>(h + w, h)[h];

            dump(res1, res2, res3, res4, res5, res6, res7);

            assert(allEqual({res1, res2, res3, res4, res5, res6, res7}));
            ans += res1;
        }
    }

    cout << ans << endl;

    return 0;
}
