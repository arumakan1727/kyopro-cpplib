#pragma once
#include <map>

/**
 * @brief primeFactorize() (素因数分解 $O(\sqrt n)$)
 */
template <class Integer>
std::map<Integer, int> primeFactorize(Integer n) {
    std::map<Integer, int> res;
    for (Integer i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}