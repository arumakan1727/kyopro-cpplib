---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/is-prime.hpp
    title: "isPrime() (\u7D20\u6570\u5224\u5B9A $O(\\sqrt n)$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n\n#include\
    \ <iostream>\n\n#line 2 \"Math/Number-Theory/is-prime.hpp\"\n#include <cstdint>\n\
    \n/**\n * @brief isPrime() (\u7D20\u6570\u5224\u5B9A $O(\\sqrt n)$)\n */\nbool\
    \ isPrime(int64_t n) {\n    if (n == 2) return true;\n    if (n <= 1 || n % 2\
    \ == 0) return false;\n    for (int64_t i = 3; i * i <= n; i += 2) {\n       \
    \ if (n % i == 0) return false;\n    }\n    return true;\n}\n#line 6 \"test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \n    int N;\n    std::cin >> N;\n\n    int ans = 0;\n    while (N--) {\n    \
    \    int x;\n        std::cin >> x;\n        if (isPrime(x)) ++ans;\n    }\n\n\
    \    std::cout << ans << std::endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <iostream>\n\n#include \"../../Math/Number-Theory/is-prime.hpp\"\n\
    \nint main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \n    int N;\n    std::cin >> N;\n\n    int ans = 0;\n    while (N--) {\n    \
    \    int x;\n        std::cin >> x;\n        if (isPrime(x)) ++ans;\n    }\n\n\
    \    std::cout << ans << std::endl;\n\n    return 0;\n}\n"
  dependsOn:
  - Math/Number-Theory/is-prime.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 10:59:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp
- /verify/test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp.html
title: test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp
---
