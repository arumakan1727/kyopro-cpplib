---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "join() (\u8981\u7D20\u3092\u533A\u5207\u308A\u6587\u5B57\u3067\
      \u7D50\u5408\u3057\u3066\u51FA\u529B)"
    links: []
  bundledCode: "#line 2 \"Util/IO/join-into-ostream.hpp\"\n#include <iostream>\n\n\
    /**\n * @brief join() (\u8981\u7D20\u3092\u533A\u5207\u308A\u6587\u5B57\u3067\u7D50\
    \u5408\u3057\u3066\u51FA\u529B)\n */\ntemplate <class InputItr>\nvoid join(std::ostream&\
    \ os, InputItr begin, InputItr end, const char* delim, const char* last = \"\\\
    n\") {\n    const char* tmp[] = {delim, \"\"};\n    for (auto it = begin; it !=\
    \ end; ++it) os << tmp[it == begin] << *it;\n    os << last;\n}\n"
  code: "#pragma once\n#include <iostream>\n\n/**\n * @brief join() (\u8981\u7D20\u3092\
    \u533A\u5207\u308A\u6587\u5B57\u3067\u7D50\u5408\u3057\u3066\u51FA\u529B)\n */\n\
    template <class InputItr>\nvoid join(std::ostream& os, InputItr begin, InputItr\
    \ end, const char* delim, const char* last = \"\\n\") {\n    const char* tmp[]\
    \ = {delim, \"\"};\n    for (auto it = begin; it != end; ++it) os << tmp[it ==\
    \ begin] << *it;\n    os << last;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Util/IO/join-into-ostream.hpp
  requiredBy: []
  timestamp: '2020-09-08 04:00:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/IO/join-into-ostream.hpp
layout: document
redirect_from:
- /library/Util/IO/join-into-ostream.hpp
- /library/Util/IO/join-into-ostream.hpp.html
title: "join() (\u8981\u7D20\u3092\u533A\u5207\u308A\u6587\u5B57\u3067\u7D50\u5408\
  \u3057\u3066\u51FA\u529B)"
---
