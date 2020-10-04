---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/helloworld/fix-point.test.cpp
    title: test/helloworld/fix-point.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "FixPoint (\u30E9\u30E0\u30C0\u5F0F\u306E\u518D\u5E30)"
    links: []
  bundledCode: "#line 2 \"Util/fix-point.hpp\"\n#include <functional>\n\n/**\n * @brief\
    \ FixPoint (\u30E9\u30E0\u30C0\u5F0F\u306E\u518D\u5E30)\n */\n// Ex) FixPoint([&](auto\
    \ func, int n) -> int {...})(10);\ntemplate <class F>\nstruct FixPoint : F {\n\
    \    FixPoint(F&& f)\n        : F(std::forward<F>(f)) {}\n\n    template <class...\
    \ Args>\n    decltype(auto) operator()(Args&&... args) const {\n        return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n"
  code: "#pragma once\n#include <functional>\n\n/**\n * @brief FixPoint (\u30E9\u30E0\
    \u30C0\u5F0F\u306E\u518D\u5E30)\n */\n// Ex) FixPoint([&](auto func, int n) ->\
    \ int {...})(10);\ntemplate <class F>\nstruct FixPoint : F {\n    FixPoint(F&&\
    \ f)\n        : F(std::forward<F>(f)) {}\n\n    template <class... Args>\n   \
    \ decltype(auto) operator()(Args&&... args) const {\n        return F::operator()(*this,\
    \ std::forward<Args>(args)...);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/fix-point.hpp
  requiredBy: []
  timestamp: '2020-09-25 14:35:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/helloworld/fix-point.test.cpp
documentation_of: Util/fix-point.hpp
layout: document
redirect_from:
- /library/Util/fix-point.hpp
- /library/Util/fix-point.hpp.html
title: "FixPoint (\u30E9\u30E0\u30C0\u5F0F\u306E\u518D\u5E30)"
---
