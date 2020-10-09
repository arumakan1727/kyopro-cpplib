---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data-Structure/Disjoint-Set/union-find.hpp
    title: "Union-Find (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020)"
  - icon: ':heavy_check_mark:'
    path: Graph/Minimum-Spanning-Tree/kruskal.hpp
    title: "kruskal() (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template (Edge, Graph, MatrixGraph)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
  bundledCode: "#line 1 \"test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp\"\
    \n#include <iostream>\n\n#line 2 \"Graph/graph-template.hpp\"\n#include <cstdint>\n\
    #include <vector>\n#line 5 \"Graph/graph-template.hpp\"\n\n/**\n * @brief graph-template\
    \ (Edge, Graph, MatrixGraph)\n */\n// \u30B0\u30E9\u30D5\u306E\u8FBA (\u91CD\u307F\
    \u4ED8\u304D)\ntemplate <class T>\nstruct Edge {\n    int from, to;\n    T weight;\n\
    \    int id;\n\n    Edge() = default;\n\n    constexpr explicit Edge(int to_,\
    \ const T& weight_)\n        : Edge(-1, to_, weight_, -1) {}\n\n    constexpr\
    \ Edge(int from_, int to_, const T& weight_, int id_ = -1)\n        : from(from_)\n\
    \        , to(to_)\n        , weight(weight_)\n        , id(id_) {}\n\n    constexpr\
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
    #line 2 \"Graph/Minimum-Spanning-Tree/kruskal.hpp\"\n#include <algorithm>\n#line\
    \ 4 \"Graph/Minimum-Spanning-Tree/kruskal.hpp\"\n\n#line 2 \"Data-Structure/Disjoint-Set/union-find.hpp\"\
    \n#include <cassert>\n#line 5 \"Data-Structure/Disjoint-Set/union-find.hpp\"\n\
    #include <utility>\n#line 7 \"Data-Structure/Disjoint-Set/union-find.hpp\"\n\n\
    /**\n * @brief Union-Find (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020)\n\
    \ * @note path-compression + union-by-size\n */\nclass UnionFind {\nprivate:\n\
    \    int n;\n    mutable std::vector<int> p;\n\npublic:\n    UnionFind() = default;\n\
    \n    explicit UnionFind(int n_)\n        : n(n_)\n        , p(n_, -1) {}\n\n\
    \    int unite(int x, int y) {\n        x = leader(x), y = leader(y);\n      \
    \  if (x == y) return x;\n        if (p[y] < p[x]) std::swap(x, y);\n        p[x]\
    \ += p[y];\n        p[y] = x;\n        return x;\n    }\n\n    int leader(int\
    \ x) const { return p[x] < 0 ? x : p[x] = leader(p[x]); }\n\n    bool same(int\
    \ x, int y) const { return leader(x) == leader(y); }\n\n    int size(int x) const\
    \ { return -p[leader(x)]; }\n\n    std::vector<std::vector<int>> groups() const\
    \ {\n        std::vector<int> leaderBuf(n), groupSize(n);\n        for (int i\
    \ = 0; i < n; i++) ++groupSize[leaderBuf[i] = leader(i)];\n\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) result[i].reserve(groupSize[i]);\n\
    \        for (int i = 0; i < n; i++) result[leaderBuf[i]].push_back(i);\n    \
    \    result.erase(std::remove_if(result.begin(), result.end(), [](const std::vector<int>&\
    \ v) { return v.empty(); }), result.end());\n        return result;\n    }\n};\n\
    #line 7 \"Graph/Minimum-Spanning-Tree/kruskal.hpp\"\n\n/**\n * @brief kruskal()\
    \ (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)\n */\ntemplate <class ResultType, class\
    \ WeightType>\nResultType kruskal(int V, std::vector<Edge<WeightType>>& edges)\
    \ {\n    ResultType weightSum{};\n    UnionFind uf(V);\n    std::sort(edges.begin(),\
    \ edges.end(), [](const auto& e1, const auto& e2) {\n        return e1.weight\
    \ < e2.weight;\n    });\n    for (const auto &e : edges) {\n        if (uf.same(e.from,\
    \ e.to)) continue;\n        uf.unite(e.from, e.to);\n        weightSum += e.weight;\n\
    \    }\n    return weightSum;\n}\n#line 6 \"test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \n    int V, E;\n    std::cin >> V >> E;\n\n    std::vector<Edge<int>> es(E);\n\
    \    for (int i = 0; i < E; ++i) {\n        std::cin >> es[i];\n    }\n\n    std::cout\
    \ << kruskal<int>(V, es) << std::endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp\"\
    \n#include <iostream>\n\n#include \"../../Graph/graph-template.hpp\"\n#include\
    \ \"../../Graph/Minimum-Spanning-Tree/kruskal.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios_base::sync_with_stdio(false);\n\n    int V, E;\n    std::cin >>\
    \ V >> E;\n\n    std::vector<Edge<int>> es(E);\n    for (int i = 0; i < E; ++i)\
    \ {\n        std::cin >> es[i];\n    }\n\n    std::cout << kruskal<int>(V, es)\
    \ << std::endl;\n\n    return 0;\n}\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Graph/Minimum-Spanning-Tree/kruskal.hpp
  - Data-Structure/Disjoint-Set/union-find.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 05:19:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
- /verify/test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp.html
title: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
---
