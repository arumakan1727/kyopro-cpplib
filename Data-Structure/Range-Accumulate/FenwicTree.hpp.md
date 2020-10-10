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
    document_title: Fenwic-Tree (Binary-Indexed-Tree)
    links: []
  bundledCode: "#line 2 \"Data-Structure/Range-Accumulate/FenwicTree.hpp\"\n#include\
    \ <vector>\n#include <cassert>\n\n/**\n * @brief Fenwic-Tree (Binary-Indexed-Tree)\n\
    \ */\ntemplate <class T>\nclass FenwicTree {\n    size_t m_size;\n    std::vector<T>\
    \ dat;\n\npublic:\n    FenwicTree() = default;\n\n    explicit FenwicTree(size_t\
    \ n)\n        : m_size(n)\n        , dat(n + 1) {}\n\n    //! i: [0, n)\n    void\
    \ add(size_t i, const T& value) {\n        assert(i < m_size);\n        ++i;\n\
    \        while (i <= m_size) dat[i] += value, i += i & -i;\n    }\n\n    //! [0,\
    \ r)\n    const T prefixSum(size_t r) const {\n        T acc = 0;\n        while\
    \ (r > 0) acc += dat[r], r -= r & -r;\n        return acc;\n    }\n\n    //! [l,\
    \ r)\n    const T sum(size_t l, size_t r) const { return prefixSum(r) - prefixSum(l);\
    \ }\n\n    //! i: [0, n)\n    const T at(size_t i) const { return prefixSum(i\
    \ + 1) - prefixSum(i); }\n\n    //! return `i` s.t. prefixSum(i) >= value\n  \
    \  size_t lowerBound(T value) const {\n        if (value <= 0) return 0;\n   \
    \     static const auto B = floorPow2(m_size);\n        size_t i = 0;\n      \
    \  for (size_t k = B; k > 0; k >>= 1) {\n            if (i + k <= m_size && dat[i\
    \ + k] < value) {\n                value -= dat[i + k];\n                i +=\
    \ k;\n            }\n        }\n        return i + 1;\n    }\n\nprivate:\n   \
    \ static inline constexpr size_t floorPow2(size_t x) noexcept {\n        size_t\
    \ ret = 1;\n        while (ret <= x) ret <<= 1;\n        return ret >> 1;\n  \
    \  }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\n/**\n * @brief Fenwic-Tree\
    \ (Binary-Indexed-Tree)\n */\ntemplate <class T>\nclass FenwicTree {\n    size_t\
    \ m_size;\n    std::vector<T> dat;\n\npublic:\n    FenwicTree() = default;\n\n\
    \    explicit FenwicTree(size_t n)\n        : m_size(n)\n        , dat(n + 1)\
    \ {}\n\n    //! i: [0, n)\n    void add(size_t i, const T& value) {\n        assert(i\
    \ < m_size);\n        ++i;\n        while (i <= m_size) dat[i] += value, i +=\
    \ i & -i;\n    }\n\n    //! [0, r)\n    const T prefixSum(size_t r) const {\n\
    \        T acc = 0;\n        while (r > 0) acc += dat[r], r -= r & -r;\n     \
    \   return acc;\n    }\n\n    //! [l, r)\n    const T sum(size_t l, size_t r)\
    \ const { return prefixSum(r) - prefixSum(l); }\n\n    //! i: [0, n)\n    const\
    \ T at(size_t i) const { return prefixSum(i + 1) - prefixSum(i); }\n\n    //!\
    \ return `i` s.t. prefixSum(i) >= value\n    size_t lowerBound(T value) const\
    \ {\n        if (value <= 0) return 0;\n        static const auto B = floorPow2(m_size);\n\
    \        size_t i = 0;\n        for (size_t k = B; k > 0; k >>= 1) {\n       \
    \     if (i + k <= m_size && dat[i + k] < value) {\n                value -= dat[i\
    \ + k];\n                i += k;\n            }\n        }\n        return i +\
    \ 1;\n    }\n\nprivate:\n    static inline constexpr size_t floorPow2(size_t x)\
    \ noexcept {\n        size_t ret = 1;\n        while (ret <= x) ret <<= 1;\n \
    \       return ret >> 1;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data-Structure/Range-Accumulate/FenwicTree.hpp
  requiredBy: []
  timestamp: '2020-10-10 20:16:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static-range-sum.test.cpp
documentation_of: Data-Structure/Range-Accumulate/FenwicTree.hpp
layout: document
redirect_from:
- /library/Data-Structure/Range-Accumulate/FenwicTree.hpp
- /library/Data-Structure/Range-Accumulate/FenwicTree.hpp.html
title: Fenwic-Tree (Binary-Indexed-Tree)
---
