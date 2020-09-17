---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30B3\u30F3\u30C6\u30CA\u306E\u5165\u51FA\u529B"
    links: []
  bundledCode: "#line 2 \"Util/IO/container-io.hpp\"\n#include <iostream>\n\n/**\n\
    \ * @brief \u30B3\u30F3\u30C6\u30CA\u306E\u5165\u51FA\u529B\n */\ntemplate <class\
    \ Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, Container& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << &\" \"[it == std::begin(v)] << *it;\n    return os;\n}\n"
  code: "#pragma once\n#include <iostream>\n\n/**\n * @brief \u30B3\u30F3\u30C6\u30CA\
    \u306E\u5165\u51FA\u529B\n */\ntemplate <class Container, class = typename Container::value_type,\
    \ std::enable_if_t<!std::is_same_v<Container, std::string>, std::nullptr_t> =\
    \ nullptr>\nstd::istream& operator>>(std::istream& is, Container& v) {\n    for\
    \ (auto& e : v) is >> e;\n    return is;\n}\n\ntemplate <class Container, class\
    \ = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << &\" \"[it == std::begin(v)] << *it;\n    return os;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/IO/container-io.hpp
  requiredBy: []
  timestamp: '2020-09-17 10:59:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/IO/container-io.hpp
layout: document
redirect_from:
- /library/Util/IO/container-io.hpp
- /library/Util/IO/container-io.hpp.html
title: "\u30B3\u30F3\u30C6\u30CA\u306E\u5165\u51FA\u529B"
---
