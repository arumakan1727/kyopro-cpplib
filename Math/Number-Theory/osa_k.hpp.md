---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/eratosthenes-sieve.hpp
    title: "Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/helloworld/divisor-count-table.test.cpp
    title: test/helloworld/divisor-count-table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/helloworld/osa_k.test.cpp
    title: test/helloworld/osa_k.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "osa_k() (\u524D\u8A08\u7B97 $O(N \\log \\log N)$, \u7D20\u56E0\
      \u6570\u5206\u89E3 $O(\\log N)$)"
    links:
    - https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
  bundledCode: "#line 2 \"Math/Number-Theory/osa_k.hpp\"\n\n#include <map>\n\n#line\
    \ 2 \"Math/Number-Theory/eratosthenes-sieve.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n#include <numeric>\n\n/**\n * @brief Eratosthenes-Sieve (\u30A8\u30E9\
    \u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    \ */\nclass EratosthenesSieve {\nprivate:\n    int m_size;\n    std::vector<int>\
    \ m_minFactor;\n\npublic:\n    EratosthenesSieve() = default;\n\n    // [0, n]\
    \ \u306E\u7BC4\u56F2\u3067\u7BE9\u3092\u69CB\u7BC9\u3059\u308B\n    explicit EratosthenesSieve(int\
    \ n_)\n        : m_size(n_ + 1)\n        , m_minFactor(m_size) {\n        std::iota(m_minFactor.begin(),\
    \ m_minFactor.end(), 0);\n        for (int i = 2; i * i < m_size; ++i) {\n   \
    \         if (m_minFactor[i] < i) continue;\n            for (int j = i * i; j\
    \ < m_size; j += i) {\n                if (m_minFactor[j] == j) m_minFactor[j]\
    \ = i;\n            }\n        }\n        m_minFactor[0] = -1;\n        if (n_\
    \ >= 1) m_minFactor[1] = -1;\n    }\n\n    bool isPrime(int x) const {\n     \
    \   assert(0 <= x && x < m_size);\n        return m_minFactor[x] == x;\n    }\n\
    \n    int minFactor(int x) const {\n        assert(0 <= x && x < m_size);\n  \
    \      return m_minFactor[x];\n    }\n};\n#line 6 \"Math/Number-Theory/osa_k.hpp\"\
    \n\n/**\n * @brief osa_k() (\u524D\u8A08\u7B97 $O(N \\log \\log N)$, \u7D20\u56E0\
    \u6570\u5206\u89E3 $O(\\log N)$)\n * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    \ */\nstd::map<int, int> osa_k(int n, const EratosthenesSieve& es) {\n    std::map<int,\
    \ int> ret;\n    while (n > 1) {\n        ++ret[es.minFactor(n)];\n        n /=\
    \ es.minFactor(n);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <map>\n\n#include \"./eratosthenes-sieve.hpp\"\n\
    \n/**\n * @brief osa_k() (\u524D\u8A08\u7B97 $O(N \\log \\log N)$, \u7D20\u56E0\
    \u6570\u5206\u89E3 $O(\\log N)$)\n * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    \ */\nstd::map<int, int> osa_k(int n, const EratosthenesSieve& es) {\n    std::map<int,\
    \ int> ret;\n    while (n > 1) {\n        ++ret[es.minFactor(n)];\n        n /=\
    \ es.minFactor(n);\n    }\n    return ret;\n}\n"
  dependsOn:
  - Math/Number-Theory/eratosthenes-sieve.hpp
  isVerificationFile: false
  path: Math/Number-Theory/osa_k.hpp
  requiredBy: []
  timestamp: '2020-09-21 12:52:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/helloworld/osa_k.test.cpp
  - test/helloworld/divisor-count-table.test.cpp
documentation_of: Math/Number-Theory/osa_k.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/osa_k.hpp
- /library/Math/Number-Theory/osa_k.hpp.html
title: "osa_k() (\u524D\u8A08\u7B97 $O(N \\log \\log N)$, \u7D20\u56E0\u6570\u5206\
  \u89E3 $O(\\log N)$)"
---
