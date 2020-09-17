#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja"

#include <iostream>
#include <type_traits>

#include "../../Math/Modulo/mod-int.hpp"
#include "../../Algorithm/doubling-pow.hpp"
#include "../../Util/IO/println.hpp"

int main() {
    using Mint = ModInt1000000007;

    int n;
    std::cin >> n;

    Mint k;
    std::cin >> k;

    const auto ans1 = k.pow(n);
    const auto ans2 = doublingPow(k, n);

    static_assert(std::is_same_v<decltype(ans1), decltype(ans2)>);
    assert(ans1 == ans2);


    println(ans1);

    return 0;
}
