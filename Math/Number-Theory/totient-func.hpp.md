---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp
    title: test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "totient() (\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\
      \u30F3\u30C8\u95A2\u6570)"
    links: []
  bundledCode: "#line 2 \"Math/Number-Theory/totient-func.hpp\"\n\n/**\n * @brief\
    \ totient() (\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\
    \u95A2\u6570)\n */\ntemplate <class Integer>\nconstexpr Integer totient(Integer\
    \ n) {\n    Integer ret = n;\n    for (Integer i = 2; i * i <= n; ++i) {\n   \
    \     if (n % i == 0) {\n            ret -= ret / i;\n            while (n % i\
    \ == 0) n /= i;\n        }\n    }\n    if (n != 1) ret -= ret / n;\n    return\
    \ ret;\n}\n"
  code: "#pragma once\n\n/**\n * @brief totient() (\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\
    \u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)\n */\ntemplate <class Integer>\nconstexpr\
    \ Integer totient(Integer n) {\n    Integer ret = n;\n    for (Integer i = 2;\
    \ i * i <= n; ++i) {\n        if (n % i == 0) {\n            ret -= ret / i;\n\
    \            while (n % i == 0) n /= i;\n        }\n    }\n    if (n != 1) ret\
    \ -= ret / n;\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/totient-func.hpp
  requiredBy: []
  timestamp: '2020-09-17 22:43:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp
documentation_of: Math/Number-Theory/totient-func.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/totient-func.hpp
- /library/Math/Number-Theory/totient-func.hpp.html
title: "totient() (\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\
  \u95A2\u6570)"
---
