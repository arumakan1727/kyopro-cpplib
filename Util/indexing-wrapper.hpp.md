---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: IndexingWrapper
    links: []
  bundledCode: "#line 2 \"Util/indexing-wrapper.hpp\"\n#include <functional>\n\n/**\n\
    \ * @brief IndexingWrapper\n *\n * a.at(i [, j, k, ...]) \u3092\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3067\u53D7\u3051\u53D6\u3063\u305F\u95A2\u6570\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u547C\u3073\u51FA\u3057 indexConverter(i\
    \ [, j, k, ...]) \u3068\u3057\u3066\u547C\u3073\u51FA\u3059\n * indexConverter()\
    \ \u306F\u53C2\u7167\u3092\u8FD4\u3055\u306A\u3051\u308C\u3070\u306A\u3089\u306A\
    \u3044\n */\ntemplate <class IndexConverterFunc>\nstruct IndexingWrapper {\n \
    \   IndexConverterFunc indexConverter;\n\n    IndexingWrapper(IndexConverterFunc\
    \ indexConverter_)\n        : indexConverter(indexConverter_) {}\n\n    template\
    \ <class... Args>\n    auto&& at(Args&&... args) {\n        return indexConverter(std::forward<Args>(args)...);\n\
    \    }\n\n    template <class... Args>\n    const auto&& at(Args&&... args) const\
    \ {\n        return indexConverter(std::forward<Args>(args)...);\n    }\n\n  \
    \  template <class Arg>\n    auto&& operator[](Arg&& arg) {\n        return indexConverter(std::forward<Arg>(arg));\n\
    \    }\n\n    template <class Arg>\n    const auto&& operator[](Arg&& arg) const\
    \ {\n        return indexConverter(std::forward<Arg>(arg));\n    }\n};\n"
  code: "#pragma once\n#include <functional>\n\n/**\n * @brief IndexingWrapper\n *\n\
    \ * a.at(i [, j, k, ...]) \u3092\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\
    \u53D7\u3051\u53D6\u3063\u305F\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u547C\u3073\u51FA\u3057 indexConverter(i [, j, k, ...]) \u3068\u3057\u3066\
    \u547C\u3073\u51FA\u3059\n * indexConverter() \u306F\u53C2\u7167\u3092\u8FD4\u3055\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\n */\ntemplate <class IndexConverterFunc>\n\
    struct IndexingWrapper {\n    IndexConverterFunc indexConverter;\n\n    IndexingWrapper(IndexConverterFunc\
    \ indexConverter_)\n        : indexConverter(indexConverter_) {}\n\n    template\
    \ <class... Args>\n    auto&& at(Args&&... args) {\n        return indexConverter(std::forward<Args>(args)...);\n\
    \    }\n\n    template <class... Args>\n    const auto&& at(Args&&... args) const\
    \ {\n        return indexConverter(std::forward<Args>(args)...);\n    }\n\n  \
    \  template <class Arg>\n    auto&& operator[](Arg&& arg) {\n        return indexConverter(std::forward<Arg>(arg));\n\
    \    }\n\n    template <class Arg>\n    const auto&& operator[](Arg&& arg) const\
    \ {\n        return indexConverter(std::forward<Arg>(arg));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/indexing-wrapper.hpp
  requiredBy: []
  timestamp: '2020-09-26 18:57:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/indexing-wrapper.hpp
layout: document
redirect_from:
- /library/Util/indexing-wrapper.hpp
- /library/Util/indexing-wrapper.hpp.html
title: IndexingWrapper
---
