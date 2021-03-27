---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0558-Cheese.test.cpp
    title: test/AOJ/0558-Cheese.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/helloworld/rolling-hash.test.cpp
    title: test/helloworld/rolling-hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "rep()\u30DE\u30AF\u30ED"
    links: []
  bundledCode: "#line 2 \"Util/rep-macro.hpp\"\n\n/**\n * @brief rep()\u30DE\u30AF\
    \u30ED\n */\n#define rep(i, begin, end) for (int64_t i = (begin), i##_end = (end);\
    \ i < i##_end; ++i)\n#define repc(i, begin, last) for (int64_t i = (begin), i##_last\
    \ = (last); i <= i##_last; ++i)\n#define repr(i, begin, last) for (int64_t i =\
    \ (begin), i##_last = (last); i >= i##_last; --i)\n"
  code: "#pragma once\n\n/**\n * @brief rep()\u30DE\u30AF\u30ED\n */\n#define rep(i,\
    \ begin, end) for (int64_t i = (begin), i##_end = (end); i < i##_end; ++i)\n#define\
    \ repc(i, begin, last) for (int64_t i = (begin), i##_last = (last); i <= i##_last;\
    \ ++i)\n#define repr(i, begin, last) for (int64_t i = (begin), i##_last = (last);\
    \ i >= i##_last; --i)\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/rep-macro.hpp
  requiredBy:
  - export/template-prototype.cpp
  timestamp: '2021-03-27 22:16:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/0558-Cheese.test.cpp
  - test/helloworld/rolling-hash.test.cpp
documentation_of: Util/rep-macro.hpp
layout: document
redirect_from:
- /library/Util/rep-macro.hpp
- /library/Util/rep-macro.hpp.html
title: "rep()\u30DE\u30AF\u30ED"
---
