---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0558-Cheese.test.cpp
    title: test/AOJ/0558-Cheese.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210)"
    links: []
  bundledCode: "#line 2 \"Util/makeVec.hpp\"\n#include <vector>\n\n/**\n * @brief\
    \ makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210)\n */\ntemplate <class\
    \ T>\ninline std::vector<T> makeVec(std::size_t sz, const T& initValue) {\n  \
    \  return std::vector<T>(sz, initValue);\n}\ntemplate <class T, class... Args>\n\
    inline auto makeVec(size_t sz, Args... args) {\n    return std::vector<decltype(makeVec<T>(args...))>(sz,\
    \ makeVec<T>(args...));\n}\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief makeVec() (\u591A\u6B21\
    \u5143std::vector\u306E\u751F\u6210)\n */\ntemplate <class T>\ninline std::vector<T>\
    \ makeVec(std::size_t sz, const T& initValue) {\n    return std::vector<T>(sz,\
    \ initValue);\n}\ntemplate <class T, class... Args>\ninline auto makeVec(size_t\
    \ sz, Args... args) {\n    return std::vector<decltype(makeVec<T>(args...))>(sz,\
    \ makeVec<T>(args...));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/makeVec.hpp
  requiredBy: []
  timestamp: '2020-09-25 22:19:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/0558-Cheese.test.cpp
documentation_of: Util/makeVec.hpp
layout: document
redirect_from:
- /library/Util/makeVec.hpp
- /library/Util/makeVec.hpp.html
title: "makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210)"
---
