---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1501-Grid.test.cpp
    title: test/AOJ/1501-Grid.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "binomial() (\u4E8C\u9805\u4FC2\u6570 $O(K)$)"
    links: []
  bundledCode: "#line 2 \"Math/Combinatorics/binomial-O(K).cpp\"\n#include <cstdint>\n\
    \n/**\n * @brief binomial() (\u4E8C\u9805\u4FC2\u6570 $O(K)$)\n */\ntemplate <class\
    \ T>\nT binomial(int64_t n, int k) {\n    if (k < 0 || n < k) return 0;\n    T\
    \ nume = 1, deno = 1;\n    for (int i = 1; i <= k; ++i) {\n        nume *= n -\
    \ i + 1;\n        deno *= i;\n    }\n    return nume / deno;\n}\n"
  code: "#pragma once\n#include <cstdint>\n\n/**\n * @brief binomial() (\u4E8C\u9805\
    \u4FC2\u6570 $O(K)$)\n */\ntemplate <class T>\nT binomial(int64_t n, int k) {\n\
    \    if (k < 0 || n < k) return 0;\n    T nume = 1, deno = 1;\n    for (int i\
    \ = 1; i <= k; ++i) {\n        nume *= n - i + 1;\n        deno *= i;\n    }\n\
    \    return nume / deno;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combinatorics/binomial-O(K).cpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1501-Grid.test.cpp
documentation_of: Math/Combinatorics/binomial-O(K).cpp
layout: document
redirect_from:
- /library/Math/Combinatorics/binomial-O(K).cpp
- /library/Math/Combinatorics/binomial-O(K).cpp.html
title: "binomial() (\u4E8C\u9805\u4FC2\u6570 $O(K)$)"
---
