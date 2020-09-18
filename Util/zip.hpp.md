---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/zip.test.cpp
    title: test/unittest/zip.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "zip() (n\u500B\u306Evector\u304B\u3089n\u8981\u7D20\u306E\u30BF\
      \u30D7\u30EB\u306Evector\u3092\u751F\u6210\u3059\u308B)"
    links: []
  bundledCode: "#line 2 \"Util/zip.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    #include <utility>\n#include <tuple>\n\n/**\n * @brief zip() (n\u500B\u306Evector\u304B\
    \u3089n\u8981\u7D20\u306E\u30BF\u30D7\u30EB\u306Evector\u3092\u751F\u6210\u3059\
    \u308B)\n */\ntemplate <class T1, class T2>\nstd::vector<std::pair<T1, T2>> zip(const\
    \ std::vector<T1>& v1, const std::vector<T2>& v2) {\n    const auto sz = std::min(v1.size(),\
    \ v2.size());\n    std::vector<std::pair<T1, T2>> ret(sz);\n    for (std::size_t\
    \ i = 0; i < sz; ++i) ret[i] = std::make_pair(v1[i], v2[i]);\n    return ret;\n\
    }\n\ntemplate <class T1, class T2, class T3>\nstd::vector<std::tuple<T1, T2, T3>>\
    \ zip(const std::vector<T1>& v1, const std::vector<T2>& v2, const std::vector<T3>&\
    \ v3) {\n    const auto sz = std::min({v1.size(), v2.size(), v3.size()});\n  \
    \  std::vector<std::tuple<T1, T2, T3>> ret(sz);\n    for (std::size_t i = 0; i\
    \ < sz; ++i) ret[i] = std::make_tuple(v1[i], v2[i], v3[i]);\n    return ret;\n\
    }\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n#include <utility>\n\
    #include <tuple>\n\n/**\n * @brief zip() (n\u500B\u306Evector\u304B\u3089n\u8981\
    \u7D20\u306E\u30BF\u30D7\u30EB\u306Evector\u3092\u751F\u6210\u3059\u308B)\n */\n\
    template <class T1, class T2>\nstd::vector<std::pair<T1, T2>> zip(const std::vector<T1>&\
    \ v1, const std::vector<T2>& v2) {\n    const auto sz = std::min(v1.size(), v2.size());\n\
    \    std::vector<std::pair<T1, T2>> ret(sz);\n    for (std::size_t i = 0; i <\
    \ sz; ++i) ret[i] = std::make_pair(v1[i], v2[i]);\n    return ret;\n}\n\ntemplate\
    \ <class T1, class T2, class T3>\nstd::vector<std::tuple<T1, T2, T3>> zip(const\
    \ std::vector<T1>& v1, const std::vector<T2>& v2, const std::vector<T3>& v3) {\n\
    \    const auto sz = std::min({v1.size(), v2.size(), v3.size()});\n    std::vector<std::tuple<T1,\
    \ T2, T3>> ret(sz);\n    for (std::size_t i = 0; i < sz; ++i) ret[i] = std::make_tuple(v1[i],\
    \ v2[i], v3[i]);\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/zip.hpp
  requiredBy: []
  timestamp: '2020-09-18 19:25:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/zip.test.cpp
documentation_of: Util/zip.hpp
layout: document
redirect_from:
- /library/Util/zip.hpp
- /library/Util/zip.hpp.html
title: "zip() (n\u500B\u306Evector\u304B\u3089n\u8981\u7D20\u306E\u30BF\u30D7\u30EB\
  \u306Evector\u3092\u751F\u6210\u3059\u308B)"
---
