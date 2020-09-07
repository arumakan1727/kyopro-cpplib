#pragma once
#include <cmath>
#include "../template-parts/type-alias.hpp"

/**
 * @brief pow() (繰り返し二乗法)
 */
template <class Integer>
Integer pow(const Integer& n, const i64 exp) {
    Integer ret = 1, square = n;
    for (u64 p = std::abs(exp); p; p >>= 1) {
        if (p & 1) ret *= square;
        square *= square;
    }
    return (exp < 0) ? (1 / ret) : ret;
}