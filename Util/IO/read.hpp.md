---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: export/template-prototype.cpp
    title: export/template-prototype.cpp
  - icon: ':warning:'
    path: test/yosupo/static-range-sum.cpp
    title: test/yosupo/static-range-sum.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "read() (n\u500B\u5165\u529B\u3057\u3066Container\u306B\u683C\u7D0D\
      \u3057\u3066\u8FD4\u3059)"
    links: []
  bundledCode: "#line 2 \"Util/IO/read.hpp\"\n#include <iostream>\n#include <vector>\n\
    \n/**\n * @brief read() (n\u500B\u5165\u529B\u3057\u3066Container\u306B\u683C\u7D0D\
    \u3057\u3066\u8FD4\u3059)\n */\ntemplate <class T = int, template <class, class...>\
    \ class Container = std::vector>\nContainer<T> read(size_t n) {\n    Container<T>\
    \ ret(n);\n    for (auto& e : ret) std::cin >> e;\n    return ret;\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n\n/**\n * @brief read()\
    \ (n\u500B\u5165\u529B\u3057\u3066Container\u306B\u683C\u7D0D\u3057\u3066\u8FD4\
    \u3059)\n */\ntemplate <class T = int, template <class, class...> class Container\
    \ = std::vector>\nContainer<T> read(size_t n) {\n    Container<T> ret(n);\n  \
    \  for (auto& e : ret) std::cin >> e;\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/IO/read.hpp
  requiredBy:
  - export/template-prototype.cpp
  - test/yosupo/static-range-sum.cpp
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/IO/read.hpp
layout: document
redirect_from:
- /library/Util/IO/read.hpp
- /library/Util/IO/read.hpp.html
title: "read() (n\u500B\u5165\u529B\u3057\u3066Container\u306B\u683C\u7D0D\u3057\u3066\
  \u8FD4\u3059)"
---
