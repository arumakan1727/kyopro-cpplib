---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "std::istream\u306B\u3088\u308B\u30B3\u30F3\u30C6\u30CA\u306E\u5165\
      \u529B"
    links: []
  bundledCode: "#line 2 \"Util/IO/container-input.hpp\"\n#include <iostream>\n\n/**\n\
    \ * @brief std::istream\u306B\u3088\u308B\u30B3\u30F3\u30C6\u30CA\u306E\u5165\u529B\
    \n */\ntemplate <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, Container& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n"
  code: "#pragma once\n#include <iostream>\n\n/**\n * @brief std::istream\u306B\u3088\
    \u308B\u30B3\u30F3\u30C6\u30CA\u306E\u5165\u529B\n */\ntemplate <class Container,\
    \ class = typename Container::value_type, std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, Container& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/IO/container-input.hpp
  requiredBy: []
  timestamp: '2020-09-22 21:57:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/IO/container-input.hpp
layout: document
redirect_from:
- /library/Util/IO/container-input.hpp
- /library/Util/IO/container-input.hpp.html
title: "std::istream\u306B\u3088\u308B\u30B3\u30F3\u30C6\u30CA\u306E\u5165\u529B"
---
