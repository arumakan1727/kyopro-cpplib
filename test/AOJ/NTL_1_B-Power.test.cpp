#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <iostream>
#include <type_traits>

#include "../../Math/Modulo/mod-int.hpp"
#include "../../Algorithm/doubling-pow.hpp"

int main() {
    using Mint = ModInt1000000007;

    Mint m;
    int n;
    std::cin >> m >> n;

    const auto ans1 = m.pow(n);
    const auto ans2 = doublingPow(m, n);

    static_assert(std::is_same_v<decltype(ans1), decltype(ans2)>);
    assert(ans1 == ans2);

    std::cout << ans1 << std::endl;

    return 0;
}
