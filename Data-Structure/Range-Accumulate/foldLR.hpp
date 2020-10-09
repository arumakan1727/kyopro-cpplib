#pragma once
#include <vector>

/**
 * @brief FoldLR
 */
template <class T>
class FoldLR {
    std::vector<T> m_foldL, m_foldR;
    T m_e;

public:
    FoldLR() = default;

    template <class BidirectionalItr, class Op>
    FoldLR(BidirectionalItr begin, BidirectionalItr end, const T& e, Op op)
        : FoldLR(begin, end, e, op, op) {}

    /**
     * foldLeftOp: (T, Elem) -> T
     * foldRightOp: (Elem, T) -> T
     */
    template <class BidirectionalItr, class FoldLeftOp, class FoldRightOp>
    FoldLR(BidirectionalItr begin, BidirectionalItr end, const T& e, FoldLeftOp foldLeftOp, FoldRightOp foldRightOp)
        : m_foldL(std::distance(begin, end) + 1, e)
        , m_foldR(std::distance(begin, end) + 1, e)
        , m_e(e) {
        size_t i;
        BidirectionalItr itr;
        for (i = 0, itr = begin; itr != end; ++i, ++itr) {
            m_foldL[i + 1] = foldLeftOp(m_foldL[i], *itr);
        }
        for (i = m_foldR.size() - 1, itr = std::prev(end); i > 0; --i, --itr) {
            m_foldR[i - 1] = foldRightOp(*itr, m_foldR[i]);
        }
    }

    /**
     * [0, r)
     * ((((e op a[0]) op a[1]) op a[2]) ... op a[r - 1])
     * foldL(0) returns e();
     */
    const T foldL(size_t r) const { return m_foldL[r]; }

    /**
     * [l, N)
     * (a[l] op ... (a[N - 3] op (a[N - 2] op (a[N - 1] op e))))
     * foldR(N) returns e();
     */
    const T foldR(size_t l) const { return m_foldR[l]; }

    const T e() const { return m_e; }
};
