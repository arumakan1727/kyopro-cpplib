#pragma once
#include <cassert>
#include <vector>

#include "../Modulo/mod-int.hpp"

/**
 * @brief factorials (階乗, 階乗の逆元, nCr, nPr)
 */
template <int Mod>
class Factorials {
public:
    static constexpr std::size_t MAX_N = std::min<std::size_t>(3e6, Mod) + 1;
    using value_type = StaticModInt<Mod>;

private:
    static size_t size;
    static value_type factorial[MAX_N];
    static value_type factInv[MAX_N];

public:
    Factorials() = delete;

    static void preCalc(std::size_t n) {
        if (n < size) return;
        if (size == 0) ++size, (factorial[0] = factInv[0] = value_type::raw(1));
        const std::size_t l = size;
        const std::size_t r = n + 1;
        for (std::size_t i = l; i < r; ++i) factorial[i] = factorial[i - 1] * i;
        factInv[r - 1] = factorial[r - 1].inv();
        for (std::size_t i = r - 1; i > l; --i) factInv[i - 1] = factInv[i] * i;
        size = r;
    }

    static value_type fact(int i) { return preCalc(i), factorial[i]; }
    static value_type finv(int i) { return preCalc(i), factInv[i]; }

    static value_type C(int n, int r) {
        if (r < 0 || n < r) return value_type::raw(0);
        return preCalc(n), factorial[n] * factInv[r] * factInv[n - r];
    }

    static value_type P(int n, int r) {
        if (r < 0 || n < r) return value_type::raw(0);
        return preCalc(n), factorial[n] * factInv[n - r];
    }

    static value_type H(int n, int r) {
        if (n < 0 || r < 0) return value_type::raw(0);
        if (n == 0 && r == 0) return value_type::raw(1);
        return C(n + r - 1, r);
    }
};
template <int Mod>
std::size_t Factorials<Mod>::size = 0;
template <int Mod>
typename Factorials<Mod>::value_type Factorials<Mod>::factorial[];
template <int Mod>
typename Factorials<Mod>::value_type Factorials<Mod>::factInv[];
