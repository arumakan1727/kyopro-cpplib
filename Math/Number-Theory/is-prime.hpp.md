---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp
    title: test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "isPrime() (\u7D20\u6570\u5224\u5B9A $O(\\sqrt n)$)"
    links: []
  bundledCode: "#line 2 \"Math/Number-Theory/is-prime.hpp\"\n#include <cstdint>\n\n\
    /**\n * @brief isPrime() (\u7D20\u6570\u5224\u5B9A $O(\\sqrt n)$)\n */\nconstexpr\
    \ bool isPrime(int64_t n) {\n    if (n == 2) return true;\n    if (n <= 1 || n\
    \ % 2 == 0) return false;\n    for (int64_t i = 3; i * i <= n; i += 2) {\n   \
    \     if (n % i == 0) return false;\n    }\n    return true;\n}\n"
  code: "#pragma once\n#include <cstdint>\n\n/**\n * @brief isPrime() (\u7D20\u6570\
    \u5224\u5B9A $O(\\sqrt n)$)\n */\nconstexpr bool isPrime(int64_t n) {\n    if\
    \ (n == 2) return true;\n    if (n <= 1 || n % 2 == 0) return false;\n    for\
    \ (int64_t i = 3; i * i <= n; i += 2) {\n        if (n % i == 0) return false;\n\
    \    }\n    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/is-prime.hpp
  requiredBy: []
  timestamp: '2020-09-17 22:43:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp
documentation_of: Math/Number-Theory/is-prime.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/is-prime.hpp
- /library/Math/Number-Theory/is-prime.hpp.html
title: "isPrime() (\u7D20\u6570\u5224\u5B9A $O(\\sqrt n)$)"
---
