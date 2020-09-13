#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>

#include "../../Math/Number-Theory/is-prime.hpp"
#include "../../Util/IO/io-setup.hpp"

int main() {
    ioSetup();

    int N;
    std::cin >> N;

    int ans = 0;
    while (N--) {
        int x;
        std::cin >> x;
        if (isPrime(x)) ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}
