---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Minimum-Spanning-Tree/kruskal.hpp
    title: "kruskal() (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':warning:'
    path: Util/Debug/graph-debug.hpp
    title: "graph-debug (\u30B0\u30E9\u30D5\u306E\u30C7\u30D0\u30C3\u30B0\u51FA\u529B\
      )"
  - icon: ':heavy_check_mark:'
    path: Util/IO/read-directed-graph.hpp
    title: "readDirectedGraph() (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5165\u529B)"
  - icon: ':warning:'
    path: Util/IO/read-undirected-graph.hpp
    title: "readUndirectedGraph() (\u7121\u5411\u30B0\u30E9\u30D5\u306E\u5165\u529B\
      )"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
    title: test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
    title: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
    title: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: graph-template (Edge, Graph, MatrixGraph)
    links: []
  bundledCode: "#line 2 \"Graph/graph-template.hpp\"\n#include <cstdint>\n#include\
    \ <vector>\n#include <iostream>\n\n/**\n * @brief graph-template (Edge, Graph,\
    \ MatrixGraph)\n */\n// \u30B0\u30E9\u30D5\u306E\u8FBA (\u91CD\u307F\u4ED8\u304D\
    )\ntemplate <class T>\nstruct Edge {\n    int from, to;\n    T weight;\n    int\
    \ id;\n\n    Edge() = default;\n\n    constexpr explicit Edge(int to_, const T&\
    \ weight_)\n        : Edge(-1, to_, weight_, -1) {}\n\n    constexpr Edge(int\
    \ from_, int to_, const T& weight_, int id_ = -1)\n        : from(from_)\n   \
    \     , to(to_)\n        , weight(weight_)\n        , id(id_) {}\n\n    constexpr\
    \ const Edge rev() const { return Edge(to, from, weight, id); }\n\n    template\
    \ <class Int, std::enable_if_t<std::is_integral<Int>::value, std::nullptr_t> =\
    \ nullptr>\n    constexpr operator Int() const {\n        return static_cast<Int>(to);\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& is, Edge& e) { return\
    \ is >> e.from >> e.to >> e.weight; }\n};\n\n// \u30B0\u30E9\u30D5\u306E\u8FBA\
    \ (\u91CD\u307F\u30CA\u30B7)\ntemplate <>\nstruct Edge<void> {\n    int from,\
    \ to;\n    int id;\n\n    Edge() = default;\n\n    constexpr explicit Edge(int\
    \ to_)\n        : Edge(-1, to_, -1) {}\n\n    constexpr Edge(int from_, int to_,\
    \ int id_ = -1)\n        : from(from_)\n        , to(to_)\n        , id(id_) {}\n\
    \n    constexpr const Edge rev() const { return Edge(to, from, id); }\n\n    template\
    \ <class Int, std::enable_if_t<std::is_integral<Int>::value, std::nullptr_t> =\
    \ nullptr>\n    constexpr operator Int() const {\n        return static_cast<Int>(to);\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& is, Edge& e) { return\
    \ is >> e.from >> e.to; }\n};\n\n// \u30B0\u30E9\u30D5 (\u96A3\u63A5\u30EA\u30B9\
    \u30C8\u5B9F\u88C5)\ntemplate <class T>\nusing Graph = std::vector<std::vector<Edge<T>>>;\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n#include <iostream>\n\
    \n/**\n * @brief graph-template (Edge, Graph, MatrixGraph)\n */\n// \u30B0\u30E9\
    \u30D5\u306E\u8FBA (\u91CD\u307F\u4ED8\u304D)\ntemplate <class T>\nstruct Edge\
    \ {\n    int from, to;\n    T weight;\n    int id;\n\n    Edge() = default;\n\n\
    \    constexpr explicit Edge(int to_, const T& weight_)\n        : Edge(-1, to_,\
    \ weight_, -1) {}\n\n    constexpr Edge(int from_, int to_, const T& weight_,\
    \ int id_ = -1)\n        : from(from_)\n        , to(to_)\n        , weight(weight_)\n\
    \        , id(id_) {}\n\n    constexpr const Edge rev() const { return Edge(to,\
    \ from, weight, id); }\n\n    template <class Int, std::enable_if_t<std::is_integral<Int>::value,\
    \ std::nullptr_t> = nullptr>\n    constexpr operator Int() const {\n        return\
    \ static_cast<Int>(to);\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, Edge& e) { return is >> e.from >> e.to >> e.weight; }\n};\n\n// \u30B0\u30E9\
    \u30D5\u306E\u8FBA (\u91CD\u307F\u30CA\u30B7)\ntemplate <>\nstruct Edge<void>\
    \ {\n    int from, to;\n    int id;\n\n    Edge() = default;\n\n    constexpr\
    \ explicit Edge(int to_)\n        : Edge(-1, to_, -1) {}\n\n    constexpr Edge(int\
    \ from_, int to_, int id_ = -1)\n        : from(from_)\n        , to(to_)\n  \
    \      , id(id_) {}\n\n    constexpr const Edge rev() const { return Edge(to,\
    \ from, id); }\n\n    template <class Int, std::enable_if_t<std::is_integral<Int>::value,\
    \ std::nullptr_t> = nullptr>\n    constexpr operator Int() const {\n        return\
    \ static_cast<Int>(to);\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, Edge& e) { return is >> e.from >> e.to; }\n};\n\n// \u30B0\u30E9\u30D5 (\u96A3\
    \u63A5\u30EA\u30B9\u30C8\u5B9F\u88C5)\ntemplate <class T>\nusing Graph = std::vector<std::vector<Edge<T>>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/graph-template.hpp
  requiredBy:
  - Util/Debug/graph-debug.hpp
  - Util/IO/read-directed-graph.hpp
  - Util/IO/read-undirected-graph.hpp
  - Graph/Minimum-Spanning-Tree/kruskal.hpp
  timestamp: '2020-09-25 22:23:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
  - test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
  - test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
documentation_of: Graph/graph-template.hpp
layout: document
redirect_from:
- /library/Graph/graph-template.hpp
- /library/Graph/graph-template.hpp.html
title: graph-template (Edge, Graph, MatrixGraph)
---
