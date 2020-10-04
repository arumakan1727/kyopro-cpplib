---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/helloworld/divisor-count-table.test.cpp
    title: test/helloworld/divisor-count-table.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "divisorCountTable (\u7D04\u6570\u306E\u500B\u6570\u306E\u30C6\
      \u30FC\u30D6\u30EB, $O(N \\log N)$)"
    links: []
  bundledCode: "#line 2 \"Math/Number-Theory/divisor-count-table.hpp\"\n\n#include\
    \ <vector>\n\n/**\n * @brief divisorCountTable (\u7D04\u6570\u306E\u500B\u6570\
    \u306E\u30C6\u30FC\u30D6\u30EB, $O(N \\log N)$)\n * cnt[i] = i \u306E\u7D04\u6570\
    \u306E\u500B\u6570; \u7BC4\u56F2\u306F\u9589\u533A\u9593 [0, N]\n */\nstd::vector<int>\
    \ divisorCountTable(int N) {\n    std::vector<int> cnt(N + 1);\n    for (int d\
    \ = 1; d <= N; ++d) {\n        for (int i = d; i <= N; i += d) ++cnt[i];\n   \
    \ }\n    return cnt;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\n/**\n * @brief divisorCountTable (\u7D04\
    \u6570\u306E\u500B\u6570\u306E\u30C6\u30FC\u30D6\u30EB, $O(N \\log N)$)\n * cnt[i]\
    \ = i \u306E\u7D04\u6570\u306E\u500B\u6570; \u7BC4\u56F2\u306F\u9589\u533A\u9593\
    \ [0, N]\n */\nstd::vector<int> divisorCountTable(int N) {\n    std::vector<int>\
    \ cnt(N + 1);\n    for (int d = 1; d <= N; ++d) {\n        for (int i = d; i <=\
    \ N; i += d) ++cnt[i];\n    }\n    return cnt;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/divisor-count-table.hpp
  requiredBy: []
  timestamp: '2020-09-21 12:52:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/helloworld/divisor-count-table.test.cpp
documentation_of: Math/Number-Theory/divisor-count-table.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/divisor-count-table.hpp
- /library/Math/Number-Theory/divisor-count-table.hpp.html
title: "divisorCountTable (\u7D04\u6570\u306E\u500B\u6570\u306E\u30C6\u30FC\u30D6\u30EB\
  , $O(N \\log N)$)"
---
