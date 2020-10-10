#pragma once
#include <vector>
#include <cassert>

/**
 * @brief Fenwic-Tree (Binary-Indexed-Tree)
 */
template <class T>
class FenwicTree {
    size_t m_size;
    std::vector<T> dat;

public:
    FenwicTree() = default;

    explicit FenwicTree(size_t n)
        : m_size(n)
        , dat(n + 1) {}

    //! i: [0, n)
    void add(size_t i, const T& value) {
        assert(i < m_size);
        ++i;
        while (i <= m_size) dat[i] += value, i += i & -i;
    }

    //! [0, r)
    const T prefixSum(size_t r) const {
        T acc = 0;
        while (r > 0) acc += dat[r], r -= r & -r;
        return acc;
    }

    //! [l, r)
    const T sum(size_t l, size_t r) const { return prefixSum(r) - prefixSum(l); }

    //! i: [0, n)
    const T at(size_t i) const { return prefixSum(i + 1) - prefixSum(i); }

    //! return `i` s.t. prefixSum(i) >= value
    size_t lowerBound(T value) const {
        if (value <= 0) return 0;
        static const auto B = floorPow2(m_size);
        size_t i = 0;
        for (size_t k = B; k > 0; k >>= 1) {
            if (i + k <= m_size && dat[i + k] < value) {
                value -= dat[i + k];
                i += k;
            }
        }
        return i + 1;
    }

private:
    static inline constexpr size_t floorPow2(size_t x) noexcept {
        size_t ret = 1;
        while (ret <= x) ret <<= 1;
        return ret >> 1;
    }
};
