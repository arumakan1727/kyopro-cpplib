---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Shortest-Path/bfs.hpp
    title: "bfs() (\u5E45\u512A\u5148\u63A2\u7D22\u306B\u3088\u308B\u5358\u4E00\u59CB\
      \u70B9\u6700\u77ED\u7D4C\u8DEF, \u6B21\u5143\u62E1\u5F35\u306B\u5BFE\u5FDC)"
  - icon: ':heavy_check_mark:'
    path: Util/at.hpp
    title: at() ()
  - icon: ':heavy_check_mark:'
    path: Util/int-infinity.hpp
    title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
  - icon: ':heavy_check_mark:'
    path: Util/make-four-neighbor-enumerator.hpp
    title: "makeFourNeighborEnumerator() (\u30B0\u30EA\u30C3\u30C9\u306E\u56DB\u8FD1\
      \u508D(\u4E0A\u4E0B\u5DE6\u53F3)\u306E\u5217\u6319)"
  - icon: ':heavy_check_mark:'
    path: Util/rep-macro.hpp
    title: "rep()\u30DE\u30AF\u30ED"
  - icon: ':heavy_check_mark:'
    path: Util/makeVec.hpp
    title: "makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210)"
  - icon: ':heavy_check_mark:'
    path: Util/fillContainer.hpp
    title: "fillContainer() (\u30B3\u30F3\u30C6\u30CA\u306Efill)"
  - icon: ':heavy_check_mark:'
    path: Util/IO/var-declaration-with-input.hpp
    title: "\u8907\u6570\u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\u6642\u306B\
      \u5165\u529B\u3082\u3059\u308B\u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558
  bundledCode: "#line 1 \"test/AOJ/0558-Cheese.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558\"\
    \n#include <bits/stdc++.h>\n\n#line 7 \"Graph/Shortest-Path/bfs.hpp\"\n\n#line\
    \ 4 \"Util/at.hpp\"\n#include <type_traits>\n\n/**\n * @brief at() ()\n */\nnamespace\
    \ arumakan {\n\n// at(a, i) returns a[i]\ntemplate <class Array, class Integer,\
    \ std::enable_if_t<std::is_integral<Integer>::value, std::nullptr_t> = nullptr>\n\
    inline auto at(Array&& a, Integer i) -> decltype(a[0])& {\n    return a[i];\n\
    }\n\n// at(a, Tuple{i}) returns a[i]\ntemplate <class Array, class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value\
    \ == 1, std::nullptr_t> = nullptr>\ninline auto at(Array&& a, Tuple index) ->\
    \ decltype(a[0])& {\n    return a[std::get<0>(index)];\n}\n\n// at(mat, Tuple{y,\
    \ x}) returns mat[y][x]\ntemplate <class Matrix, class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value\
    \ == 2, std::nullptr_t> = nullptr>\ninline auto at(Matrix&& mat, Tuple index)\
    \ -> decltype(mat[0][0])& {\n    return mat[std::get<0>(index)][std::get<1>(index)];\n\
    }\n\n// at(cube, Tuple{z, y, x}) returns cube[z][y][x]\ntemplate <class Cube,\
    \ class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value == 3, std::nullptr_t>\
    \ = nullptr>\ninline auto at(Cube&& cube, Tuple index) -> decltype(cube[0][0][0])&\
    \ {\n    return cube[std::get<0>(index)][std::get<1>(index)][std::get<2>(index)];\n\
    }\n\n}  // namespace arumakan\n#line 3 \"Util/int-infinity.hpp\"\n\n/**\n * @brief\
    \ int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)\n * 2\u500D\u3057\u3066\
    \u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 & memset()\u306B\
    \u3082\u4F7F\u3048\u308B (\u9700\u8981\u3042\u308B\uFF1F)\n */\nconstexpr std::int32_t\
    \ INF = 0x3f3f3f3f;\nconstexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n#line\
    \ 10 \"Graph/Shortest-Path/bfs.hpp\"\n\n/**\n * @brief bfs() (\u5E45\u512A\u5148\
    \u63A2\u7D22\u306B\u3088\u308B\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
    , \u6B21\u5143\u62E1\u5F35\u306B\u5BFE\u5FDC)\n *\n * @param dist:\n *      start\
    \ \u304B\u3089\u306E\u8DDD\u96E2\u3092\u683C\u7D0D\u3059\u308B\u914D\u5217\u3002\
    \n *      \u8981\u7D20\u6570\u306F\u9802\u70B9\u6570\u4EE5\u4E0A\u3067\u306A\u3051\
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
    \ }\n        });\n    }\n    return dist;\n}\n#line 4 \"Util/make-four-neighbor-enumerator.hpp\"\
    \n\n/**\n * @brief makeFourNeighborEnumerator() (\u30B0\u30EA\u30C3\u30C9\u306E\
    \u56DB\u8FD1\u508D(\u4E0A\u4E0B\u5DE6\u53F3)\u306E\u5217\u6319) \n *\n * handlerFunc:\
    \ fn({sy, sx}, {ny, nx}, f)\n */\ntemplate <class HandlerFunc>\nauto makeFourNeighborEnumerator(int\
    \ H, int W, HandlerFunc handlerFunc) {\n    return [H, W, handlerFunc](auto v,\
    \ auto func) {\n        using P = decltype(v);\n        static constexpr int dy[]{0,\
    \ 1, 0, -1};\n        const auto y = std::get<0>(v);\n        const auto x = std::get<1>(v);\n\
    \n        for (std::size_t q = 0; q < 4; ++q) {\n            const auto ny = y\
    \ + dy[q];\n            const auto nx = x + dy[q ^ 1];\n            if (0 <= ny\
    \ && ny < H && 0 <= nx && nx < W) handlerFunc(P{y, x}, P{ny, nx}, func);\n   \
    \     }\n    };\n}\n#line 2 \"Util/rep-macro.hpp\"\n\n/**\n * @brief rep()\u30DE\
    \u30AF\u30ED\n */\n#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_end = (end); i < i##_end; ++i)\n#define repc(i, begin, last)\
    \ for (std::make_signed_t<std::remove_cv_t<decltype(last)>> i = (begin), i##_last\
    \ = (last); i <= i##_last; ++i)\n#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(begin)>>\
    \ i = (begin), i##_last = (last); i >= i##_last; --i)\n#line 3 \"Util/makeVec.hpp\"\
    \n\n/**\n * @brief makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210\
    )\n */\ntemplate <class T>\ninline std::vector<T> makeVec(std::size_t sz, const\
    \ T& initValue) {\n    return std::vector<T>(sz, initValue);\n}\ntemplate <class\
    \ T, class... Args>\ninline auto makeVec(size_t sz, Args... args) {\n    return\
    \ std::vector<decltype(makeVec<T>(args...))>(sz, makeVec<T>(args...));\n}\n#line\
    \ 5 \"Util/fillContainer.hpp\"\n\n/**\n * @brief fillContainer() (\u30B3\u30F3\
    \u30C6\u30CA\u306Efill)\n */\ntemplate <class T, class Container, class... ConstructorArgs,\
    \ std::enable_if_t<std::is_same<Container, T>::value, std::nullptr_t> = nullptr>\n\
    inline void fillContainer(Container& container, ConstructorArgs&&... constructorArgs)\
    \ {\n    container = T(std::forward<ConstructorArgs>(constructorArgs)...);\n}\n\
    \ntemplate <class T, class Container, class... ConstructorArgs, std::enable_if_t<!std::is_same<Container,\
    \ T>::value, std::nullptr_t> = nullptr>\ninline void fillContainer(Container&\
    \ container, ConstructorArgs&&... constructorArgs) {\n    for (auto& e: container)\
    \ fillContainer<T>(e, std::forward<ConstructorArgs>(constructorArgs)...);\n}\n\
    #line 3 \"Util/IO/var-declaration-with-input.hpp\"\n\n/**\n * @brief \u8907\u6570\
    \u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\u6642\u306B\u5165\u529B\u3082\
    \u3059\u308B\u3084\u3064\n */\ntemplate <class T>\nstd::istream& operator,(std::istream&\
    \ is, T& rhs) {\n    return is >> rhs;\n}\n\n#define var(type, ...) \\\n    type\
    \ __VA_ARGS__;  \\\n    std::cin >> __VA_ARGS__\n#line 10 \"test/AOJ/0558-Cheese.test.cpp\"\
    \n\nint main() {\n    using P = std::array<int, 2>;\n\n    var(int, H, W, N);\n\
    \n    std::vector<std::string> mat(H);\n    std::vector<P> cheeses(N + 1);\n\n\
    \    rep(i, 0, H) {\n        std::cin >> mat[i];\n        rep(j, 0, W) {\n   \
    \         if (std::isdigit(mat[i][j])) {\n                cheeses[mat[i][j] -\
    \ '0'] = P{i, j};\n            } else if (mat[i][j] == 'S') {\n              \
    \  cheeses[0] = P{i, j};\n            }\n        }\n    }\n\n    const auto enumerate4neighbor\
    \ = makeFourNeighborEnumerator(H, W, [&](auto, auto to, auto f) {\n        const\
    \ auto [y, x] = to;\n        if (mat[y][x] != 'X') f(to);\n    });\n\n    auto\
    \ dist = makeVec<int>(H, W, -1);\n\n    int ans = 0;\n    rep(level, 0, N) {\n\
    \        const P s = cheeses[level];\n        const P g = cheeses[level + 1];\n\
    \        fillContainer<int>(dist, -1);\n        bfs(dist, s, enumerate4neighbor);\n\
    \        ans += arumakan::at(dist, g);\n    }\n\n    std::cout << ans << std::endl;\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../Graph/Shortest-Path/bfs.hpp\"\n\
    #include \"../../Util/make-four-neighbor-enumerator.hpp\"\n#include \"../../Util/rep-macro.hpp\"\
    \n#include \"../../Util/makeVec.hpp\"\n#include \"../../Util/fillContainer.hpp\"\
    \n#include \"../../Util/IO/var-declaration-with-input.hpp\"\n\nint main() {\n\
    \    using P = std::array<int, 2>;\n\n    var(int, H, W, N);\n\n    std::vector<std::string>\
    \ mat(H);\n    std::vector<P> cheeses(N + 1);\n\n    rep(i, 0, H) {\n        std::cin\
    \ >> mat[i];\n        rep(j, 0, W) {\n            if (std::isdigit(mat[i][j]))\
    \ {\n                cheeses[mat[i][j] - '0'] = P{i, j};\n            } else if\
    \ (mat[i][j] == 'S') {\n                cheeses[0] = P{i, j};\n            }\n\
    \        }\n    }\n\n    const auto enumerate4neighbor = makeFourNeighborEnumerator(H,\
    \ W, [&](auto, auto to, auto f) {\n        const auto [y, x] = to;\n        if\
    \ (mat[y][x] != 'X') f(to);\n    });\n\n    auto dist = makeVec<int>(H, W, -1);\n\
    \n    int ans = 0;\n    rep(level, 0, N) {\n        const P s = cheeses[level];\n\
    \        const P g = cheeses[level + 1];\n        fillContainer<int>(dist, -1);\n\
    \        bfs(dist, s, enumerate4neighbor);\n        ans += arumakan::at(dist,\
    \ g);\n    }\n\n    std::cout << ans << std::endl;\n\n    return 0;\n}\n"
  dependsOn:
  - Graph/Shortest-Path/bfs.hpp
  - Util/at.hpp
  - Util/int-infinity.hpp
  - Util/make-four-neighbor-enumerator.hpp
  - Util/rep-macro.hpp
  - Util/makeVec.hpp
  - Util/fillContainer.hpp
  - Util/IO/var-declaration-with-input.hpp
  isVerificationFile: true
  path: test/AOJ/0558-Cheese.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 22:23:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/0558-Cheese.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/0558-Cheese.test.cpp
- /verify/test/AOJ/0558-Cheese.test.cpp.html
title: test/AOJ/0558-Cheese.test.cpp
---
