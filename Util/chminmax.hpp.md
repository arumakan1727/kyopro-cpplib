---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest-Path/dijkstra.hpp
    title: "dijkstra() (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9, $O((V + E)\\log V)$)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1501-Grid.test.cpp
    title: test/AOJ/1501-Grid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
    title: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: chmin(), chmax()
    links: []
  bundledCode: "#line 2 \"Util/chminmax.hpp\"\n\n/**\n * @brief chmin(), chmax()\n\
    \ */\ntemplate <class T, class U>\ninline bool chmin(T& a, const U& b) {\n   \
    \ return b < a && (a = b, true);\n}\n\ntemplate <class T, class U>\ninline bool\
    \ chmax(T& a, const U& b) {\n    return b > a && (a = b, true);\n}\n"
  code: "#pragma once\n\n/**\n * @brief chmin(), chmax()\n */\ntemplate <class T,\
    \ class U>\ninline bool chmin(T& a, const U& b) {\n    return b < a && (a = b,\
    \ true);\n}\n\ntemplate <class T, class U>\ninline bool chmax(T& a, const U& b)\
    \ {\n    return b > a && (a = b, true);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/chminmax.hpp
  requiredBy:
  - export/template-prototype.cpp
  - Graph/Shortest-Path/dijkstra.hpp
  timestamp: '2020-09-08 04:00:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1501-Grid.test.cpp
  - test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
documentation_of: Util/chminmax.hpp
layout: document
redirect_from:
- /library/Util/chminmax.hpp
- /library/Util/chminmax.hpp.html
title: chmin(), chmax()
---
