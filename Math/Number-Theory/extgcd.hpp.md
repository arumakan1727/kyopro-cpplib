---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp
    title: test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "extgcd() (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
      \u4E92\u9664\u6CD5)"
    links: []
  bundledCode: "#line 2 \"Math/Number-Theory/extgcd.hpp\"\n\n/**\n * @brief extgcd()\
    \ (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n\
    \ */\n// ax + by = gcd(a, b) \u306E\u6574\u6570\u89E3 (x, y) \u3092\u6C42\u3081\
    \u308B\ntemplate <class T>\nT extgcd(T a, T b, T& x, T& y) {\n    T g = a;\n \
    \   if (b != 0) {\n        g = extgcd(b, a % b, y, x);\n        y -= (a / b) *\
    \ x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return g;\n}\n"
  code: "#pragma once\n\n/**\n * @brief extgcd() (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n */\n// ax + by = gcd(a, b) \u306E\u6574\
    \u6570\u89E3 (x, y) \u3092\u6C42\u3081\u308B\ntemplate <class T>\nT extgcd(T a,\
    \ T b, T& x, T& y) {\n    T g = a;\n    if (b != 0) {\n        g = extgcd(b, a\
    \ % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n     \
    \   y = 0;\n    }\n    return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/extgcd.hpp
  requiredBy: []
  timestamp: '2020-09-13 11:30:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp
documentation_of: Math/Number-Theory/extgcd.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/extgcd.hpp
- /library/Math/Number-Theory/extgcd.hpp.html
title: "extgcd() (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
  \u6CD5)"
---
