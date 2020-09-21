#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <bits/stdc++.h>

#include "../../Math/Number-Theory/eratosthenes-sieve.hpp"
#include "../../Math/Number-Theory/osa_k.hpp"
#include "../../Math/Number-Theory/prime-factorize.hpp"

constexpr int N = 1e4;

void test_osa_k() {
    const auto sieve = EratosthenesSieve(N);
    
    for (int i = 2; i <= N; ++i) {
        const auto expected = primeFactorize(i);
        const auto got = osa_k(i, sieve);
        assert(got == expected);
    }

    std::clog << __func__ << " : OK" << std::endl;
}

int main() {
    std::cout << "Hello World" << std::endl;

    test_osa_k();

    return 0;
}
