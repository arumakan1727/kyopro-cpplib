---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/rolling-hash.test.cpp
    title: test/unittest/rolling-hash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "rep()\u30DE\u30AF\u30ED"
    links: []
  bundledCode: "#line 2 \"Util/rep-macro.hpp\"\n\n/**\n * @brief rep()\u30DE\u30AF\
    \u30ED\n */\n#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_end = (end); i < i##_end; ++i)\n#define repc(i, begin, last)\
    \ for (std::make_signed_t<std::remove_cv_t<decltype(last)>> i = (begin), i##_last\
    \ = (last); i <= i##_last; ++i)\n#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(begin)>>\
    \ i = (begin), i##_last = (last); i >= i##_last; --i)\n"
  code: "#pragma once\n\n/**\n * @brief rep()\u30DE\u30AF\u30ED\n */\n#define rep(i,\
    \ begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin),\
    \ i##_end = (end); i < i##_end; ++i)\n#define repc(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(last)>>\
    \ i = (begin), i##_last = (last); i <= i##_last; ++i)\n#define repr(i, begin,\
    \ last) for (std::make_signed_t<std::remove_cv_t<decltype(begin)>> i = (begin),\
    \ i##_last = (last); i >= i##_last; --i)\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/rep-macro.hpp
  requiredBy:
  - export/template-prototype.cpp
  timestamp: '2020-09-20 14:50:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/rolling-hash.test.cpp
documentation_of: Util/rep-macro.hpp
layout: document
redirect_from:
- /library/Util/rep-macro.hpp
- /library/Util/rep-macro.hpp.html
title: "rep()\u30DE\u30AF\u30ED"
---
