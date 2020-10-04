---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1501-Grid.test.cpp
    title: test/AOJ/1501-Grid.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "binomialTable_constN() (\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\u30D6\
      \u30EB $O(K)$)"
    links: []
  bundledCode: "#line 2 \"Math/Combinatorics/binomial-table-const-N.cpp\"\n#include\
    \ <cstdint>\n#include <vector>\n\n/**\n * @brief binomialTable_constN() (\u4E8C\
    \u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB $O(K)$)\n * binomial[k] = binomial(N,\
    \ k) \u3092 O(K) \u3067\u524D\u8A08\u7B97\u3059\u308B\u3002\n */\ntemplate <class\
    \ T>\nstd::vector<T> binomialTable_constN(int64_t N, int K) {\n    std::vector<T>\
    \ binomial(K + 1);\n    binomial[0] = 1;\n    for (int i = 1; i <= K; ++i) {\n\
    \        binomial[i] = binomial[i - 1] * (N - i + 1) / i;\n    }\n    return binomial;\n\
    }\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\n/**\n * @brief binomialTable_constN()\
    \ (\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB $O(K)$)\n * binomial[k] =\
    \ binomial(N, k) \u3092 O(K) \u3067\u524D\u8A08\u7B97\u3059\u308B\u3002\n */\n\
    template <class T>\nstd::vector<T> binomialTable_constN(int64_t N, int K) {\n\
    \    std::vector<T> binomial(K + 1);\n    binomial[0] = 1;\n    for (int i = 1;\
    \ i <= K; ++i) {\n        binomial[i] = binomial[i - 1] * (N - i + 1) / i;\n \
    \   }\n    return binomial;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combinatorics/binomial-table-const-N.cpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1501-Grid.test.cpp
documentation_of: Math/Combinatorics/binomial-table-const-N.cpp
layout: document
redirect_from:
- /library/Math/Combinatorics/binomial-table-const-N.cpp
- /library/Math/Combinatorics/binomial-table-const-N.cpp.html
title: "binomialTable_constN() (\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB $O(K)$)"
---
