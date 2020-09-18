---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/eratosthenes-sieve.test.cpp
    title: test/unittest/eratosthenes-sieve.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
      \u306E\u7BE9)"
    links: []
  bundledCode: "#line 2 \"Math/Number-Theory/eratosthenes-sieve.hpp\"\n#include <cassert>\n\
    #include <vector>\n#include <numeric>\n\n/**\n * @brief Eratosthenes-Sieve (\u30A8\
    \u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n */\nclass EratosthenesSieve\
    \ {\nprivate:\n    int m_size;\n    std::vector<int> m_minFactor;\n\npublic:\n\
    \    EratosthenesSieve() = default;\n\n    // [0, n] \u306E\u7BC4\u56F2\u3067\u7BE9\
    \u3092\u69CB\u7BC9\u3059\u308B\n    explicit EratosthenesSieve(int n_)\n     \
    \   : m_size(n_ + 1)\n        , m_minFactor(m_size) {\n        std::iota(m_minFactor.begin(),\
    \ m_minFactor.end(), 0);\n        for (int i = 2; i * i < m_size; ++i) {\n   \
    \         if (m_minFactor[i] < i) continue;\n            for (int j = i * i; j\
    \ < m_size; j += i) {\n                if (m_minFactor[j] == j) m_minFactor[j]\
    \ = i;\n            }\n        }\n        m_minFactor[0] = -1;\n        if (n_\
    \ >= 1) m_minFactor[1] = -1;\n    }\n\n    bool isPrime(int x) const {\n     \
    \   assert(0 <= x && x < m_size);\n        return m_minFactor[x] == x;\n    }\n\
    \n    int minFactor(int x) const {\n        assert(0 <= x && x < m_size);\n  \
    \      return m_minFactor[x];\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include <numeric>\n\
    \n/**\n * @brief Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9)\n */\nclass EratosthenesSieve {\nprivate:\n    int m_size;\n   \
    \ std::vector<int> m_minFactor;\n\npublic:\n    EratosthenesSieve() = default;\n\
    \n    // [0, n] \u306E\u7BC4\u56F2\u3067\u7BE9\u3092\u69CB\u7BC9\u3059\u308B\n\
    \    explicit EratosthenesSieve(int n_)\n        : m_size(n_ + 1)\n        , m_minFactor(m_size)\
    \ {\n        std::iota(m_minFactor.begin(), m_minFactor.end(), 0);\n        for\
    \ (int i = 2; i * i < m_size; ++i) {\n            if (m_minFactor[i] < i) continue;\n\
    \            for (int j = i * i; j < m_size; j += i) {\n                if (m_minFactor[j]\
    \ == j) m_minFactor[j] = i;\n            }\n        }\n        m_minFactor[0]\
    \ = -1;\n        if (n_ >= 1) m_minFactor[1] = -1;\n    }\n\n    bool isPrime(int\
    \ x) const {\n        assert(0 <= x && x < m_size);\n        return m_minFactor[x]\
    \ == x;\n    }\n\n    int minFactor(int x) const {\n        assert(0 <= x && x\
    \ < m_size);\n        return m_minFactor[x];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/eratosthenes-sieve.hpp
  requiredBy: []
  timestamp: '2020-09-18 19:25:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/eratosthenes-sieve.test.cpp
documentation_of: Math/Number-Theory/eratosthenes-sieve.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/eratosthenes-sieve.hpp
- /library/Math/Number-Theory/eratosthenes-sieve.hpp.html
title: "Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
  )"
---
