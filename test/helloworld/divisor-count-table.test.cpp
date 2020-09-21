#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <bits/stdc++.h>

#include "../../Math/Number-Theory/eratosthenes-sieve.hpp"
#include "../../Math/Number-Theory/osa_k.hpp"
#include "../../Math/Number-Theory/divisor-count-table.hpp"

constexpr int N = 1e5;

int divisorCount(int n, const EratosthenesSieve& sieve) {
    int ret = 1;
    for (const auto [value, cnt] : osa_k(n, sieve)) {
        ret *= (cnt + 1);
    }
    return ret;
}

void test_divisorCountTable() {
    const auto dct = divisorCountTable(N);
    const auto sieve = EratosthenesSieve(N);

    for (int i = 1; i <= N; ++i) {
        const auto expected = divisorCount(i, sieve);
        const auto got = dct[i];
        assert(got == expected);
    }

    std::clog << __func__ << " : OK" << std::endl;
}

int main() {
    std::cout << "Hello World" << std::endl;

    test_divisorCountTable();

    return 0;
}
