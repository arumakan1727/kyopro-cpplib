#pragma once
#include <cassert>
#include <vector>

#include "../Modulo/mod-int.hpp"

/**
 * @brief factorials (階乗, 階乗の逆元, nCr, nPr)
 */
template <class Mint>
struct Factorials {
public:
    using value_type = Mint;
    static constexpr size_t MAX_N = std::min<size_t>(1e7, Mint::mod()) + 1;

private:
    mutable std::vector<value_type> m_fact, m_finv;

public:
    Factorials() {
        m_fact.reserve(MAX_N);
        m_finv.reserve(MAX_N);
        m_fact.resize(2, value_type::raw(1));   // m_fact[0] = m_fact[1] = 1
        m_finv.resize(2, value_type::raw(1));   // m_finv[0] = m_finv[1] = 1
    }

    void preCalc(size_t n) const {
        if (n < m_fact.size()) return;
        const size_t l = m_fact.size();
        const size_t r = n + 1;
        m_fact.resize(r), m_finv.resize(r);
        for (size_t i = l; i < r; ++i) m_fact[i] = m_fact[i - 1] * i;
        m_finv[r - 1] = m_fact[r - 1].inv();
        for (size_t i = r - 1; i > l; --i) m_finv[i - 1] = m_finv[i] * i;
    }

    const value_type fact(int i) const { return preCalc(i), m_fact[i]; }
    const value_type finv(int i) const { return preCalc(i), m_finv[i]; }

    const value_type C(int n, int r) const {
        if (r < 0 || n < r) return value_type::raw(0);
        return preCalc(n), m_fact[n] * m_finv[r] * m_finv[n - r];
    }

    const value_type P(int n, int r) const {
        if (r < 0 || n < r) return value_type::raw(0);
        return preCalc(n), m_fact[n] * m_finv[n - r];
    }

    const value_type H(int n, int r) const {
        if (n < 0 || r < 0) return value_type::raw(0);
        if (n == 0 && r == 0) return value_type::raw(1);
        return C(n + r - 1, r);
    }
};
