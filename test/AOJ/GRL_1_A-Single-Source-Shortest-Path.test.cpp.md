---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest-Path/dijkstra.hpp
    title: "dijkstra() (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9, $O((V + E)\\log V)$)"
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template (Edge, Graph, MatrixGraph)
  - icon: ':heavy_check_mark:'
    path: Util/IO/println.hpp
    title: "println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\
      \u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)"
  - icon: ':heavy_check_mark:'
    path: Util/IO/read-directed-graph.hpp
    title: "readDirectedGraph() (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5165\u529B)"
  - icon: ':heavy_check_mark:'
    path: Util/at.hpp
    title: at() ()
  - icon: ':heavy_check_mark:'
    path: Util/chminmax.hpp
    title: chmin(), chmax()
  - icon: ':heavy_check_mark:'
    path: Util/int-alias.hpp
    title: "int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)"
  - icon: ':heavy_check_mark:'
    path: Util/int-infinity.hpp
    title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
  bundledCode: "#line 1 \"test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"Graph/graph-template.hpp\"\
    \n#include <cstdint>\n#line 5 \"Graph/graph-template.hpp\"\n\n/**\n * @brief graph-template\
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
    #line 2 \"Graph/Shortest-Path/dijkstra.hpp\"\n#include <cassert>\n#include <functional>\n\
    #include <queue>\n#include <type_traits>\n#include <utility>\n#line 8 \"Graph/Shortest-Path/dijkstra.hpp\"\
    \n\n#line 2 \"Util/at.hpp\"\n#include <tuple>\n#line 5 \"Util/at.hpp\"\n\n/**\n\
    \ * @brief at() ()\n */\nnamespace arumakan {\n\n// at(a, i) returns a[i]\ntemplate\
    \ <class Array, class Integer, std::enable_if_t<std::is_integral<Integer>::value,\
    \ std::nullptr_t> = nullptr>\ninline auto at(Array&& a, Integer i) -> decltype(a[0])&\
    \ {\n    return a[i];\n}\n\n// at(a, Tuple{i}) returns a[i]\ntemplate <class Array,\
    \ class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value == 1, std::nullptr_t>\
    \ = nullptr>\ninline auto at(Array&& a, Tuple index) -> decltype(a[0])& {\n  \
    \  return a[std::get<0>(index)];\n}\n\n// at(mat, Tuple{y, x}) returns mat[y][x]\n\
    template <class Matrix, class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value\
    \ == 2, std::nullptr_t> = nullptr>\ninline auto at(Matrix&& mat, Tuple index)\
    \ -> decltype(mat[0][0])& {\n    return mat[std::get<0>(index)][std::get<1>(index)];\n\
    }\n\n// at(cube, Tuple{z, y, x}) returns cube[z][y][x]\ntemplate <class Cube,\
    \ class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value == 3, std::nullptr_t>\
    \ = nullptr>\ninline auto at(Cube&& cube, Tuple index) -> decltype(cube[0][0][0])&\
    \ {\n    return cube[std::get<0>(index)][std::get<1>(index)][std::get<2>(index)];\n\
    }\n\n}  // namespace arumakan\n#line 2 \"Util/chminmax.hpp\"\n\n/**\n * @brief\
    \ chmin(), chmax()\n */\ntemplate <class T, class U>\ninline bool chmin(T& a,\
    \ const U& b) {\n    return b < a && (a = b, true);\n}\n\ntemplate <class T, class\
    \ U>\ninline bool chmax(T& a, const U& b) {\n    return b > a && (a = b, true);\n\
    }\n#line 3 \"Util/int-infinity.hpp\"\n\n/**\n * @brief int-infinity (\u6574\u6570\
    \u306E\u30C7\u30AB\u30A4\u5024)\n * 2\u500D\u3057\u3066\u3082\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 & memset()\u306B\u3082\u4F7F\u3048\u308B\
    \ (\u9700\u8981\u3042\u308B\uFF1F)\n */\nconstexpr int32_t INF = 0x3f3f3f3f;\n\
    constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n#line 12 \"Graph/Shortest-Path/dijkstra.hpp\"\
    \n\n/**\n * @brief dijkstra() (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9, $O((V + E)\\\
    log V)$)\n *\n * @param dist:\n *      start \u304B\u3089\u306E\u8DDD\u96E2\u3092\
    \u683C\u7D0D\u3059\u308B\u914D\u5217\u3002\n *      \u8981\u7D20\u6570\u306F\u9802\
    \u70B9\u6570\u4EE5\u4E0A\u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\
    \u3002INF\u306A\u3069\u306E\u3067\u304B\u3044\u5024\u3067fill\u3055\u308C\u3066\
    \u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n *      \u591A\u6B21\u5143\u914D\
    \u5217\u3067\u3082OK\u3002\n *\n * @param start:\n *      \u9802\u70B9\u3092\u8868\
    \u3059dist\u306E\u6DFB\u5B57\u3002\n *      dist\u304C\u4E00\u6B21\u5143\u914D\
    \u5217\u306A\u3089\u6574\u6570\u578B,\n *      dist\u304C\u4E8C\u6B21\u5143\u914D\
    \u5217\u306A\u3089std::pair<integer, integer> \u307E\u305F\u306F std::tuple<integer,\
    \ integer> \u307E\u305F\u306F std::array<integer, 2>,\n *      dist\u304C\u4E09\
    \u6B21\u5143\u914D\u5217\u306A\u3089std::tuple<integer, integer, integer> \u307E\
    \u305F\u306F std::array<integer, 3>\u3002\n *      start = {i, j, k} \u306E\u3068\
    \u304D dist[i][j][k] \u3067\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u3002\n *\n *\
    \ @param enumerateNextVertex:\n *      fn(from: Vertex, fn(to: Vertex, w: EdgeWeight)\
    \ => void) => void\n *      \u7B2C\u4E00\u5F15\u6570\u306BVertex, \u7B2C\u4E8C\
    \u5F15\u6570\u306B\u95A2\u6570\u3092\u3068\u308B\u95A2\u6570\u3002\n *      \u3053\
    \u306E\u95A2\u6570\u304C\u7B2C\u4E00\u5F15\u6570\u306E\u9802\u70B9from\u304B\u3089\
    \u6B21\u306E\u9802\u70B9\u306E\u9077\u79FB\u5148\u3092\u5217\u6319\u3057\u3001\
    \u7B2C\u4E8C\u5F15\u6570\u306B\u6E21\u3059\u3053\u3068\u3067 dijkstra() \u306B\
    \u9077\u79FB\u51E6\u7406\u3092\u59D4\u8B72\u3059\u308B\u3002\n */\ntemplate <class\
    \ DistArray, class Vertex, class NextVertexEnumerator>\nDistArray dijkstra(DistArray&&\
    \ dist, Vertex start, NextVertexEnumerator enumerateNextVertex) {\n    using arumakan::at;\n\
    \    assert(!dist.empty());\n    assert(at(dist, start) >= INF);\n    using WeightType\
    \ = typename std::remove_reference_t<decltype(at(dist, start))>;\n    using P\
    \ = std::pair<WeightType, Vertex>;\n\n    std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> que;\n    que.emplace(at(dist, start) = WeightType(), start);\n\
    \n    while (!que.empty()) {\n        const auto curDist = que.top().first;\n\
    \        const auto curVertex = que.top().second;\n        que.pop();\n      \
    \  if (at(dist, curVertex) < curDist) continue;\n        enumerateNextVertex(curVertex,\
    \ [&](auto nxtVertex, auto edgeWeight) {\n            if (chmin(at(dist, nxtVertex),\
    \ curDist + edgeWeight)) {\n                que.emplace(curDist + edgeWeight,\
    \ nxtVertex);\n            }\n        });\n    }\n    return dist;\n}\n\n#line\
    \ 4 \"Util/IO/read-directed-graph.hpp\"\n\n#line 6 \"Util/IO/read-directed-graph.hpp\"\
    \n\n/**\n * @brief readDirectedGraph() (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u5165\
    \u529B)\n */\ntemplate <class T>\nGraph<T> readDirectedGraph(size_t V, size_t\
    \ E, int padding = -1, std::istream& is = std::cin) {\n    Graph<T> G(V);\n  \
    \  for (size_t i = 0; i < E; ++i) {\n        Edge<T> e;\n        is >> e;\n  \
    \      e.from += padding, e.to += padding;\n        e.id = static_cast<int>(i);\n\
    \        G[e.from].emplace_back(e);\n    }\n    return G;\n}\n\n#line 9 \"test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp\"\
    \n\n#line 3 \"Util/int-alias.hpp\"\n\n/**\n * @brief int-alias (\u6574\u6570\u578B\
    \u306E\u30A8\u30A4\u30EA\u30A2\u30B9)\n */\nusing i64 = int64_t;\nusing u64 =\
    \ uint64_t;\n#line 4 \"Util/IO/println.hpp\"\n\n/**\n * @brief println() (\u53EF\
    \u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\
    \u3057\u3066\u6539\u884C\u3059\u308B)\n */\ninline void println() {\n    std::cout\
    \ << '\\n';\n}\ntemplate <class Head, class... Tail>\ninline void println(Head&&\
    \ head, Tail&&... tail) {\n    std::cout << head << &\" \"[!sizeof...(tail)];\n\
    \    println(std::forward<Tail>(tail)...);\n}\n#line 13 \"test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \n    int V, E, r;\n    std::cin >> V >> E >> r;\n\n    auto G = readDirectedGraph<int>(V,\
    \ E, 0);\n\n    std::vector<i64> dist(V, LINF);\n    dijkstra(dist, r, [&](int\
    \ v, auto push) {\n        for (Edge e : G[v]) {\n            push(e.to, e.weight);\n\
    \        }\n    });\n\n    for (const auto d : dist) {\n        if (d >= LINF)\
    \ {\n            println(\"INF\");\n        } else {\n            println(d);\n\
    \        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../Graph/graph-template.hpp\"\
    \n#include \"../../Graph/Shortest-Path/dijkstra.hpp\"\n#include \"../../Util/IO/read-directed-graph.hpp\"\
    \n\n#include \"../../Util/int-alias.hpp\"\n#include \"../../Util/int-infinity.hpp\"\
    \n#include \"../../Util/IO/println.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios_base::sync_with_stdio(false);\n\n    int V, E, r;\n    std::cin\
    \ >> V >> E >> r;\n\n    auto G = readDirectedGraph<int>(V, E, 0);\n\n    std::vector<i64>\
    \ dist(V, LINF);\n    dijkstra(dist, r, [&](int v, auto push) {\n        for (Edge\
    \ e : G[v]) {\n            push(e.to, e.weight);\n        }\n    });\n\n    for\
    \ (const auto d : dist) {\n        if (d >= LINF) {\n            println(\"INF\"\
    );\n        } else {\n            println(d);\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Graph/Shortest-Path/dijkstra.hpp
  - Util/at.hpp
  - Util/chminmax.hpp
  - Util/int-infinity.hpp
  - Util/IO/read-directed-graph.hpp
  - Util/int-alias.hpp
  - Util/IO/println.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
- /verify/test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp.html
title: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
---
