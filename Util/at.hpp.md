---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  requiredBy: []
  timestamp: '2020-09-25 15:02:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/helloworld/at.test.cpp
documentation_of: Util/at.hpp
layout: document
redirect_from:
- /library/Util/at.hpp
- /library/Util/at.hpp.html
title: at() ()
---
