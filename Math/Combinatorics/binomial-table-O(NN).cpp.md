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
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "binomialTable() (\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB\
      \ $O(N^2)$)"
    links: []
  bundledCode: "#line 2 \"Math/Combinatorics/binomial-table-O(NN).cpp\"\n#include\
    \ <vector>\n\n/**\n * @brief binomialTable() (\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\
    \u30D6\u30EB $O(N^2)$)\n * \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\u306B\
    \u3088\u308A N \u4EE5\u4E0B\u306E\u4E8C\u9805\u4FC2\u6570\u3092\u6C42\u3081\u308B\
    \u3002\n */\ntemplate <class T>\nauto binomialTable(int N) {\n    using std::vector;\n\
    \    vector<vector<T>> binomial(N + 1);\n    for (int i = 0; i <= N; ++i) {\n\
    \        binomial[i].resize(i + 1);\n        for (int j = 0; j <= i; ++j) {\n\
    \            if (j == 0 || j == i)\n                binomial[i][j] = 1;\n    \
    \        else\n                binomial[i][j] = binomial[i - 1][j - 1] + binomial[i\
    \ - 1][j];\n        }\n    }\n    return binomial;\n}\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief binomialTable() (\u4E8C\
    \u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB $O(N^2)$)\n * \u30D1\u30B9\u30AB\u30EB\
    \u306E\u4E09\u89D2\u5F62\u306B\u3088\u308A N \u4EE5\u4E0B\u306E\u4E8C\u9805\u4FC2\
    \u6570\u3092\u6C42\u3081\u308B\u3002\n */\ntemplate <class T>\nauto binomialTable(int\
    \ N) {\n    using std::vector;\n    vector<vector<T>> binomial(N + 1);\n    for\
    \ (int i = 0; i <= N; ++i) {\n        binomial[i].resize(i + 1);\n        for\
    \ (int j = 0; j <= i; ++j) {\n            if (j == 0 || j == i)\n            \
    \    binomial[i][j] = 1;\n            else\n                binomial[i][j] = binomial[i\
    \ - 1][j - 1] + binomial[i - 1][j];\n        }\n    }\n    return binomial;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combinatorics/binomial-table-O(NN).cpp
  requiredBy: []
  timestamp: '2020-09-17 22:45:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1501-Grid.test.cpp
documentation_of: Math/Combinatorics/binomial-table-O(NN).cpp
layout: document
redirect_from:
- /library/Math/Combinatorics/binomial-table-O(NN).cpp
- /library/Math/Combinatorics/binomial-table-O(NN).cpp.html
title: "binomialTable() (\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB $O(N^2)$)"
---
