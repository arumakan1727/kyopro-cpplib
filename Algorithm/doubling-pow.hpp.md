---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/int-alias.hpp
    title: "int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_5_A.test.cpp
    title: test/AOJ/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_B-Power.test.cpp
    title: test/AOJ/NTL_1_B-Power.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "doubling-pow() (\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
    links: []
  bundledCode: "#line 2 \"Algorithm/doubling-pow.hpp\"\n#include <cmath>\n#line 2\
    \ \"Util/int-alias.hpp\"\n#include <cstdint>\n\n/**\n * @brief int-alias (\u6574\
    \u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)\n */\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\n#line 4 \"Algorithm/doubling-pow.hpp\"\n\n/**\n * @brief\
    \ doubling-pow() (\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)\n */\ntemplate <class\
    \ Integer>\nconstexpr Integer doublingPow(const Integer& n, const i64 expv) {\n\
    \    Integer ret = 1, square = n;\n    for (u64 p = std::abs(expv); p; p >>= 1)\
    \ {\n        if (p & 1) ret *= square;\n        square *= square;\n    }\n   \
    \ return (expv < 0) ? (1 / ret) : ret;\n}\n"
  code: "#pragma once\n#include <cmath>\n#include \"../Util/int-alias.hpp\"\n\n/**\n\
    \ * @brief doubling-pow() (\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)\n */\n\
    template <class Integer>\nconstexpr Integer doublingPow(const Integer& n, const\
    \ i64 expv) {\n    Integer ret = 1, square = n;\n    for (u64 p = std::abs(expv);\
    \ p; p >>= 1) {\n        if (p & 1) ret *= square;\n        square *= square;\n\
    \    }\n    return (expv < 0) ? (1 / ret) : ret;\n}\n"
  dependsOn:
  - Util/int-alias.hpp
  isVerificationFile: false
  path: Algorithm/doubling-pow.hpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL_1_B-Power.test.cpp
  - test/AOJ/DPL_5_A.test.cpp
documentation_of: Algorithm/doubling-pow.hpp
layout: document
redirect_from:
- /library/Algorithm/doubling-pow.hpp
- /library/Algorithm/doubling-pow.hpp.html
title: "doubling-pow() (\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
---
