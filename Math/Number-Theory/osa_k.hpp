#pragma once

#include <map>

#include "./eratosthenes-sieve.hpp"

/**
 * @brief osa_k() (前計算 $O(N \log \log N)$, 素因数分解 $O(\log N)$)
 * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
 */
std::map<int, int> osa_k(int n, const EratosthenesSieve& es) {
    std::map<int, int> ret;
    while (n > 1) {
        ++ret[es.minFactor(n)];
        n /= es.minFactor(n);
    }
    return ret;
}
