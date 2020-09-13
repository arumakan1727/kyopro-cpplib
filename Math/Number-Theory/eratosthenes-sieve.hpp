#pragma once
#include <cassert>
#include <vector>
#include <numeric>

/**
 * @brief Eratosthenes-Sieve (エラトステネスの篩)
 */
class EratosthenesSieve {
private:
    int n_;
    std::vector<int> minFactor_;

public:
    EratosthenesSieve() = default;

    explicit EratosthenesSieve(int n)
        : n_(n)
        , minFactor_(n) {
        std::iota(minFactor_.begin(), minFactor_.end(), 0);
        for (int i = 2; i * i < n; ++i) {
            if (minFactor_[i] < i) continue;
            for (int j = i * i; j < n; j += i) {
                if (minFactor_[j] == j) minFactor_[j] = i;
            }
        }
        if (n >= 0) minFactor_[0] = -1;
        if (n >= 1) minFactor_[1] = -1;
    }

    bool isPrime(int x) const {
        assert(0 <= x && x < n_);
        return minFactor_[x] == x;
    }

    int minFactor(int x) const {
        assert(0 <= x && x < n_);
        return minFactor_[x];
    }
};
