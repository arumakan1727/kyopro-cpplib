---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data-Structure/Disjoint-Set/union-find.hpp
    title: "Union-Find (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020)"
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template (Edge, Graph, MatrixGraph)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
    title: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "kruskal() (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
    links: []
  bundledCode: "#line 2 \"Graph/Minimum-Spanning-Tree/kruskal.hpp\"\n#include <algorithm>\n\
    #include <vector>\n\n#line 2 \"Graph/graph-template.hpp\"\n#include <cstdint>\n\
    #line 4 \"Graph/graph-template.hpp\"\n#include <iostream>\n\n/**\n * @brief graph-template\
    \ (Edge, Graph, MatrixGraph)\n */\n//! \u30B0\u30E9\u30D5\u306E\u8FBA (\u91CD\u307F\
    \u4ED8\u304D)\ntemplate <class T>\nstruct Edge {\n    int from, to;\n    T weight;\n\
    \    int id;\n\n    Edge() = default;\n\n    constexpr explicit Edge(int to_,\
    \ const T& weight_)\n        : Edge(-1, to_, weight_, -1) {}\n\n    constexpr\
    \ Edge(int from_, int to_, const T& weight_, int id_ = -1)\n        : from(from_)\n\
    \        , to(to_)\n        , weight(weight_)\n        , id(id_) {}\n\n    constexpr\
    \ const Edge rev() const { return Edge(to, from, weight, id); }\n\n    template\
    \ <class Int, std::enable_if_t<std::is_integral<Int>::value, std::nullptr_t> =\
    \ nullptr>\n    constexpr operator Int() const {\n        return static_cast<Int>(to);\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& is, Edge& e) { return\
    \ is >> e.from >> e.to >> e.weight; }\n};\n\n//! \u30B0\u30E9\u30D5\u306E\u8FBA\
    \ (\u91CD\u307F\u306A\u3057)\ntemplate <>\nstruct Edge<void> {\n    int from,\
    \ to;\n    int id;\n\n    Edge() = default;\n\n    constexpr explicit Edge(int\
    \ to_)\n        : Edge(-1, to_, -1) {}\n\n    constexpr Edge(int from_, int to_,\
    \ int id_ = -1)\n        : from(from_)\n        , to(to_)\n        , id(id_) {}\n\
    \n    constexpr const Edge rev() const { return Edge(to, from, id); }\n\n    template\
    \ <class Int, std::enable_if_t<std::is_integral<Int>::value, std::nullptr_t> =\
    \ nullptr>\n    constexpr operator Int() const {\n        return static_cast<Int>(to);\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& is, Edge& e) { return\
    \ is >> e.from >> e.to; }\n};\n\ntemplate <class T>\nusing Graph = std::vector<std::vector<Edge<T>>>;\n\
    #line 2 \"Data-Structure/Disjoint-Set/union-find.hpp\"\n#include <cassert>\n#line\
    \ 5 \"Data-Structure/Disjoint-Set/union-find.hpp\"\n#include <utility>\n#line\
    \ 7 \"Data-Structure/Disjoint-Set/union-find.hpp\"\n\n/**\n * @brief Union-Find\
    \ (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020)\n * @note path-compression\
    \ + union-by-size\n */\nclass UnionFind {\nprivate:\n    int n;\n    mutable std::vector<int>\
    \ p;\n\npublic:\n    UnionFind() = default;\n\n    explicit UnionFind(int n_)\n\
    \        : n(n_)\n        , p(n_, -1) {}\n\n    int unite(int x, int y) {\n  \
    \      x = leader(x), y = leader(y);\n        if (x == y) return x;\n        if\
    \ (p[y] < p[x]) std::swap(x, y);\n        p[x] += p[y];\n        p[y] = x;\n \
    \       return x;\n    }\n\n    int leader(int x) const { return p[x] < 0 ? x\
    \ : p[x] = leader(p[x]); }\n\n    bool same(int x, int y) const { return leader(x)\
    \ == leader(y); }\n\n    int size(int x) const { return -p[leader(x)]; }\n\n \
    \   std::vector<std::vector<int>> groups() const {\n        std::vector<int> leaderBuf(n),\
    \ groupSize(n);\n        for (int i = 0; i < n; i++) ++groupSize[leaderBuf[i]\
    \ = leader(i)];\n\n        std::vector<std::vector<int>> result(n);\n        for\
    \ (int i = 0; i < n; i++) result[i].reserve(groupSize[i]);\n        for (int i\
    \ = 0; i < n; i++) result[leaderBuf[i]].push_back(i);\n        result.erase(std::remove_if(result.begin(),\
    \ result.end(), [](const std::vector<int>& v) { return v.empty(); }), result.end());\n\
    \        return result;\n    }\n};\n#line 7 \"Graph/Minimum-Spanning-Tree/kruskal.hpp\"\
    \n\n/**\n * @brief kruskal() (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)\n */\ntemplate\
    \ <class ResultType, class WeightType>\nResultType kruskal(int V, std::vector<Edge<WeightType>>&\
    \ edges) {\n    ResultType weightSum{};\n    UnionFind uf(V);\n    std::sort(edges.begin(),\
    \ edges.end(), [](const auto& e1, const auto& e2) {\n        return e1.weight\
    \ < e2.weight;\n    });\n    for (const auto &e : edges) {\n        if (uf.same(e.from,\
    \ e.to)) continue;\n        uf.unite(e.from, e.to);\n        weightSum += e.weight;\n\
    \    }\n    return weightSum;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n#include \"../graph-template.hpp\"\
    \n#include \"../../Data-Structure/Disjoint-Set/union-find.hpp\"\n\n/**\n * @brief\
    \ kruskal() (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)\n */\ntemplate <class ResultType,\
    \ class WeightType>\nResultType kruskal(int V, std::vector<Edge<WeightType>>&\
    \ edges) {\n    ResultType weightSum{};\n    UnionFind uf(V);\n    std::sort(edges.begin(),\
    \ edges.end(), [](const auto& e1, const auto& e2) {\n        return e1.weight\
    \ < e2.weight;\n    });\n    for (const auto &e : edges) {\n        if (uf.same(e.from,\
    \ e.to)) continue;\n        uf.unite(e.from, e.to);\n        weightSum += e.weight;\n\
    \    }\n    return weightSum;\n}\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Data-Structure/Disjoint-Set/union-find.hpp
  isVerificationFile: false
  path: Graph/Minimum-Spanning-Tree/kruskal.hpp
  requiredBy: []
  timestamp: '2020-10-25 20:18:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
documentation_of: Graph/Minimum-Spanning-Tree/kruskal.hpp
layout: document
redirect_from:
- /library/Graph/Minimum-Spanning-Tree/kruskal.hpp
- /library/Graph/Minimum-Spanning-Tree/kruskal.hpp.html
title: "kruskal() (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
---
