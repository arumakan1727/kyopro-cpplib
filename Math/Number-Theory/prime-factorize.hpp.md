---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_A-Prime-Factorize.test.cpp
    title: test/AOJ/NTL_1_A-Prime-Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/helloworld/osa_k.test.cpp
    title: test/helloworld/osa_k.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "primeFactorize() (\u7D20\u56E0\u6570\u5206\u89E3 $O(\\sqrt n)$)"
    links: []
  bundledCode: "#line 2 \"Math/Number-Theory/prime-factorize.hpp\"\n#include <map>\n\
    \n/**\n * @brief primeFactorize() (\u7D20\u56E0\u6570\u5206\u89E3 $O(\\sqrt n)$)\n\
    \ */\ntemplate <class Integer>\nstd::map<Integer, int> primeFactorize(Integer\
    \ n) {\n    std::map<Integer, int> res;\n    for (Integer i = 2; i * i <= n; ++i)\
    \ {\n        while (n % i == 0) {\n            ++res[i];\n            n /= i;\n\
    \        }\n    }\n    if (n != 1) res[n] = 1;\n    return res;\n}\n"
  code: "#pragma once\n#include <map>\n\n/**\n * @brief primeFactorize() (\u7D20\u56E0\
    \u6570\u5206\u89E3 $O(\\sqrt n)$)\n */\ntemplate <class Integer>\nstd::map<Integer,\
    \ int> primeFactorize(Integer n) {\n    std::map<Integer, int> res;\n    for (Integer\
    \ i = 2; i * i <= n; ++i) {\n        while (n % i == 0) {\n            ++res[i];\n\
    \            n /= i;\n        }\n    }\n    if (n != 1) res[n] = 1;\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/prime-factorize.hpp
  requiredBy: []
  timestamp: '2020-09-13 11:30:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL_1_A-Prime-Factorize.test.cpp
  - test/helloworld/osa_k.test.cpp
documentation_of: Math/Number-Theory/prime-factorize.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/prime-factorize.hpp
- /library/Math/Number-Theory/prime-factorize.hpp.html
title: "primeFactorize() (\u7D20\u56E0\u6570\u5206\u89E3 $O(\\sqrt n)$)"
---
