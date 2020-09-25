---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    path: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
    title: test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/helloworld/at.test.cpp
    title: test/helloworld/at.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: at() ()
    links: []
  bundledCode: "#line 2 \"Util/at.hpp\"\n#include <tuple>\n#include <functional>\n\
    #include <type_traits>\n\n/**\n * @brief at() ()\n */\nnamespace arumakan {\n\n\
    // at(a, i) returns a[i]\ntemplate <class Array, class Integer, std::enable_if_t<std::is_integral<Integer>::value,\
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
    }\n\n}  // namespace arumakan\n"
  code: "#pragma once\n#include <tuple>\n#include <functional>\n#include <type_traits>\n\
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
    }\n\n}  // namespace arumakan\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/at.hpp
  requiredBy:
  - Graph/Shortest-Path/bfs.hpp
  - Graph/Shortest-Path/dijkstra.hpp
  timestamp: '2020-09-25 15:02:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_11_C-Breadth-First-Search.test.cpp
  - test/AOJ/0558-Cheese.test.cpp
  - test/AOJ/GRL_1_A-Single-Source-Shortest-Path.test.cpp
  - test/helloworld/at.test.cpp
documentation_of: Util/at.hpp
layout: document
redirect_from:
- /library/Util/at.hpp
- /library/Util/at.hpp.html
title: at() ()
---
