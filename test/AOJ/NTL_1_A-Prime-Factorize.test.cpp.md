---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/prime-factorize.hpp
    title: "primeFactorize() (\u7D20\u56E0\u6570\u5206\u89E3 $O(\\sqrt n)$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/AOJ/NTL_1_A-Prime-Factorize.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\n\n#include\
    \ <iostream>\n\n#line 2 \"Math/Number-Theory/prime-factorize.hpp\"\n#include <map>\n\
    \n/**\n * @brief primeFactorize() (\u7D20\u56E0\u6570\u5206\u89E3 $O(\\sqrt n)$)\n\
    \ */\ntemplate <class Integer>\nstd::map<Integer, int> primeFactorize(Integer\
    \ n) {\n    std::map<Integer, int> res;\n    for (Integer i = 2; i * i <= n; ++i)\
    \ {\n        while (n % i == 0) {\n            ++res[i];\n            n /= i;\n\
    \        }\n    }\n    if (n != 1) res[n] = 1;\n    return res;\n}\n#line 6 \"\
    test/AOJ/NTL_1_A-Prime-Factorize.test.cpp\"\n\nusing namespace std;\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n\n    cout << n << \":\";\n\n    for (const auto\
    \ [value, cnt] : primeFactorize(n)) {\n        for (int i = 0; i < cnt; ++i) cout\
    \ << ' ' << value;\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#include <iostream>\n\n#include \"../../Math/Number-Theory/prime-factorize.hpp\"\
    \n\nusing namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n\n    cout\
    \ << n << \":\";\n\n    for (const auto [value, cnt] : primeFactorize(n)) {\n\
    \        for (int i = 0; i < cnt; ++i) cout << ' ' << value;\n    }\n    cout\
    \ << endl;\n}"
  dependsOn:
  - Math/Number-Theory/prime-factorize.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_A-Prime-Factorize.test.cpp
  requiredBy: []
  timestamp: '2020-09-13 11:30:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_A-Prime-Factorize.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_A-Prime-Factorize.test.cpp
- /verify/test/AOJ/NTL_1_A-Prime-Factorize.test.cpp.html
title: test/AOJ/NTL_1_A-Prime-Factorize.test.cpp
---
