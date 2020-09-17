#pragma once
#include <cmath>
#include "../Util/int-alias.hpp"

/**
 * @brief pow() (繰り返し二乗法)
 */
template <class Integer>
Integer pow(const Integer& n, const i64 expv) {
    Integer ret = 1, square = n;
    for (u64 p = std::abs(expv); p; p >>= 1) {
        if (p & 1) ret *= square;
        square *= square;
    }
    return (expv < 0) ? (1 / ret) : ret;
}
