#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <iostream>

#include "../../Math/Modulo/mod-int.hpp"
#include "../../Algorithm/pow-doubling.hpp"

int main() {
    using Mint = StaticModInt<int(1e9) + 7>;

    Mint m;
    int n;
    std::cin >> m >> n;
    std::cout << pow(m, n) << std::endl;

    return 0;
}