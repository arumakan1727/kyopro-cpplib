#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja"

#include <iostream>
#include <type_traits>

#include "../include/math/mod-int.hpp"
#include "../include/math/pow-doubling.hpp"
#include "../include/utility/compiletime-mod-holder.hpp"
#include "../include/template-parts/println.hpp"

int main() {
    using Mint = ModInt<CompiletimeModHolder<int(1e9) + 7>>;

    int n;
    std::cin >> n;

    Mint k;
    std::cin >> k;

    auto ans = pow(k, n);
    static_assert(std::is_same_v<decltype(ans), Mint>);

    println(pow(k, n));

    return 0;
}
