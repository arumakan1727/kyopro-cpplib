---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/at.hpp
    title: at() ()
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/helloworld/at.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n\n#line 2 \"Util/at.hpp\"\n#include\
    \ <tuple>\n#include <functional>\n#include <type_traits>\n\n/**\n * @brief at()\
    \ ()\n */\nnamespace arumakan {\n\n//! at(a, i) returns a[i]\ntemplate <class\
    \ Array, class Integer, std::enable_if_t<std::is_integral<Integer>::value, std::nullptr_t>\
    \ = nullptr>\ninline auto at(Array&& a, Integer i) -> decltype(a[0])& {\n    return\
    \ a[i];\n}\n\n//! at(a, Tuple{i}) returns a[i]\ntemplate <class Array, class Tuple,\
    \ std::enable_if_t<std::tuple_size<Tuple>::value == 1, std::nullptr_t> = nullptr>\n\
    inline auto at(Array&& a, Tuple index) -> decltype(a[0])& {\n    return a[std::get<0>(index)];\n\
    }\n\n//! at(mat, Tuple{y, x}) returns mat[y][x]\ntemplate <class Matrix, class\
    \ Tuple, std::enable_if_t<std::tuple_size<Tuple>::value == 2, std::nullptr_t>\
    \ = nullptr>\ninline auto at(Matrix&& mat, Tuple index) -> decltype(mat[0][0])&\
    \ {\n    return mat[std::get<0>(index)][std::get<1>(index)];\n}\n\n//! at(cube,\
    \ Tuple{z, y, x}) returns cube[z][y][x]\ntemplate <class Cube, class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value\
    \ == 3, std::nullptr_t> = nullptr>\ninline auto at(Cube&& cube, Tuple index) ->\
    \ decltype(cube[0][0][0])& {\n    return cube[std::get<0>(index)][std::get<1>(index)][std::get<2>(index)];\n\
    }\n\n}  // namespace arumakan\n#line 6 \"test/helloworld/at.test.cpp\"\n\nvoid\
    \ at_test_dim1_a() {\n    using arumakan::at;\n    constexpr int W = 5;\n    int\
    \ a[W];\n\n    for (int i = 0; i < W; ++i) {\n        at(a, i) = i;\n        assert(&at(a,\
    \ i) == &a[i]);\n        assert(a[i] == i);\n    }\n\n    std::clog << __func__\
    \ << \" : OK\" << std::endl;\n}\n\nvoid at_test_dim1_b() {\n    using arumakan::at;\n\
    \    constexpr int W = 5;\n    int a[W];\n    using P1 = std::array<int, 1>;\n\
    \    using P2 = std::tuple<int>;\n\n    for (int i = 0; i < W; ++i) {\n      \
    \  at(a, P1{i}) = i;\n        assert(a[i] == i);\n        assert(&at(a, P1{i})\
    \ == &a[i]);\n        assert(&at(a, P2{i}) == &a[i]);\n    }\n\n    std::clog\
    \ << __func__ << \" : OK\" << std::endl;\n}\n\nvoid at_test_dim2() {\n    using\
    \ arumakan::at;\n    constexpr int H = 3;\n    constexpr int W = 4;\n    int a[H][W];\n\
    \    using P1 = std::array<int, 2>;\n    using P2 = std::pair<int, int>;\n   \
    \ using P3 = std::tuple<int, int>;\n\n    for (int i = 0; i < H; ++i) {\n    \
    \    for (int j = 0; j < W; ++j) {\n            at(a, P1{i, j}) = i * W + j;\n\
    \            assert(a[i][j] == i * W + j);\n            assert(&at(a, P1{i, j})\
    \ == &a[i][j]);\n            assert(&at(a, P2{i, j}) == &a[i][j]);\n         \
    \   assert(&at(a, P3{i, j}) == &a[i][j]);\n        }\n    }\n\n    std::clog <<\
    \ __func__ << \" : OK\" << std::endl;\n}\n\nvoid at_test_dim3() {\n    using arumakan::at;\n\
    \    constexpr int D = 3;\n    constexpr int H = 3;\n    constexpr int W = 4;\n\
    \    int a[D][H][W];\n    using P1 = std::array<int, 3>;\n    using P2 = std::tuple<int,\
    \ int, int>;\n\n    for (int z = 0; z < D; ++z) {\n        for (int y = 0; y <\
    \ H; ++y) {\n            for (int x = 0; x < W; ++x) {\n                at(a,\
    \ P1{z, y, x}) = (z * H * W) + (y * H) + (x);\n                assert(a[z][y][x]\
    \ == (z * H * W) + (y * H) + (x));\n                assert(&at(a, P1{z, y, x})\
    \ == &a[z][y][x]);\n                assert(&at(a, P2{z, y, x}) == &a[z][y][x]);\n\
    \            }\n        }\n    }\n\n    std::clog << __func__ << \" : OK\" <<\
    \ std::endl;\n}\n\nint main() {\n    std::cout << \"Hello World\" << std::endl;\n\
    \n    at_test_dim1_a();\n    at_test_dim1_b();\n    at_test_dim2();\n    at_test_dim3();\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n\n#include \"../../Util/at.hpp\"\n\n\
    void at_test_dim1_a() {\n    using arumakan::at;\n    constexpr int W = 5;\n \
    \   int a[W];\n\n    for (int i = 0; i < W; ++i) {\n        at(a, i) = i;\n  \
    \      assert(&at(a, i) == &a[i]);\n        assert(a[i] == i);\n    }\n\n    std::clog\
    \ << __func__ << \" : OK\" << std::endl;\n}\n\nvoid at_test_dim1_b() {\n    using\
    \ arumakan::at;\n    constexpr int W = 5;\n    int a[W];\n    using P1 = std::array<int,\
    \ 1>;\n    using P2 = std::tuple<int>;\n\n    for (int i = 0; i < W; ++i) {\n\
    \        at(a, P1{i}) = i;\n        assert(a[i] == i);\n        assert(&at(a,\
    \ P1{i}) == &a[i]);\n        assert(&at(a, P2{i}) == &a[i]);\n    }\n\n    std::clog\
    \ << __func__ << \" : OK\" << std::endl;\n}\n\nvoid at_test_dim2() {\n    using\
    \ arumakan::at;\n    constexpr int H = 3;\n    constexpr int W = 4;\n    int a[H][W];\n\
    \    using P1 = std::array<int, 2>;\n    using P2 = std::pair<int, int>;\n   \
    \ using P3 = std::tuple<int, int>;\n\n    for (int i = 0; i < H; ++i) {\n    \
    \    for (int j = 0; j < W; ++j) {\n            at(a, P1{i, j}) = i * W + j;\n\
    \            assert(a[i][j] == i * W + j);\n            assert(&at(a, P1{i, j})\
    \ == &a[i][j]);\n            assert(&at(a, P2{i, j}) == &a[i][j]);\n         \
    \   assert(&at(a, P3{i, j}) == &a[i][j]);\n        }\n    }\n\n    std::clog <<\
    \ __func__ << \" : OK\" << std::endl;\n}\n\nvoid at_test_dim3() {\n    using arumakan::at;\n\
    \    constexpr int D = 3;\n    constexpr int H = 3;\n    constexpr int W = 4;\n\
    \    int a[D][H][W];\n    using P1 = std::array<int, 3>;\n    using P2 = std::tuple<int,\
    \ int, int>;\n\n    for (int z = 0; z < D; ++z) {\n        for (int y = 0; y <\
    \ H; ++y) {\n            for (int x = 0; x < W; ++x) {\n                at(a,\
    \ P1{z, y, x}) = (z * H * W) + (y * H) + (x);\n                assert(a[z][y][x]\
    \ == (z * H * W) + (y * H) + (x));\n                assert(&at(a, P1{z, y, x})\
    \ == &a[z][y][x]);\n                assert(&at(a, P2{z, y, x}) == &a[z][y][x]);\n\
    \            }\n        }\n    }\n\n    std::clog << __func__ << \" : OK\" <<\
    \ std::endl;\n}\n\nint main() {\n    std::cout << \"Hello World\" << std::endl;\n\
    \n    at_test_dim1_a();\n    at_test_dim1_b();\n    at_test_dim2();\n    at_test_dim3();\n\
    \n    return 0;\n}\n"
  dependsOn:
  - Util/at.hpp
  isVerificationFile: true
  path: test/helloworld/at.test.cpp
  requiredBy: []
  timestamp: '2020-10-25 20:18:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/helloworld/at.test.cpp
layout: document
redirect_from:
- /verify/test/helloworld/at.test.cpp
- /verify/test/helloworld/at.test.cpp.html
title: test/helloworld/at.test.cpp
---
