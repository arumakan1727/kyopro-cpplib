---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/fix-point.hpp
    title: "FixPoint (\u30E9\u30E0\u30C0\u5F0F\u306E\u518D\u5E30)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/helloworld/fix-point.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <iostream>\n#include <cassert>\n\n#line 2 \"Util/fix-point.hpp\"\n#include <functional>\n\
    \n/**\n * @brief FixPoint (\u30E9\u30E0\u30C0\u5F0F\u306E\u518D\u5E30)\n *\n *\
    \ (Ex) FixPoint([&](auto func, int n) -> int {...})(10);\n */\ntemplate <class\
    \ F>\nstruct FixPoint : F {\n    FixPoint(F&& f)\n        : F(std::forward<F>(f))\
    \ {}\n\n    template <class... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n#line 6 \"test/helloworld/fix-point.test.cpp\"\n\nvoid FixPoint_test()\
    \ {\n    const auto factorial = FixPoint([](auto f, int n) -> int {\n        if\
    \ (n <= 1) return 1;\n        return n * f(n - 1);\n    });\n\n    assert(factorial(5)\
    \ == 120);\n\n    std::clog << __func__ << \" : OK\" << std::endl;\n}\n\nint main()\
    \ {\n    std::cout << \"Hello World\" << std::endl;\n\n    FixPoint_test();\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <iostream>\n#include <cassert>\n\n#include \"../../Util/fix-point.hpp\"\
    \n\nvoid FixPoint_test() {\n    const auto factorial = FixPoint([](auto f, int\
    \ n) -> int {\n        if (n <= 1) return 1;\n        return n * f(n - 1);\n \
    \   });\n\n    assert(factorial(5) == 120);\n\n    std::clog << __func__ << \"\
    \ : OK\" << std::endl;\n}\n\nint main() {\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n\n    FixPoint_test();\n\n    return 0;\n}\n"
  dependsOn:
  - Util/fix-point.hpp
  isVerificationFile: true
  path: test/helloworld/fix-point.test.cpp
  requiredBy: []
  timestamp: '2020-10-25 20:18:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/helloworld/fix-point.test.cpp
layout: document
redirect_from:
- /verify/test/helloworld/fix-point.test.cpp
- /verify/test/helloworld/fix-point.test.cpp.html
title: test/helloworld/fix-point.test.cpp
---
