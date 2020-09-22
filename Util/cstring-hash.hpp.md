---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Util/constexpr-randint.hpp
    title: "constexprRandint() (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u4E71\u6570)"
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "cstringHash() \u30CC\u30EB\u6587\u5B57\u7D42\u7AEF\u3055\u308C\
      \u305F\u6587\u5B57\u5217\u304B\u308932bit\u30CF\u30C3\u30B7\u30E5\u5024\u3092\
      \u751F\u6210\u3059\u308B(constexpr)"
    links:
    - https://en.wikipedia.org/wiki/Jenkins_hash_function
  bundledCode: "#line 2 \"Util/cstring-hash.hpp\"\n\n#include <cstdint>\n\n/**\n *\
    \ @brief cstringHash() \u30CC\u30EB\u6587\u5B57\u7D42\u7AEF\u3055\u308C\u305F\u6587\
    \u5B57\u5217\u304B\u308932bit\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u751F\u6210\u3059\
    \u308B(constexpr)\n * @see https://en.wikipedia.org/wiki/Jenkins_hash_function\n\
    \ */\nconstexpr std::uint32_t cstringHash(const char* s) {\n    std::uint32_t\
    \ hashv = 0;\n    while (*s != '\\0') {\n        hashv += *s++;\n        hashv\
    \ += hashv << 10;\n        hashv ^= hashv >> 6;\n    }\n    hashv += hashv <<\
    \ 3;\n    hashv ^= hashv >> 11;\n    hashv += hashv << 15;\n    return hashv;\n\
    }\n"
  code: "#pragma once\n\n#include <cstdint>\n\n/**\n * @brief cstringHash() \u30CC\
    \u30EB\u6587\u5B57\u7D42\u7AEF\u3055\u308C\u305F\u6587\u5B57\u5217\u304B\u3089\
    32bit\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u751F\u6210\u3059\u308B(constexpr)\n\
    \ * @see https://en.wikipedia.org/wiki/Jenkins_hash_function\n */\nconstexpr std::uint32_t\
    \ cstringHash(const char* s) {\n    std::uint32_t hashv = 0;\n    while (*s !=\
    \ '\\0') {\n        hashv += *s++;\n        hashv += hashv << 10;\n        hashv\
    \ ^= hashv >> 6;\n    }\n    hashv += hashv << 3;\n    hashv ^= hashv >> 11;\n\
    \    hashv += hashv << 15;\n    return hashv;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/cstring-hash.hpp
  requiredBy:
  - Util/constexpr-randint.hpp
  timestamp: '2020-09-22 21:55:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/cstring-hash.hpp
layout: document
redirect_from:
- /library/Util/cstring-hash.hpp
- /library/Util/cstring-hash.hpp.html
title: "cstringHash() \u30CC\u30EB\u6587\u5B57\u7D42\u7AEF\u3055\u308C\u305F\u6587\
  \u5B57\u5217\u304B\u308932bit\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u751F\u6210\u3059\
  \u308B(constexpr)"
---
