---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  - icon: ':heavy_check_mark:'
    path: Util/Debug/debug.hpp
    title: Debug
  - icon: ':warning:'
    path: Util/Debug/graph-debug.hpp
    title: "graph-debug (\u30B0\u30E9\u30D5\u306E\u30C7\u30D0\u30C3\u30B0\u51FA\u529B\
      )"
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest-Path/bfs.hpp
    title: "bfs() (\u5E45\u512A\u5148\u63A2\u7D22\u306B\u3088\u308B\u5358\u4E00\u59CB\
      \u70B9\u6700\u77ED\u7D4C\u8DEF, \u6B21\u5143\u62E1\u5F35\u306B\u5BFE\u5FDC)"
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest-Path/dijkstra.hpp
    title: "dijkstra() (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9, $O((V + E)\\log V)$)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
    title: test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0558-Cheese.test.cpp
    title: test/AOJ/0558-Cheese.test.cpp
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
  - Util/Debug/graph-debug.hpp
  - Graph/Shortest-Path/bfs.hpp
  - Graph/Shortest-Path/dijkstra.hpp
  timestamp: '2020-09-17 10:59:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
  - test/AOJ/0558-Cheese.test.cpp
  - test/AOJ/1501-Grid.test.cpp
  - test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
documentation_of: Util/int-infinity.hpp
layout: document
redirect_from:
- /library/Util/int-infinity.hpp
- /library/Util/int-infinity.hpp.html
title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
---
