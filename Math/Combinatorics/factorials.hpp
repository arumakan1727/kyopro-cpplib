#pragma once
#include <vector>

#include "../Modulo/mod-int.hpp"

/**
 * @brief factorials (階乗, 階乗の逆元, nCr, nPr)
 */
template <int Mod>
class Factorials {
private:
    using Mint = StaticModInt<Mod>;
    static std::vector<Mint> factorial, factInv;

public:
    Factorials() = delete;

    static void grow(size_t n) {
        if (n < factorial.size()) return;
        const int l = static_cast<int>(factorial.size());
        const int r = static_cast<int>(n << 1) + 1000;
        factorial.resize(r, Mint::raw(1));
        factInv.resize(r, Mint::raw(1));
        for (int i = l; i < r; ++i) factorial[i] = factorial[i - 1] * i;
        factInv[r - 1] = Mint::raw(1) / factorial[r - 1];
        for (int i = r - 1; i > l; --i) factInv[i - 1] = factInv[i] * i;
    }

    static Mint fact(int i) { return grow(i), factorial[i]; }
    static Mint finv(int i) { return grow(i), factInv[i]; }

    static Mint C(int n, int r) {
        if (r < 0 || n < r) return Mint::raw(0);
        return grow(n), factorial[n] * factInv[r] * factInv[n - r];
    }

    static Mint P(int n, int r) {
        if (r < 0 || n < r) return Mint::raw(0);
        return grow(n), factorial[n] * factInv[n - r];
    }

    static Mint H(int n, int r) {
        if (r < 0 || n < r) return Mint::raw(0);
        if (n == 0 && r == 0) return Mint::raw(1);
        return C(n + r - 1, r);
    }
};
template <int Mod>
std::vector<typename Factorials<Mod>::Mint> Factorials<Mod>::factorial(2, 1);
template <int Mod>
std::vector<typename Factorials<Mod>::Mint> Factorials<Mod>::factInv(2, 1);
