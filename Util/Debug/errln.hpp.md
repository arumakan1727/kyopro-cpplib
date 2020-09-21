---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/helloworld/rolling-hash.test.cpp
    title: test/helloworld/rolling-hash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "errln() (println()\u306Estderr\u7248, \u30C7\u30D0\u30C3\u30B0\
      \u6642\u306E\u307F\u6709\u52B9)"
    links: []
  bundledCode: "#line 2 \"Util/Debug/errln.hpp\"\n\n#include <iostream>\n\n/**\n *\
    \ @brief errln() (println()\u306Estderr\u7248, \u30C7\u30D0\u30C3\u30B0\u6642\u306E\
    \u307F\u6709\u52B9)\n */\ninline void eprintln() {\n    std::clog << std::endl;\n\
    }\ntemplate <class Head, class... Tail>\ninline void eprintln(Head&& head, Tail&&...\
    \ tail) {\n    std::clog << head << &\" \"[!sizeof...(tail)];\n    eprintln(std::forward<Tail>(tail)...);\n\
    }\n\n#ifdef LOCAL_DEBUG\n#define errln(...) std::clog << __FILE__ << \"(\" <<\
    \ __LINE__ << \")[\" << __func__ << \"()]: \", eprintln(__VA_ARGS__)\n#else\n\
    #define errln(...) ((void)0)\n#endif\n"
  code: "#pragma once\n\n#include <iostream>\n\n/**\n * @brief errln() (println()\u306E\
    stderr\u7248, \u30C7\u30D0\u30C3\u30B0\u6642\u306E\u307F\u6709\u52B9)\n */\ninline\
    \ void eprintln() {\n    std::clog << std::endl;\n}\ntemplate <class Head, class...\
    \ Tail>\ninline void eprintln(Head&& head, Tail&&... tail) {\n    std::clog <<\
    \ head << &\" \"[!sizeof...(tail)];\n    eprintln(std::forward<Tail>(tail)...);\n\
    }\n\n#ifdef LOCAL_DEBUG\n#define errln(...) std::clog << __FILE__ << \"(\" <<\
    \ __LINE__ << \")[\" << __func__ << \"()]: \", eprintln(__VA_ARGS__)\n#else\n\
    #define errln(...) ((void)0)\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/Debug/errln.hpp
  requiredBy: []
  timestamp: '2020-09-20 14:54:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/helloworld/rolling-hash.test.cpp
documentation_of: Util/Debug/errln.hpp
layout: document
redirect_from:
- /library/Util/Debug/errln.hpp
- /library/Util/Debug/errln.hpp.html
title: "errln() (println()\u306Estderr\u7248, \u30C7\u30D0\u30C3\u30B0\u6642\u306E\
  \u307F\u6709\u52B9)"
---
