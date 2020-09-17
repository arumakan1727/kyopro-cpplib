---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_5_A.test.cpp
    title: test/AOJ/DPL_5_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\
      \u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)"
    links: []
  bundledCode: "#line 2 \"Util/IO/println.hpp\"\n#include <iostream>\n#include <utility>\n\
    \n/**\n * @brief println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\
    \u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)\n */\ninline\
    \ void println() {\n    std::cout << '\\n';\n}\ntemplate <class Head, class...\
    \ Tail>\ninline void println(Head&& head, Tail&&... tail) {\n    std::cout <<\
    \ head << &\" \"[!sizeof...(tail)];\n    println(std::forward<Tail>(tail)...);\n\
    }\n"
  code: "#pragma once\n#include <iostream>\n#include <utility>\n\n/**\n * @brief println()\
    \ (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\
    \u529B\u3057\u3066\u6539\u884C\u3059\u308B)\n */\ninline void println() {\n  \
    \  std::cout << '\\n';\n}\ntemplate <class Head, class... Tail>\ninline void println(Head&&\
    \ head, Tail&&... tail) {\n    std::cout << head << &\" \"[!sizeof...(tail)];\n\
    \    println(std::forward<Tail>(tail)...);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/IO/println.hpp
  requiredBy:
  - export/template-prototype.cpp
  timestamp: '2020-09-17 10:59:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL_5_A.test.cpp
documentation_of: Util/IO/println.hpp
layout: document
redirect_from:
- /library/Util/IO/println.hpp
- /library/Util/IO/println.hpp.html
title: "println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\u308A\
  \u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)"
---
