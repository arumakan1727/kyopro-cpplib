#pragma once

/**
 * @brief totient() (オイラーのトーシェント関数)
 */
template <class Integer>
Integer totient(Integer n) {
    Integer ret = n;
    for (Integer i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) ret -= ret / n;
    return ret;
}