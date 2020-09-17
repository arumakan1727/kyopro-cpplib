---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "enumerateDivisors() (\u7D04\u6570\u5217\u6319)"
    links: []
  bundledCode: "#line 2 \"Math/Number-Theory/enumerate-divisors.hpp\"\n#include <cstdint>\n\
    #include <algorithm>\n#include <vector>\n\n/**\n * @brief enumerateDivisors()\
    \ (\u7D04\u6570\u5217\u6319)\n */\ntemplate <class Integer>\nstd::vector<Integer>\
    \ enumerateDivisors(Integer n) {\n    std::vector<Integer> divisors;\n    Integer\
    \ i;\n    for (i = 1; i * i < n; ++i) {\n        if (n % i == 0) divisors.push_back(i),\
    \ divisors.push_back(n / i);\n    }\n    if (i * i == n) divisors.push_back(i);\n\
    \    std::sort(divisors.begin(), divisors.end());\n    return divisors;\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <algorithm>\n#include <vector>\n\
    \n/**\n * @brief enumerateDivisors() (\u7D04\u6570\u5217\u6319)\n */\ntemplate\
    \ <class Integer>\nstd::vector<Integer> enumerateDivisors(Integer n) {\n    std::vector<Integer>\
    \ divisors;\n    Integer i;\n    for (i = 1; i * i < n; ++i) {\n        if (n\
    \ % i == 0) divisors.push_back(i), divisors.push_back(n / i);\n    }\n    if (i\
    \ * i == n) divisors.push_back(i);\n    std::sort(divisors.begin(), divisors.end());\n\
    \    return divisors;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Number-Theory/enumerate-divisors.hpp
  requiredBy: []
  timestamp: '2020-09-13 11:30:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Number-Theory/enumerate-divisors.hpp
layout: document
redirect_from:
- /library/Math/Number-Theory/enumerate-divisors.hpp
- /library/Math/Number-Theory/enumerate-divisors.hpp.html
title: "enumerateDivisors() (\u7D04\u6570\u5217\u6319)"
---
