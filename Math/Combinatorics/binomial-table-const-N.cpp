#pragma once
#include <cstdint>
#include <vector>

/**
 * @brief binomialTable_constN() (二項係数テーブル $O(K)$)
 * binomial[k] = binomial(N, k) を O(K) で前計算する。
 */
template <class T>
std::vector<T> binomialTable_constN(std::int64_t N, int K) {
    std::vector<T> binomial(K + 1);
    binomial[0] = 1;
    for (int i = 1; i <= K; ++i) {
        binomial[i] = binomial[i - 1] * (N - i + 1) / i;
    }
    return binomial;
}
