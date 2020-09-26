#pragma once
#include <cstdint>

/**
 * @brief binomial() (二項係数 $O(K)$)
 */
template <class T>
T binomial(int64_t n, int k) {
    if (k < 0 || n < k) return 0;
    T nume = 1, deno = 1;
    for (int i = 1; i <= k; ++i) {
        nume *= n - i + 1;
        deno *= i;
    }
    return nume / deno;
}
