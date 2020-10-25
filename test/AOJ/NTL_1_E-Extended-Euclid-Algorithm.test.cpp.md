---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/extgcd.hpp
    title: "extgcd() (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
      \u9664\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: Util/int-alias.hpp
    title: "int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n\n#line 2 \"Math/Number-Theory/extgcd.hpp\"\n\n/**\n\
    \ * @brief extgcd() (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5)\n * ax + by = gcd(a, b) \u306E\u6574\u6570\u89E3 (x, y) \u3092\u5F15\
    \u6570\u306B\u683C\u7D0D\u3059\u308B\n */\ntemplate <class T>\nT extgcd(T a, T\
    \ b, T& x, T& y) {\n    T g = a;\n    if (b != 0) {\n        g = extgcd(b, a %\
    \ b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n       \
    \ y = 0;\n    }\n    return g;\n}\n#line 2 \"Util/int-alias.hpp\"\n#include <cstdint>\n\
    \n/**\n * @brief int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9\
    )\n */\nusing i64 = int64_t;\nusing u64 = uint64_t;\n#line 7 \"test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp\"\
    \n\nint main() {\n    i64 a, b, x, y;\n    std::cin >> a >> b;\n    extgcd(a,\
    \ b, x, y);\n    std::cout << x << ' ' << y << std::endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n\n#include \"../../Math/Number-Theory/extgcd.hpp\"\n\
    #include \"../../Util/int-alias.hpp\"\n\nint main() {\n    i64 a, b, x, y;\n \
    \   std::cin >> a >> b;\n    extgcd(a, b, x, y);\n    std::cout << x << ' ' <<\
    \ y << std::endl;\n\n    return 0;\n}"
  dependsOn:
  - Math/Number-Theory/extgcd.hpp
  - Util/int-alias.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp
  requiredBy: []
  timestamp: '2020-10-25 20:18:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp
- /verify/test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp.html
title: test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp
---
