---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
      \u306E\u7BE9)"
    links: []
  bundledCode: "#line 2 \"Math/Number-Theory/eratosthenes-sieve.hpp\"\n#include <cassert>\n\
    #include <vector>\n#include <numeric>\n\n/**\n * @brief Eratosthenes-Sieve (\u30A8\
    \u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n */\nclass EratosthenesSieve\
    \ {\nprivate:\n    int n_;\n    std::vector<int> minFactor_;\n\npublic:\n    EratosthenesSieve()\
    \ = default;\n\n    explicit EratosthenesSieve(int n)\n        : n_(n)\n     \
    \   , minFactor_(n) {\n        std::iota(minFactor_.begin(), minFactor_.end(),\
    \ 0);\n        for (int i = 2; i * i < n; ++i) {\n            if (minFactor_[i]\
    \ < i) continue;\n            for (int j = i * i; j < n; j += i) {\n         \
    \       if (minFactor_[j] == j) minFactor_[j] = i;\n            }\n        }\n\
    \        if (n >= 0) minFactor_[0] = -1;\n        if (n >= 1) minFactor_[1] =\
    \ -1;\n    }\n\n    bool isPrime(int x) const {\n        assert(0 <= x && x <\
    \ n_);\n        return minFactor_[x] == x;\n    }\n\n    int minFactor(int x)\
    \ const {\n        assert(0 <= x && x < n_);\n        return minFactor_[x];\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include <numeric>\n\
    \n/**\n * @brief Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9)\n */\nclass EratosthenesSieve {\nprivate:\n    int n_;\n    std::vector<int>\
    \ minFactor_;\n\npublic:\n    EratosthenesSieve() = default;\n\n    explicit EratosthenesSieve(int\
    \ n)\n        : n_(n)\n        , minFactor_(n) {\n        std::iota(minFactor_.begin(),\
    \ minFactor_.end(), 0);\n        for (int i = 2; i * i < n; ++i) {\n         \
    \   if (minFactor_[i] < i) continue;\n            for (int j = i * i; j < n; j\
    \ += i) {\n                if (minFactor_[j] == j) minFactor_[j] = i;\n      \
    \      }\n        }\n        if (n >= 0) minFactor_[0] = -1;\n        if (n >=\
    \ 1) minFactor_[1] = -1;\n    }\n\n    bool isPrime(int x) const {\n        assert(0\
    \ <= x && x < n_);\n        return minFactor_[x] == x;\n    }\n\n    int minFactor(int\
    \ x) const {\n        assert(0 <= x && x < n_);\n        return minFactor_[x];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/eratosthenes-sieve.hpp
  requiredBy: []
  timestamp: '2020-09-13 12:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Number-Theory/eratosthenes-sieve.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/eratosthenes-sieve.hpp
- /library/Math/Number-Theory/eratosthenes-sieve.hpp.html
title: "Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
  )"
---
