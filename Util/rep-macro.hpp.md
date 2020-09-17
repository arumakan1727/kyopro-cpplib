---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "rep()\u30DE\u30AF\u30ED"
    links: []
  bundledCode: "#line 2 \"Util/rep-macro.hpp\"\n\n/**\n * @brief rep()\u30DE\u30AF\
    \u30ED\n */\n#define rep(i, begin, end) for (int64_t i{begin}, i##_end{end}; i\
    \ < i##_end; ++i)\n#define repc(i, begin, last) for (int64_t i{begin}, i##_last{last};\
    \ i <= i##_last; ++i)\n#define repr(i, begin, last) for (int64_t i{begin}, i##_last{last};\
    \ i >= i##_last; --i)\n"
  code: "#pragma once\n\n/**\n * @brief rep()\u30DE\u30AF\u30ED\n */\n#define rep(i,\
    \ begin, end) for (int64_t i{begin}, i##_end{end}; i < i##_end; ++i)\n#define\
    \ repc(i, begin, last) for (int64_t i{begin}, i##_last{last}; i <= i##_last; ++i)\n\
    #define repr(i, begin, last) for (int64_t i{begin}, i##_last{last}; i >= i##_last;\
    \ --i)\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/rep-macro.hpp
  requiredBy:
  - export/template-prototype.cpp
  timestamp: '2020-09-08 04:00:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/rep-macro.hpp
layout: document
redirect_from:
- /library/Util/rep-macro.hpp
- /library/Util/rep-macro.hpp.html
title: "rep()\u30DE\u30AF\u30ED"
---
