---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1501-Grid.test.cpp
    title: test/AOJ/1501-Grid.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u8907\u6570\u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\u6642\
      \u306B\u5165\u529B\u3082\u3059\u308B\u3084\u3064"
    links: []
  bundledCode: "#line 2 \"Util/IO/var-declaration-with-input.hpp\"\n#include <iostream>\n\
    \n/**\n * @brief \u8907\u6570\u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\u6642\
    \u306B\u5165\u529B\u3082\u3059\u308B\u3084\u3064\n */\ntemplate <class T>\nstd::istream&\
    \ operator,(std::istream& is, T& rhs) {\n    return is >> rhs;\n}\n\n#define var(type,\
    \ ...) \\\n    type __VA_ARGS__;  \\\n    std::cin >> __VA_ARGS__\n"
  code: "#pragma once\n#include <iostream>\n\n/**\n * @brief \u8907\u6570\u5909\u6570\
    \u5BA3\u8A00\u3092\u3057\u3066\u540C\u6642\u306B\u5165\u529B\u3082\u3059\u308B\
    \u3084\u3064\n */\ntemplate <class T>\nstd::istream& operator,(std::istream& is,\
    \ T& rhs) {\n    return is >> rhs;\n}\n\n#define var(type, ...) \\\n    type __VA_ARGS__;\
    \  \\\n    std::cin >> __VA_ARGS__\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/IO/var-declaration-with-input.hpp
  requiredBy:
  - export/template-prototype.cpp
  timestamp: '2020-09-08 04:00:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1501-Grid.test.cpp
documentation_of: Util/IO/var-declaration-with-input.hpp
layout: document
redirect_from:
- /library/Util/IO/var-declaration-with-input.hpp
- /library/Util/IO/var-declaration-with-input.hpp.html
title: "\u8907\u6570\u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\u6642\u306B\u5165\
  \u529B\u3082\u3059\u308B\u3084\u3064"
---
