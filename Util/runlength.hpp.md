---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/helloworld/runlength.test.cpp
    title: test/helloworld/runlength.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "runlength() (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\
      )"
    links: []
  bundledCode: "#line 2 \"Util/runlength.hpp\"\n#include <iterator>\n#include <vector>\n\
    #include <utility>\n\n/**\n * @brief runlength() (\u30E9\u30F3\u30EC\u30F3\u30B0\
    \u30B9\u5727\u7E2E)\n * (\u304B\u305F\u307E\u308A\u306E\u59CB\u307E\u308A\u4F4D\
    \u7F6E\u30A4\u30C6\u30EC\u30FC\u30BF, \u304B\u305F\u307E\u308A\u306E\u8981\u7D20\
    \u6570) \u306Epair\u306Evector\u3092\u8FD4\u3059\u3002\n */\ntemplate <class Iterator>\n\
    auto runlength(Iterator const begin, Iterator const end) {\n    std::vector<std::pair<Iterator,\
    \ std::size_t>> ret;\n    ret.reserve(std::distance(begin, end));\n\n    for (auto\
    \ itr = begin; itr != end;) {\n        std::size_t cnt = 1;\n        const auto\
    \ head = itr++;\n        while (itr != end && *itr == *head) ++itr, ++cnt;\n \
    \       ret.emplace_back(head, cnt);\n    }\n\n    ret.shrink_to_fit();\n    return\
    \ ret;\n}\n"
  code: "#pragma once\n#include <iterator>\n#include <vector>\n#include <utility>\n\
    \n/**\n * @brief runlength() (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\
    )\n * (\u304B\u305F\u307E\u308A\u306E\u59CB\u307E\u308A\u4F4D\u7F6E\u30A4\u30C6\
    \u30EC\u30FC\u30BF, \u304B\u305F\u307E\u308A\u306E\u8981\u7D20\u6570) \u306Epair\u306E\
    vector\u3092\u8FD4\u3059\u3002\n */\ntemplate <class Iterator>\nauto runlength(Iterator\
    \ const begin, Iterator const end) {\n    std::vector<std::pair<Iterator, std::size_t>>\
    \ ret;\n    ret.reserve(std::distance(begin, end));\n\n    for (auto itr = begin;\
    \ itr != end;) {\n        std::size_t cnt = 1;\n        const auto head = itr++;\n\
    \        while (itr != end && *itr == *head) ++itr, ++cnt;\n        ret.emplace_back(head,\
    \ cnt);\n    }\n\n    ret.shrink_to_fit();\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/runlength.hpp
  requiredBy: []
  timestamp: '2020-09-18 19:25:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/helloworld/runlength.test.cpp
documentation_of: Util/runlength.hpp
layout: document
redirect_from:
- /library/Util/runlength.hpp
- /library/Util/runlength.hpp.html
title: "runlength() (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E)"
---
