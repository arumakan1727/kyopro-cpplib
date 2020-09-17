#pragma once
#include <cstdint>

/**
 * @brief isPrime() (素数判定 $O(\sqrt n)$)
 */
constexpr bool isPrime(int64_t n) {
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;
    for (int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
