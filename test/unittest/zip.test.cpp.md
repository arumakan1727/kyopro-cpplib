---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/zip.hpp
    title: "zip() (n\u500B\u306Evector\u304B\u3089n\u8981\u7D20\u306E\u30BF\u30D7\u30EB\
      \u306Evector\u3092\u751F\u6210\u3059\u308B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/zip.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <vector>\n#include <string>\n\
    \n#line 2 \"Util/zip.hpp\"\n\n#include <algorithm>\n#line 5 \"Util/zip.hpp\"\n\
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
    }\n#line 8 \"test/unittest/zip.test.cpp\"\n\nint main() {\n    using namespace\
    \ std;\n    std::cout << \"Hello World\" << std::endl;\n\n    vector<int> a{0,\
    \ 1, 2, 3, 4, 5, 6, 7, 8, 9};\n    vector<char> c{'a', 'b', 'c', 'd'};\n    vector<string>\
    \ s{\"zero\", \"one\", \"two\"};\n\n    const vector<pair<int, char>> excpect1\
    \ = {\n        {0, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}\n    };\n\n    const vector<tuple<int,\
    \ char, string>> excpect2 = {\n        {0, 'a', \"zero\"}, {1, 'b', \"one\"},\
    \ {2, 'c', \"two\"}\n    };\n\n    assert(zip(a, c) == excpect1);\n    assert(zip(a,\
    \ c, s) == excpect2);\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <vector>\n#include <string>\n\
    \n#include \"../../Util/zip.hpp\"\n\nint main() {\n    using namespace std;\n\
    \    std::cout << \"Hello World\" << std::endl;\n\n    vector<int> a{0, 1, 2,\
    \ 3, 4, 5, 6, 7, 8, 9};\n    vector<char> c{'a', 'b', 'c', 'd'};\n    vector<string>\
    \ s{\"zero\", \"one\", \"two\"};\n\n    const vector<pair<int, char>> excpect1\
    \ = {\n        {0, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}\n    };\n\n    const vector<tuple<int,\
    \ char, string>> excpect2 = {\n        {0, 'a', \"zero\"}, {1, 'b', \"one\"},\
    \ {2, 'c', \"two\"}\n    };\n\n    assert(zip(a, c) == excpect1);\n    assert(zip(a,\
    \ c, s) == excpect2);\n\n    return 0;\n}\n"
  dependsOn:
  - Util/zip.hpp
  isVerificationFile: true
  path: test/unittest/zip.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 19:25:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/zip.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/zip.test.cpp
- /verify/test/unittest/zip.test.cpp.html
title: test/unittest/zip.test.cpp
---
