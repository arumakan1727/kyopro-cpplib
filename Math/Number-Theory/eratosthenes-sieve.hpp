#pragma once
#include <cassert>
#include <vector>
#include <numeric>

/**
 * @brief Eratosthenes-Sieve (エラトステネスの篩)
 * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
 */
class EratosthenesSieve {
private:
    int m_size;
    std::vector<int> m_minFactor;

public:
    EratosthenesSieve() = default;

    //! [0, n] の範囲で篩を構築する
    explicit EratosthenesSieve(int n_)
        : m_size(n_ + 1)
        , m_minFactor(m_size) {
        std::iota(m_minFactor.begin(), m_minFactor.end(), 0);
        for (int i = 2; i * i < m_size; ++i) {
            if (m_minFactor[i] < i) continue;
            for (int j = i * i; j < m_size; j += i) {
                if (m_minFactor[j] == j) m_minFactor[j] = i;
            }
        }
        m_minFactor[0] = -1;
        if (n_ >= 1) m_minFactor[1] = -1;
    }

    bool isPrime(int x) const {
        assert(0 <= x && x < m_size);
        return m_minFactor[x] == x;
    }

    int minFactor(int x) const {
        assert(0 <= x && x < m_size);
        return m_minFactor[x];
    }
};
