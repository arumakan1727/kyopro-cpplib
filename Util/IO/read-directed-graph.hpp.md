---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template (Edge, Graph, MatrixGraph)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
    title: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "readDirectedGraph() (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5165\
      \u529B)"
    links: []
  bundledCode: "#line 2 \"Util/IO/read-directed-graph.hpp\"\n#include <cstdint>\n\
    #include <iostream>\n\n#line 3 \"Graph/graph-template.hpp\"\n#include <vector>\n\
    #line 5 \"Graph/graph-template.hpp\"\n\n/**\n * @brief graph-template (Edge, Graph,\
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
    \u30C8\u5B9F\u88C5)\ntemplate <class T>\nusing Graph = std::vector<std::vector<Edge<T>>>;\n\
    #line 6 \"Util/IO/read-directed-graph.hpp\"\n\n/**\n * @brief readDirectedGraph()\
    \ (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5165\u529B)\n */\ntemplate <class T>\n\
    Graph<T> readDirectedGraph(std::size_t V, std::size_t E, int padding = -1, std::istream&\
    \ is = std::cin) {\n    Graph<T> G(V);\n    for (std::size_t i = 0; i < E; ++i)\
    \ {\n        Edge<T> e;\n        is >> e;\n        e.from += padding, e.to +=\
    \ padding;\n        e.id = static_cast<int>(i);\n        G[e.from].emplace_back(e);\n\
    \    }\n    return G;\n}\n\n"
  code: "#pragma once\n#include <cstdint>\n#include <iostream>\n\n#include \"../../Graph/graph-template.hpp\"\
    \n\n/**\n * @brief readDirectedGraph() (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5165\
    \u529B)\n */\ntemplate <class T>\nGraph<T> readDirectedGraph(std::size_t V, std::size_t\
    \ E, int padding = -1, std::istream& is = std::cin) {\n    Graph<T> G(V);\n  \
    \  for (std::size_t i = 0; i < E; ++i) {\n        Edge<T> e;\n        is >> e;\n\
    \        e.from += padding, e.to += padding;\n        e.id = static_cast<int>(i);\n\
    \        G[e.from].emplace_back(e);\n    }\n    return G;\n}\n\n"
  dependsOn:
  - Graph/graph-template.hpp
  isVerificationFile: false
  path: Util/IO/read-directed-graph.hpp
  requiredBy: []
  timestamp: '2020-09-25 23:46:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
documentation_of: Util/IO/read-directed-graph.hpp
layout: document
redirect_from:
- /library/Util/IO/read-directed-graph.hpp
- /library/Util/IO/read-directed-graph.hpp.html
title: "readDirectedGraph() (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5165\u529B)"
---
