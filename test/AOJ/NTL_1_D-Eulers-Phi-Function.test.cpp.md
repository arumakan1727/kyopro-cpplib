---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/totient-func.hpp
    title: "totient() (\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\
      \u30C8\u95A2\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include <iostream>\n\n#line 2 \"Math/Number-Theory/totient-func.hpp\"\n\n\
    /**\n * @brief totient() (\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\
    \u30F3\u30C8\u95A2\u6570)\n */\ntemplate <class Integer>\nconstexpr Integer totient(Integer\
    \ n) {\n    Integer ret = n;\n    for (Integer i = 2; i * i <= n; ++i) {\n   \
    \     if (n % i == 0) {\n            ret -= ret / i;\n            while (n % i\
    \ == 0) n /= i;\n        }\n    }\n    if (n != 1) ret -= ret / n;\n    return\
    \ ret;\n}\n#line 6 \"test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::cout << totient(n) << std::endl;\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include <iostream>\n\n#include \"../../Math/Number-Theory/totient-func.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::cout << totient(n)\
    \ << std::endl;\n\n    return 0;\n}\n"
  dependsOn:
  - Math/Number-Theory/totient-func.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:43:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp
- /verify/test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp.html
title: test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp
---
