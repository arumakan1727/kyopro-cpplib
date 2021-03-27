---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/helloworld/project.test.cpp
    title: test/helloworld/project.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "project() (\u30BF\u30D7\u30EB\u306E\u30B3\u30F3\u30C6\u30CA\u306E\
      \u7B2C I \u8981\u7D20\u3092\u62BD\u51FA\u3057\u305Fvector\u3092\u8FD4\u3059)"
    links: []
  bundledCode: "#line 2 \"Util/project.hpp\"\n#include <cstdint>\n#include <algorithm>\n\
    #include <vector>\n#include <tuple>\n\n/**\n * @brief project() (\u30BF\u30D7\u30EB\
    \u306E\u30B3\u30F3\u30C6\u30CA\u306E\u7B2C I \u8981\u7D20\u3092\u62BD\u51FA\u3057\
    \u305Fvector\u3092\u8FD4\u3059)\n */\ntemplate <size_t I, class Container, class\
    \ Value = typename std::tuple_element_t<I, typename Container::value_type>>\n\
    std::vector<Value> project(const Container& v) {\n    std::vector<Value> ret(v.size());\n\
    \    std::transform(v.begin(), v.end(), ret.begin(), [](auto&& t) { return std::get<I>(t);\
    \ });\n    return ret;\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <algorithm>\n#include <vector>\n\
    #include <tuple>\n\n/**\n * @brief project() (\u30BF\u30D7\u30EB\u306E\u30B3\u30F3\
    \u30C6\u30CA\u306E\u7B2C I \u8981\u7D20\u3092\u62BD\u51FA\u3057\u305Fvector\u3092\
    \u8FD4\u3059)\n */\ntemplate <size_t I, class Container, class Value = typename\
    \ std::tuple_element_t<I, typename Container::value_type>>\nstd::vector<Value>\
    \ project(const Container& v) {\n    std::vector<Value> ret(v.size());\n    std::transform(v.begin(),\
    \ v.end(), ret.begin(), [](auto&& t) { return std::get<I>(t); });\n    return\
    \ ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/project.hpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/helloworld/project.test.cpp
documentation_of: Util/project.hpp
layout: document
redirect_from:
- /library/Util/project.hpp
- /library/Util/project.hpp.html
title: "project() (\u30BF\u30D7\u30EB\u306E\u30B3\u30F3\u30C6\u30CA\u306E\u7B2C I\
  \ \u8981\u7D20\u3092\u62BD\u51FA\u3057\u305Fvector\u3092\u8FD4\u3059)"
---
