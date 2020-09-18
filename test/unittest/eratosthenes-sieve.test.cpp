#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <bits/stdc++.h>

#include "../../Math/Number-Theory/eratosthenes-sieve.hpp"
#include "../../Math/Number-Theory/is-prime.hpp"

constexpr int N = 1e4;
EratosthenesSieve sieve(N);

void test_isPrime() {
    for (int i = 0; i <= N; ++i) {
        assert(sieve.isPrime(i) == isPrime(i));
    }

    std::clog << __func__ << " : OK" << std::endl;
}

void test_minFactor() {

    const auto minFactor = [](int n) {
        if (n % 2 == 0) return 2;
        for (int i = 3; i < n; ++i)
            if (n % i == 0) return i;
        return -1;
    };

    for (int i = 2; i <= N; ++i) {
        if (sieve.isPrime(i)) {
            assert(sieve.minFactor(i) == i);
        } else {
            assert(sieve.minFactor(i) == minFactor(i));
        }
    }

    std::clog << __func__ << " : OK" << std::endl;
}

int main() {
    std::cout << "Hello World" << std::endl;

    test_isPrime();
    test_minFactor();

    return 0;
}
