---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Util/cstring-hash.hpp
    title: "cstringHash() \u30CC\u30EB\u6587\u5B57\u7D42\u7AEF\u3055\u308C\u305F\u6587\
      \u5B57\u5217\u304B\u308932bit\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u751F\u6210\
      \u3059\u308B(constexpr)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "constexprRandint() (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u4E71\
      \u6570)"
    links: []
  bundledCode: "#line 2 \"Util/constexpr-randint.hpp\"\n\n#include <cstdint>\n\n#line\
    \ 2 \"Util/cstring-hash.hpp\"\n\n#line 4 \"Util/cstring-hash.hpp\"\n\n/**\n *\
    \ @brief cstringHash() \u30CC\u30EB\u6587\u5B57\u7D42\u7AEF\u3055\u308C\u305F\u6587\
    \u5B57\u5217\u304B\u308932bit\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u751F\u6210\u3059\
    \u308B(constexpr)\n * @see https://en.wikipedia.org/wiki/Jenkins_hash_function\n\
    \ */\nconstexpr uint32_t cstringHash(const char* s) {\n    uint32_t hashv = 0;\n\
    \    while (*s != '\\0') {\n        hashv += *s++;\n        hashv += hashv <<\
    \ 10;\n        hashv ^= hashv >> 6;\n    }\n    hashv += hashv << 3;\n    hashv\
    \ ^= hashv >> 11;\n    hashv += hashv << 15;\n    return hashv;\n}\n#line 6 \"\
    Util/constexpr-randint.hpp\"\n\n/**\n * @brief constexprRandint() (\u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6642\u4E71\u6570)\n * \u547C\u3073\u51FA\u3059\u5EA6\u306B\
    \u5024\u304C\u5909\u308F\u308B\u308F\u3051\u3067\u306F\u306A\u3044\u306E\u3067\
    \ \u3046\u7B11\n */\n#define STRINGIZE_I(x) #x\n#define STRINGIZE(x) STRINGIZE_I(x)\n\
    #define UNIQUE_STRING __DATE__ \"_\" __TIME__ \"_\" __FILE__ \"_\" STRINGIZE(__LINE__)\n\
    \nconstexpr uint32_t constexprRandint(uint32_t min, uint32_t max) {\n    const\
    \ auto m = max - min + 1;\n    return cstringHash(UNIQUE_STRING) % m + min;\n\
    }\n"
  code: "#pragma once\n\n#include <cstdint>\n\n#include \"./cstring-hash.hpp\"\n\n\
    /**\n * @brief constexprRandint() (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u4E71\u6570\
    )\n * \u547C\u3073\u51FA\u3059\u5EA6\u306B\u5024\u304C\u5909\u308F\u308B\u308F\
    \u3051\u3067\u306F\u306A\u3044\u306E\u3067 \u3046\u7B11\n */\n#define STRINGIZE_I(x)\
    \ #x\n#define STRINGIZE(x) STRINGIZE_I(x)\n#define UNIQUE_STRING __DATE__ \"_\"\
    \ __TIME__ \"_\" __FILE__ \"_\" STRINGIZE(__LINE__)\n\nconstexpr uint32_t constexprRandint(uint32_t\
    \ min, uint32_t max) {\n    const auto m = max - min + 1;\n    return cstringHash(UNIQUE_STRING)\
    \ % m + min;\n}\n"
  dependsOn:
  - Util/cstring-hash.hpp
  isVerificationFile: false
  path: Util/constexpr-randint.hpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/constexpr-randint.hpp
layout: document
redirect_from:
- /library/Util/constexpr-randint.hpp
- /library/Util/constexpr-randint.hpp.html
title: "constexprRandint() (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u4E71\u6570)"
---
