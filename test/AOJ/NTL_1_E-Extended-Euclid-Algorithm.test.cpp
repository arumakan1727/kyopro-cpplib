#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>

#include "../../Math/Number-Theory/extgcd.hpp"
#include "../../Util/int-alias.hpp"

int main() {
    i64 a, b, x, y;
    std::cin >> a >> b;
    extgcd(a, b, x, y);
    std::cout << x << ' ' << y << std::endl;

    return 0;
}