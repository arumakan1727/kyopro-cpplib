#pragma once
#include <functional>
#include <valarray>
#include <utility>

/**
 * @brief CumulativeSum (累積和)
 */
template <class T>
struct CumulativeSum {
    std::valarray<T> data;

    CumulativeSum() = default;

    template <class Container>
    explicit CumulativeSum(const Container& container)
        : CumulativeSum(container.cbegin(), container.cend()) {}

    template <class InputItr>
    CumulativeSum(InputItr begin, InputItr end)
        : data(std::distance(begin, end) + 1) {
        size_t i;
        InputItr itr;
        for (i = 0, itr = begin; itr != end; ++i, ++itr) {
            data[i + 1] = data[i] + *itr;
        }
    }

    //! [0, r)
    const T prefixSum(size_t r) const { return data[r]; }

    //! [l, r)
    const T sum(size_t l, size_t r) const { return prefixSum(r) - prefixSum(l); }
};
