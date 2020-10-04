---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/at.hpp
    title: at() ()
  - icon: ':heavy_check_mark:'
    path: Util/int-infinity.hpp
    title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0558-Cheese.test.cpp
    title: test/AOJ/0558-Cheese.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
    title: test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "bfs() (\u5E45\u512A\u5148\u63A2\u7D22\u306B\u3088\u308B\u5358\
      \u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF, \u6B21\u5143\u62E1\u5F35\u306B\u5BFE\
      \u5FDC)"
    links: []
  bundledCode: "#line 2 \"Graph/Shortest-Path/bfs.hpp\"\n#include <cassert>\n#include\
    \ <functional>\n#include <queue>\n#include <utility>\n#include <vector>\n\n#line\
    \ 2 \"Util/at.hpp\"\n#include <tuple>\n#line 4 \"Util/at.hpp\"\n#include <type_traits>\n\
    \n/**\n * @brief at() ()\n */\nnamespace arumakan {\n\n// at(a, i) returns a[i]\n\
    template <class Array, class Integer, std::enable_if_t<std::is_integral<Integer>::value,\
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
    }\n\n}  // namespace arumakan\n#line 2 \"Util/int-infinity.hpp\"\n#include <cstdint>\n\
    \n/**\n * @brief int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)\n *\
    \ 2\u500D\u3057\u3066\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044 & memset()\u306B\u3082\u4F7F\u3048\u308B (\u9700\u8981\u3042\u308B\uFF1F\
    )\n */\nconstexpr int32_t INF = 0x3f3f3f3f;\nconstexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n\
    #line 10 \"Graph/Shortest-Path/bfs.hpp\"\n\n/**\n * @brief bfs() (\u5E45\u512A\
    \u5148\u63A2\u7D22\u306B\u3088\u308B\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\
    \u8DEF, \u6B21\u5143\u62E1\u5F35\u306B\u5BFE\u5FDC)\n *\n * @param dist:\n * \
    \     start \u304B\u3089\u306E\u8DDD\u96E2\u3092\u683C\u7D0D\u3059\u308B\u914D\
    \u5217\u3002\n *      \u8981\u7D20\u6570\u306F\u9802\u70B9\u6570\u4EE5\u4E0A\u3067\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\u3002-1\u3084INF\u306A\u3069\u3001\
    \u8DDD\u96E2\u3068\u3057\u3066\u6B63\u5F53\u3067\u306A\u3044\u5024\u3067fill\u3055\
    \u308C\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n *      \u591A\u6B21\
    \u5143\u914D\u5217\u3067\u3082OK\u3002\n *\n * @param start:\n *      \u9802\u70B9\
    \u3092\u8868\u3059dist\u306E\u6DFB\u5B57\u3002\n *      dist\u304C\u4E00\u6B21\
    \u5143\u914D\u5217\u306A\u3089\u6574\u6570\u578B,\n *      dist\u304C\u4E8C\u6B21\
    \u5143\u914D\u5217\u306A\u3089std::pair<integer, integer> \u307E\u305F\u306F std::tuple<integer,\
    \ integer> \u307E\u305F\u306F std::array<integer, 2>,\n *      dist\u304C\u4E09\
    \u6B21\u5143\u914D\u5217\u306A\u3089std::tuple<integer, integer, integer> \u307E\
    \u305F\u306F std::array<integer, 3>\u3002\n *      start = {i, j, k} \u306E\u3068\
    \u304D dist[i][j][k] \u3067\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u3002\n *\n *\
    \ @param enumerateNextVertex:\n *      fn(from: Vertex, fn(to: Vertex) => void)\
    \ => void\n *      \u7B2C\u4E00\u5F15\u6570\u306BVertex, \u7B2C\u4E8C\u5F15\u6570\
    \u306B\u95A2\u6570\u3092\u3068\u308B\u95A2\u6570\u3002\n *      \u3053\u306E\u95A2\
    \u6570\u304C\u7B2C\u4E00\u5F15\u6570\u306E\u9802\u70B9from\u304B\u3089\u6B21\u306E\
    \u9802\u70B9\u306E\u9077\u79FB\u5148\u3092\u5217\u6319\u3057\u3001\u7B2C\u4E8C\
    \u5F15\u6570\u306B\u6E21\u3059\u3053\u3068\u3067 bfs() \u306B\u9077\u79FB\u51E6\
    \u7406\u3092\u59D4\u8B72\u3059\u308B\u3002\n */\ntemplate <class DistArray, class\
    \ Vertex, class NextVertexEnumerator>\nDistArray bfs(DistArray&& dist, Vertex\
    \ start, NextVertexEnumerator enumerateNextVertex) {\n    using arumakan::at;\n\
    \    assert(!dist.empty());\n    assert(at(dist, start) == -1 || at(dist, start)\
    \ >= INF);\n\n    std::queue<Vertex> que({start});\n    const auto yetReachedMarker\
    \ = at(dist, start);\n    at(dist, start) = 0;\n    while (!que.empty()) {\n \
    \       const Vertex v = std::move(que.front());\n        que.pop();\n       \
    \ const auto curDist = at(dist, v);\n        enumerateNextVertex(v, [&](Vertex\
    \ nxt) {\n            if (at(dist, nxt) == yetReachedMarker) {\n             \
    \   at(dist, nxt) = curDist + 1;\n                que.push(nxt);\n           \
    \ }\n        });\n    }\n    return dist;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <functional>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\n#include \"../../Util/at.hpp\"\n#include\
    \ \"../../Util/int-infinity.hpp\"\n\n/**\n * @brief bfs() (\u5E45\u512A\u5148\u63A2\
    \u7D22\u306B\u3088\u308B\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF, \u6B21\
    \u5143\u62E1\u5F35\u306B\u5BFE\u5FDC)\n *\n * @param dist:\n *      start \u304B\
    \u3089\u306E\u8DDD\u96E2\u3092\u683C\u7D0D\u3059\u308B\u914D\u5217\u3002\n * \
    \     \u8981\u7D20\u6570\u306F\u9802\u70B9\u6570\u4EE5\u4E0A\u3067\u306A\u3051\
    \u308C\u3070\u306A\u3089\u306A\u3044\u3002-1\u3084INF\u306A\u3069\u3001\u8DDD\u96E2\
    \u3068\u3057\u3066\u6B63\u5F53\u3067\u306A\u3044\u5024\u3067fill\u3055\u308C\u3066\
    \u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n *      \u591A\u6B21\u5143\u914D\
    \u5217\u3067\u3082OK\u3002\n *\n * @param start:\n *      \u9802\u70B9\u3092\u8868\
    \u3059dist\u306E\u6DFB\u5B57\u3002\n *      dist\u304C\u4E00\u6B21\u5143\u914D\
    \u5217\u306A\u3089\u6574\u6570\u578B,\n *      dist\u304C\u4E8C\u6B21\u5143\u914D\
    \u5217\u306A\u3089std::pair<integer, integer> \u307E\u305F\u306F std::tuple<integer,\
    \ integer> \u307E\u305F\u306F std::array<integer, 2>,\n *      dist\u304C\u4E09\
    \u6B21\u5143\u914D\u5217\u306A\u3089std::tuple<integer, integer, integer> \u307E\
    \u305F\u306F std::array<integer, 3>\u3002\n *      start = {i, j, k} \u306E\u3068\
    \u304D dist[i][j][k] \u3067\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u3002\n *\n *\
    \ @param enumerateNextVertex:\n *      fn(from: Vertex, fn(to: Vertex) => void)\
    \ => void\n *      \u7B2C\u4E00\u5F15\u6570\u306BVertex, \u7B2C\u4E8C\u5F15\u6570\
    \u306B\u95A2\u6570\u3092\u3068\u308B\u95A2\u6570\u3002\n *      \u3053\u306E\u95A2\
    \u6570\u304C\u7B2C\u4E00\u5F15\u6570\u306E\u9802\u70B9from\u304B\u3089\u6B21\u306E\
    \u9802\u70B9\u306E\u9077\u79FB\u5148\u3092\u5217\u6319\u3057\u3001\u7B2C\u4E8C\
    \u5F15\u6570\u306B\u6E21\u3059\u3053\u3068\u3067 bfs() \u306B\u9077\u79FB\u51E6\
    \u7406\u3092\u59D4\u8B72\u3059\u308B\u3002\n */\ntemplate <class DistArray, class\
    \ Vertex, class NextVertexEnumerator>\nDistArray bfs(DistArray&& dist, Vertex\
    \ start, NextVertexEnumerator enumerateNextVertex) {\n    using arumakan::at;\n\
    \    assert(!dist.empty());\n    assert(at(dist, start) == -1 || at(dist, start)\
    \ >= INF);\n\n    std::queue<Vertex> que({start});\n    const auto yetReachedMarker\
    \ = at(dist, start);\n    at(dist, start) = 0;\n    while (!que.empty()) {\n \
    \       const Vertex v = std::move(que.front());\n        que.pop();\n       \
    \ const auto curDist = at(dist, v);\n        enumerateNextVertex(v, [&](Vertex\
    \ nxt) {\n            if (at(dist, nxt) == yetReachedMarker) {\n             \
    \   at(dist, nxt) = curDist + 1;\n                que.push(nxt);\n           \
    \ }\n        });\n    }\n    return dist;\n}\n"
  dependsOn:
  - Util/at.hpp
  - Util/int-infinity.hpp
  isVerificationFile: false
  path: Graph/Shortest-Path/bfs.hpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
  - test/AOJ/0558-Cheese.test.cpp
documentation_of: Graph/Shortest-Path/bfs.hpp
layout: document
redirect_from:
- /library/Graph/Shortest-Path/bfs.hpp
- /library/Graph/Shortest-Path/bfs.hpp.html
title: "bfs() (\u5E45\u512A\u5148\u63A2\u7D22\u306B\u3088\u308B\u5358\u4E00\u59CB\u70B9\
  \u6700\u77ED\u7D4C\u8DEF, \u6B21\u5143\u62E1\u5F35\u306B\u5BFE\u5FDC)"
---
