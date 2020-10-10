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
    document_title: "CumulativeSum (\u7D2F\u7A4D\u548C)"
    links: []
  bundledCode: "#line 2 \"Data-Structure/Range-Accumulate/cumulative-sum.hpp\"\n#include\
    \ <functional>\n#include <valarray>\n#include <utility>\n\n/**\n * @brief CumulativeSum\
    \ (\u7D2F\u7A4D\u548C)\n */\ntemplate <class T>\nstruct CumulativeSum {\n    std::valarray<T>\
    \ data;\n\n    CumulativeSum() = default;\n\n    template <class Container>\n\
    \    explicit CumulativeSum(const Container& container)\n        : CumulativeSum(container.cbegin(),\
    \ container.cend()) {}\n\n    template <class InputItr>\n    CumulativeSum(InputItr\
    \ begin, InputItr end)\n        : data(std::distance(begin, end) + 1) {\n    \
    \    size_t i;\n        InputItr itr;\n        for (i = 0, itr = begin; itr !=\
    \ end; ++i, ++itr) {\n            data[i + 1] = data[i] + *itr;\n        }\n \
    \   }\n\n    //! [0, r)\n    const T prefixSum(size_t r) const { return data[r];\
    \ }\n\n    //! [l, r)\n    const T sum(size_t l, size_t r) const { return prefixSum(r)\
    \ - prefixSum(l); }\n};\n"
  code: "#pragma once\n#include <functional>\n#include <valarray>\n#include <utility>\n\
    \n/**\n * @brief CumulativeSum (\u7D2F\u7A4D\u548C)\n */\ntemplate <class T>\n\
    struct CumulativeSum {\n    std::valarray<T> data;\n\n    CumulativeSum() = default;\n\
    \n    template <class Container>\n    explicit CumulativeSum(const Container&\
    \ container)\n        : CumulativeSum(container.cbegin(), container.cend()) {}\n\
    \n    template <class InputItr>\n    CumulativeSum(InputItr begin, InputItr end)\n\
    \        : data(std::distance(begin, end) + 1) {\n        size_t i;\n        InputItr\
    \ itr;\n        for (i = 0, itr = begin; itr != end; ++i, ++itr) {\n         \
    \   data[i + 1] = data[i] + *itr;\n        }\n    }\n\n    //! [0, r)\n    const\
    \ T prefixSum(size_t r) const { return data[r]; }\n\n    //! [l, r)\n    const\
    \ T sum(size_t l, size_t r) const { return prefixSum(r) - prefixSum(l); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data-Structure/Range-Accumulate/cumulative-sum.hpp
  requiredBy: []
  timestamp: '2020-10-10 05:48:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static-range-sum.test.cpp
documentation_of: Data-Structure/Range-Accumulate/cumulative-sum.hpp
layout: document
redirect_from:
- /library/Data-Structure/Range-Accumulate/cumulative-sum.hpp
- /library/Data-Structure/Range-Accumulate/cumulative-sum.hpp.html
title: "CumulativeSum (\u7D2F\u7A4D\u548C)"
---
