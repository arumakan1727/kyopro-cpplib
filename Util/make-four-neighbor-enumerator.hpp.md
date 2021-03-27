---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0558-Cheese.test.cpp
    title: test/AOJ/0558-Cheese.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "makeFourNeighborEnumerator() (\u30B0\u30EA\u30C3\u30C9\u306E\u56DB\
      \u8FD1\u508D(\u4E0A\u4E0B\u5DE6\u53F3)\u306E\u5217\u6319)"
    links: []
  bundledCode: "#line 2 \"Util/make-four-neighbor-enumerator.hpp\"\n#include <cstdint>\n\
    #include <utility>\n\n/**\n * @brief makeFourNeighborEnumerator() (\u30B0\u30EA\
    \u30C3\u30C9\u306E\u56DB\u8FD1\u508D(\u4E0A\u4E0B\u5DE6\u53F3)\u306E\u5217\u6319\
    ) \n *\n * handlerFunc: fn({sy, sx}, {ny, nx}, f)\n */\ntemplate <class HandlerFunc>\n\
    auto makeFourNeighborEnumerator(int H, int W, HandlerFunc handlerFunc) {\n   \
    \ return [H, W, handlerFunc](auto v, auto func) {\n        using P = decltype(v);\n\
    \        static constexpr int dy[]{0, 1, 0, -1};\n        const auto y = std::get<0>(v);\n\
    \        const auto x = std::get<1>(v);\n\n        for (size_t q = 0; q < 4; ++q)\
    \ {\n            const auto ny = y + dy[q];\n            const auto nx = x + dy[q\
    \ ^ 1];\n            if (0 <= ny && ny < H && 0 <= nx && nx < W) handlerFunc(P{y,\
    \ x}, P{ny, nx}, func);\n        }\n    };\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <utility>\n\n/**\n * @brief makeFourNeighborEnumerator()\
    \ (\u30B0\u30EA\u30C3\u30C9\u306E\u56DB\u8FD1\u508D(\u4E0A\u4E0B\u5DE6\u53F3)\u306E\
    \u5217\u6319) \n *\n * handlerFunc: fn({sy, sx}, {ny, nx}, f)\n */\ntemplate <class\
    \ HandlerFunc>\nauto makeFourNeighborEnumerator(int H, int W, HandlerFunc handlerFunc)\
    \ {\n    return [H, W, handlerFunc](auto v, auto func) {\n        using P = decltype(v);\n\
    \        static constexpr int dy[]{0, 1, 0, -1};\n        const auto y = std::get<0>(v);\n\
    \        const auto x = std::get<1>(v);\n\n        for (size_t q = 0; q < 4; ++q)\
    \ {\n            const auto ny = y + dy[q];\n            const auto nx = x + dy[q\
    \ ^ 1];\n            if (0 <= ny && ny < H && 0 <= nx && nx < W) handlerFunc(P{y,\
    \ x}, P{ny, nx}, func);\n        }\n    };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/make-four-neighbor-enumerator.hpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/0558-Cheese.test.cpp
documentation_of: Util/make-four-neighbor-enumerator.hpp
layout: document
redirect_from:
- /library/Util/make-four-neighbor-enumerator.hpp
- /library/Util/make-four-neighbor-enumerator.hpp.html
title: "makeFourNeighborEnumerator() (\u30B0\u30EA\u30C3\u30C9\u306E\u56DB\u8FD1\u508D\
  (\u4E0A\u4E0B\u5DE6\u53F3)\u306E\u5217\u6319)"
---
