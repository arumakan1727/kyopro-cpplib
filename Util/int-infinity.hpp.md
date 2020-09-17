---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  - icon: ':warning:'
    path: Util/Debug/debug.hpp
    title: Debug
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
    links: []
  bundledCode: "#line 2 \"Util/int-infinity.hpp\"\n#include <cstdint>\n\n/**\n * @brief\
    \ int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)\n * 2\u500D\u3057\u3066\
    \u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 & memset()\u306B\
    \u3082\u4F7F\u3048\u308B (\u9700\u8981\u3042\u308B\uFF1F)\n */\nconstexpr std::int32_t\
    \ INF = 0x3f3f3f3f;\nconstexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n"
  code: "#pragma once\n#include <cstdint>\n\n/**\n * @brief int-infinity (\u6574\u6570\
    \u306E\u30C7\u30AB\u30A4\u5024)\n * 2\u500D\u3057\u3066\u3082\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 & memset()\u306B\u3082\u4F7F\u3048\u308B\
    \ (\u9700\u8981\u3042\u308B\uFF1F)\n */\nconstexpr std::int32_t INF = 0x3f3f3f3f;\n\
    constexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/int-infinity.hpp
  requiredBy:
  - export/template-prototype.cpp
  - Util/Debug/debug.hpp
  timestamp: '2020-09-17 10:59:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/int-infinity.hpp
layout: document
redirect_from:
- /library/Util/int-infinity.hpp
- /library/Util/int-infinity.hpp.html
title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
---
