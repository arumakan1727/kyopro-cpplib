---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static-range-sum.test.cpp
    title: test/yosupo/static-range-sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: FoldLR
    links: []
  bundledCode: "#line 2 \"Data-Structure/Range-Accumulate/foldLR.hpp\"\n#include <vector>\n\
    \n/**\n * @brief FoldLR\n */\ntemplate <class T>\nclass FoldLR {\n    std::vector<T>\
    \ m_foldL, m_foldR;\n    T m_e;\n\npublic:\n    FoldLR() = default;\n\n    template\
    \ <class BidirectionalItr, class Op>\n    FoldLR(BidirectionalItr begin, BidirectionalItr\
    \ end, const T& e, Op op)\n        : FoldLR(begin, end, e, op, op) {}\n\n    /**\n\
    \     * foldLeftOp: (T, Elem) -> T\n     * foldRightOp: (Elem, T) -> T\n     */\n\
    \    template <class BidirectionalItr, class FoldLeftOp, class FoldRightOp>\n\
    \    FoldLR(BidirectionalItr begin, BidirectionalItr end, const T& e, FoldLeftOp\
    \ foldLeftOp, FoldRightOp foldRightOp)\n        : m_foldL(std::distance(begin,\
    \ end) + 1, e)\n        , m_foldR(std::distance(begin, end) + 1, e)\n        ,\
    \ m_e(e) {\n        size_t i;\n        BidirectionalItr itr;\n        for (i =\
    \ 0, itr = begin; itr != end; ++i, ++itr) {\n            m_foldL[i + 1] = foldLeftOp(m_foldL[i],\
    \ *itr);\n        }\n        for (i = m_foldR.size() - 1, itr = std::prev(end);\
    \ i > 0; --i, --itr) {\n            m_foldR[i - 1] = foldRightOp(*itr, m_foldR[i]);\n\
    \        }\n    }\n\n    /**\n     * [0, r)\n     * ((((e op a[0]) op a[1]) op\
    \ a[2]) ... op a[r - 1])\n     * foldL(0) returns e();\n     */\n    const T foldL(size_t\
    \ r) const { return m_foldL[r]; }\n\n    /**\n     * [l, N)\n     * (a[l] op ...\
    \ (a[N - 3] op (a[N - 2] op (a[N - 1] op e))))\n     * foldR(N) returns e();\n\
    \     */\n    const T foldR(size_t l) const { return m_foldR[l]; }\n\n    const\
    \ T e() const { return m_e; }\n};\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief FoldLR\n */\ntemplate <class\
    \ T>\nclass FoldLR {\n    std::vector<T> m_foldL, m_foldR;\n    T m_e;\n\npublic:\n\
    \    FoldLR() = default;\n\n    template <class BidirectionalItr, class Op>\n\
    \    FoldLR(BidirectionalItr begin, BidirectionalItr end, const T& e, Op op)\n\
    \        : FoldLR(begin, end, e, op, op) {}\n\n    /**\n     * foldLeftOp: (T,\
    \ Elem) -> T\n     * foldRightOp: (Elem, T) -> T\n     */\n    template <class\
    \ BidirectionalItr, class FoldLeftOp, class FoldRightOp>\n    FoldLR(BidirectionalItr\
    \ begin, BidirectionalItr end, const T& e, FoldLeftOp foldLeftOp, FoldRightOp\
    \ foldRightOp)\n        : m_foldL(std::distance(begin, end) + 1, e)\n        ,\
    \ m_foldR(std::distance(begin, end) + 1, e)\n        , m_e(e) {\n        size_t\
    \ i;\n        BidirectionalItr itr;\n        for (i = 0, itr = begin; itr != end;\
    \ ++i, ++itr) {\n            m_foldL[i + 1] = foldLeftOp(m_foldL[i], *itr);\n\
    \        }\n        for (i = m_foldR.size() - 1, itr = std::prev(end); i > 0;\
    \ --i, --itr) {\n            m_foldR[i - 1] = foldRightOp(*itr, m_foldR[i]);\n\
    \        }\n    }\n\n    /**\n     * [0, r)\n     * ((((e op a[0]) op a[1]) op\
    \ a[2]) ... op a[r - 1])\n     * foldL(0) returns e();\n     */\n    const T foldL(size_t\
    \ r) const { return m_foldL[r]; }\n\n    /**\n     * [l, N)\n     * (a[l] op ...\
    \ (a[N - 3] op (a[N - 2] op (a[N - 1] op e))))\n     * foldR(N) returns e();\n\
    \     */\n    const T foldR(size_t l) const { return m_foldR[l]; }\n\n    const\
    \ T e() const { return m_e; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data-Structure/Range-Accumulate/foldLR.hpp
  requiredBy: []
  timestamp: '2020-10-10 05:48:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static-range-sum.test.cpp
documentation_of: Data-Structure/Range-Accumulate/foldLR.hpp
layout: document
redirect_from:
- /library/Data-Structure/Range-Accumulate/foldLR.hpp
- /library/Data-Structure/Range-Accumulate/foldLR.hpp.html
title: FoldLR
---
