#pragma once
#include <cstdint>
#include <algorithm>
#include <vector>

/**
 * @brief enumerateDivisors() (約数列挙)
 */
template <class Integer>
std::vector<Integer> enumerateDivisors(Integer n) {
    std::vector<Integer> divisors;
    Integer i;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) divisors.push_back(i), divisors.push_back(n / i);
    }
    if (i * i == n) divisors.push_back(i);
    std::sort(divisors.begin(), divisors.end());
    return divisors;
}