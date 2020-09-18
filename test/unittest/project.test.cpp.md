---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/project.hpp
    title: "project() (\u30BF\u30D7\u30EB\u306E\u30B3\u30F3\u30C6\u30CA\u306E\u7B2C\
      \ I \u8981\u7D20\u3092\u62BD\u51FA\u3057\u305Fvector\u3092\u8FD4\u3059)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/project.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#line 6 \"Util/project.hpp\"\n\n/**\n * @brief project()\
    \ (\u30BF\u30D7\u30EB\u306E\u30B3\u30F3\u30C6\u30CA\u306E\u7B2C I \u8981\u7D20\
    \u3092\u62BD\u51FA\u3057\u305Fvector\u3092\u8FD4\u3059)\n */\ntemplate <std::size_t\
    \ I, class Container, class Value = typename std::tuple_element_t<I, typename\
    \ Container::value_type>>\nstd::vector<Value> project(const Container& v) {\n\
    \    std::vector<Value> ret(v.size());\n    std::transform(v.begin(), v.end(),\
    \ ret.begin(), [](auto&& t) { return std::get<I>(t); });\n    return ret;\n}\n\
    #line 5 \"test/unittest/project.test.cpp\"\n\nusing namespace std;\n\nvoid test1()\
    \ {\n    vector<pair<int, char>> a {\n        {0, 'a'},\n        {1, 'b'},\n \
    \       {2, 'c'},\n    };\n\n    const vector<int> expected0 = {0, 1, 2};\n  \
    \  const vector<char> expected1 = {'a', 'b', 'c'};\n\n    assert(project<0>(a)\
    \ == expected0);\n    assert(project<1>(a) == expected1);\n\n    clog << __func__\
    \ << \" : OK\" << endl;\n}\n\nvoid test2() {\n    vector<tuple<int, char, bool>>\
    \ a {\n        {0, 'a', true},\n        {1, 'b', false},\n        {2, 'c', true},\n\
    \    };\n\n    const vector<int> expected0 = {0, 1, 2};\n    const vector<char>\
    \ expected1 = {'a', 'b', 'c'};\n    const vector<bool> expected2 = {true, false,\
    \ true};\n\n    assert(project<0>(a) == expected0);\n    assert(project<1>(a)\
    \ == expected1);\n    assert(project<2>(a) == expected2);\n\n    clog << __func__\
    \ << \" : OK\" << endl;\n}\n\nint main() {\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n\n    test1();\n    test2();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../Util/project.hpp\"\n\nusing namespace\
    \ std;\n\nvoid test1() {\n    vector<pair<int, char>> a {\n        {0, 'a'},\n\
    \        {1, 'b'},\n        {2, 'c'},\n    };\n\n    const vector<int> expected0\
    \ = {0, 1, 2};\n    const vector<char> expected1 = {'a', 'b', 'c'};\n\n    assert(project<0>(a)\
    \ == expected0);\n    assert(project<1>(a) == expected1);\n\n    clog << __func__\
    \ << \" : OK\" << endl;\n}\n\nvoid test2() {\n    vector<tuple<int, char, bool>>\
    \ a {\n        {0, 'a', true},\n        {1, 'b', false},\n        {2, 'c', true},\n\
    \    };\n\n    const vector<int> expected0 = {0, 1, 2};\n    const vector<char>\
    \ expected1 = {'a', 'b', 'c'};\n    const vector<bool> expected2 = {true, false,\
    \ true};\n\n    assert(project<0>(a) == expected0);\n    assert(project<1>(a)\
    \ == expected1);\n    assert(project<2>(a) == expected2);\n\n    clog << __func__\
    \ << \" : OK\" << endl;\n}\n\nint main() {\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n\n    test1();\n    test2();\n\n    return 0;\n}\n"
  dependsOn:
  - Util/project.hpp
  isVerificationFile: true
  path: test/unittest/project.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 19:25:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/project.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/project.test.cpp
- /verify/test/unittest/project.test.cpp.html
title: test/unittest/project.test.cpp
---
