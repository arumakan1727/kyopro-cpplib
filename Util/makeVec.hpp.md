---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210)"
    links: []
  bundledCode: "#line 2 \"Util/makeVec.hpp\"\n#include <vector>\n\n/**\n * @brief\
    \ makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210)\n */\ntemplate <class\
    \ T>\ninline std::vector<T> makeVec(const T& initValue, size_t sz) {\n    return\
    \ std::vector<T>(sz, initValue);\n}\ntemplate <class T, class... Args>\ninline\
    \ auto makeVec(const T& initValue, size_t sz, Args... args) {\n    return std::vector<decltype(makeVec<T>(initValue,\
    \ args...))>(sz, makeVec<T>(initValue, args...));\n}\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief makeVec() (\u591A\u6B21\
    \u5143std::vector\u306E\u751F\u6210)\n */\ntemplate <class T>\ninline std::vector<T>\
    \ makeVec(const T& initValue, size_t sz) {\n    return std::vector<T>(sz, initValue);\n\
    }\ntemplate <class T, class... Args>\ninline auto makeVec(const T& initValue,\
    \ size_t sz, Args... args) {\n    return std::vector<decltype(makeVec<T>(initValue,\
    \ args...))>(sz, makeVec<T>(initValue, args...));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/makeVec.hpp
  requiredBy: []
  timestamp: '2020-09-08 04:00:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/makeVec.hpp
layout: document
redirect_from:
- /library/Util/makeVec.hpp
- /library/Util/makeVec.hpp.html
title: "makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210)"
---
