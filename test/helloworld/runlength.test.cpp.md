---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/runlength.hpp
    title: "runlength() (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/helloworld/runlength.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <bits/stdc++.h>\n\n#line 5 \"Util/runlength.hpp\"\n\n/**\n * @brief runlength()\
    \ (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E)\n * (\u304B\u305F\u307E\u308A\
    \u306E\u59CB\u307E\u308A\u4F4D\u7F6E\u30A4\u30C6\u30EC\u30FC\u30BF, \u304B\u305F\
    \u307E\u308A\u306E\u8981\u7D20\u6570) \u306Epair\u306Evector\u3092\u8FD4\u3059\
    \u3002\n */\ntemplate <class Iterator>\nauto runlength(Iterator const begin, Iterator\
    \ const end) {\n    std::vector<std::pair<Iterator, std::size_t>> ret;\n    ret.reserve(std::distance(begin,\
    \ end));\n\n    for (auto itr = begin; itr != end;) {\n        std::size_t cnt\
    \ = 1;\n        const auto head = itr++;\n        while (itr != end && *itr ==\
    \ *head) ++itr, ++cnt;\n        ret.emplace_back(head, cnt);\n    }\n\n    ret.shrink_to_fit();\n\
    \    return ret;\n}\n#line 5 \"test/helloworld/runlength.test.cpp\"\n\nusing namespace\
    \ std;\n\nvoid test1() {\n    array<int, 6> a{1, 1, 5, 5, 5, -8};\n\n    const\
    \ vector<pair<decltype(a)::iterator, size_t>> expected = {\n        {begin(a)\
    \ + 0, size_t(2)},\n        {begin(a) + 2, size_t(3)},\n        {begin(a) + 5,\
    \ size_t(1)},\n    };\n\n    assert(runlength(begin(a), end(a)) == expected);\n\
    \    clog << __func__ << \" : OK\" << endl;\n}\n\nvoid test2() {\n    array<int,\
    \ 1> a{1727};\n\n    const vector<pair<decltype(a)::iterator, size_t>> expected\
    \ = {\n        {begin(a) + 0, size_t(1)},\n    };\n\n    assert(runlength(begin(a),\
    \ end(a)) == expected);\n    clog << __func__ << \" : OK\" << endl;\n}\n\nvoid\
    \ test3() {\n    string s = \"x01ssss\";\n\n    const vector<pair<decltype(s)::iterator,\
    \ size_t>> expected = {\n        {begin(s) + 0, size_t(1)},\n        {begin(s)\
    \ + 1, size_t(1)},\n        {begin(s) + 2, size_t(1)},\n        {begin(s) + 3,\
    \ size_t(4)},\n    };\n\n    assert(runlength(begin(s), end(s)) == expected);\n\
    \    clog << __func__ << \" : OK\" << endl;\n}\n\nint main() {\n    std::cout\
    \ << \"Hello World\" << std::endl;\n\n    test1();\n    test2();\n    test3();\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../Util/runlength.hpp\"\n\nusing namespace\
    \ std;\n\nvoid test1() {\n    array<int, 6> a{1, 1, 5, 5, 5, -8};\n\n    const\
    \ vector<pair<decltype(a)::iterator, size_t>> expected = {\n        {begin(a)\
    \ + 0, size_t(2)},\n        {begin(a) + 2, size_t(3)},\n        {begin(a) + 5,\
    \ size_t(1)},\n    };\n\n    assert(runlength(begin(a), end(a)) == expected);\n\
    \    clog << __func__ << \" : OK\" << endl;\n}\n\nvoid test2() {\n    array<int,\
    \ 1> a{1727};\n\n    const vector<pair<decltype(a)::iterator, size_t>> expected\
    \ = {\n        {begin(a) + 0, size_t(1)},\n    };\n\n    assert(runlength(begin(a),\
    \ end(a)) == expected);\n    clog << __func__ << \" : OK\" << endl;\n}\n\nvoid\
    \ test3() {\n    string s = \"x01ssss\";\n\n    const vector<pair<decltype(s)::iterator,\
    \ size_t>> expected = {\n        {begin(s) + 0, size_t(1)},\n        {begin(s)\
    \ + 1, size_t(1)},\n        {begin(s) + 2, size_t(1)},\n        {begin(s) + 3,\
    \ size_t(4)},\n    };\n\n    assert(runlength(begin(s), end(s)) == expected);\n\
    \    clog << __func__ << \" : OK\" << endl;\n}\n\nint main() {\n    std::cout\
    \ << \"Hello World\" << std::endl;\n\n    test1();\n    test2();\n    test3();\n\
    \n    return 0;\n}\n"
  dependsOn:
  - Util/runlength.hpp
  isVerificationFile: true
  path: test/helloworld/runlength.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 11:43:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/helloworld/runlength.test.cpp
layout: document
redirect_from:
- /verify/test/helloworld/runlength.test.cpp
- /verify/test/helloworld/runlength.test.cpp.html
title: test/helloworld/runlength.test.cpp
---
