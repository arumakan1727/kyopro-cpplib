---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "std::ostream\u306B\u3088\u308B\u30B3\u30F3\u30C6\u30CA\u306E\u51FA\
      \u529B"
    links: []
  bundledCode: "#line 2 \"Util/IO/container-output.hpp\"\n#include <iostream>\n\n\
    /**\n * @brief std::ostream\u306B\u3088\u308B\u30B3\u30F3\u30C6\u30CA\u306E\u51FA\
    \u529B\n */\ntemplate <class Container, class = typename Container::value_type,\
    \ std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t>\
    \ = nullptr>\nstd::ostream& operator<<(std::ostream& os, const Container& v) {\n\
    \    for (auto it = std::begin(v); it != std::end(v); ++it) os << &\" \"[it ==\
    \ std::begin(v)] << *it;\n    return os;\n}\n"
  code: "#pragma once\n#include <iostream>\n\n/**\n * @brief std::ostream\u306B\u3088\
    \u308B\u30B3\u30F3\u30C6\u30CA\u306E\u51FA\u529B\n */\ntemplate <class Container,\
    \ class = typename Container::value_type, std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << &\" \"[it == std::begin(v)] << *it;\n    return os;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/IO/container-output.hpp
  requiredBy:
  - export/template-prototype.cpp
  timestamp: '2020-09-22 21:57:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/IO/container-output.hpp
layout: document
redirect_from:
- /library/Util/IO/container-output.hpp
- /library/Util/IO/container-output.hpp.html
title: "std::ostream\u306B\u3088\u308B\u30B3\u30F3\u30C6\u30CA\u306E\u51FA\u529B"
---
