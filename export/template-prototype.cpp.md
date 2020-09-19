---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/all-macro.hpp
    title: "all()\u30DE\u30AF\u30ED"
  - icon: ':warning:'
    path: Util/rep-macro.hpp
    title: "rep()\u30DE\u30AF\u30ED"
  - icon: ':heavy_check_mark:'
    path: Util/int-alias.hpp
    title: "int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)"
  - icon: ':heavy_check_mark:'
    path: Util/int-infinity.hpp
    title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
  - icon: ':warning:'
    path: Util/IO/container-io.hpp
    title: "\u30B3\u30F3\u30C6\u30CA\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Util/IO/var-declaration-with-input.hpp
    title: "\u8907\u6570\u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\u6642\u306B\
      \u5165\u529B\u3082\u3059\u308B\u3084\u3064"
  - icon: ':heavy_check_mark:'
    path: Util/IO/println.hpp
    title: "println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\
      \u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)"
  - icon: ':heavy_check_mark:'
    path: Util/chminmax.hpp
    title: chmin(), chmax()
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"export/template-prototype.cpp\"\n#include <bits/stdc++.h>\n\
    // header {{{\n#line 2 \"Util/all-macro.hpp\"\n\n/**\n * @brief all()\u30DE\u30AF\
    \u30ED\n */\n#define all(x) std::begin(x), std::end(x)\n#define rall(x) std::rbegin(x),\
    \ std::rend(x)\n#line 2 \"Util/rep-macro.hpp\"\n\n/**\n * @brief rep()\u30DE\u30AF\
    \u30ED\n */\n#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_end = (end); i < i##_end; ++i)\n#define repc(i, begin, last)\
    \ for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin), i##_last\
    \ = (last); i <= i##_last; ++i)\n#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_last = (last); i >= i##_last; --i)\n#line 5 \"export/template-prototype.cpp\"\
    \n#define let const auto\n#line 3 \"Util/int-alias.hpp\"\n\n/**\n * @brief int-alias\
    \ (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)\n */\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\n#line 3 \"Util/int-infinity.hpp\"\n\n/**\n * @brief\
    \ int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)\n * 2\u500D\u3057\u3066\
    \u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 & memset()\u306B\
    \u3082\u4F7F\u3048\u308B (\u9700\u8981\u3042\u308B\uFF1F)\n */\nconstexpr std::int32_t\
    \ INF = 0x3f3f3f3f;\nconstexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n#line\
    \ 8 \"export/template-prototype.cpp\"\n\n#line 3 \"Util/IO/container-io.hpp\"\n\
    \n/**\n * @brief \u30B3\u30F3\u30C6\u30CA\u306E\u5165\u51FA\u529B\n */\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, Container& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << &\" \"[it == std::begin(v)] << *it;\n    return os;\n}\n#line 10\
    \ \"export/template-prototype.cpp\"\n\n#line 3 \"Util/IO/var-declaration-with-input.hpp\"\
    \n\n/**\n * @brief \u8907\u6570\u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\
    \u6642\u306B\u5165\u529B\u3082\u3059\u308B\u3084\u3064\n */\ntemplate <class T>\n\
    std::istream& operator,(std::istream& is, T& rhs) {\n    return is >> rhs;\n}\n\
    \n#define var(type, ...) \\\n    type __VA_ARGS__;  \\\n    std::cin >> __VA_ARGS__\n\
    #line 12 \"export/template-prototype.cpp\"\n\n#line 4 \"Util/IO/println.hpp\"\n\
    \n/**\n * @brief println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\
    \u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)\n */\ninline\
    \ void println() {\n    std::cout << '\\n';\n}\ntemplate <class Head, class...\
    \ Tail>\ninline void println(Head&& head, Tail&&... tail) {\n    std::cout <<\
    \ head << &\" \"[!sizeof...(tail)];\n    println(std::forward<Tail>(tail)...);\n\
    }\n#line 14 \"export/template-prototype.cpp\"\n\n#line 2 \"Util/chminmax.hpp\"\
    \n\n/**\n * @brief chmin(), chmax()\n */\ntemplate <class T, class U>\ninline\
    \ bool chmin(T& a, const U& b) {\n    return b < a && (a = b, true);\n}\n\ntemplate\
    \ <class T, class U>\ninline bool chmax(T& a, const U& b) {\n    return b > a\
    \ && (a = b, true);\n}\n#line 16 \"export/template-prototype.cpp\"\n// }}}\n\n\
    using namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << std::fixed << std::setprecision(12);\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n// header {{{\n#include \"../Util/all-macro.hpp\"\
    \n#include \"../Util/rep-macro.hpp\"\n#define let const auto\n#include \"../Util/int-alias.hpp\"\
    \n#include \"../Util/int-infinity.hpp\"\n\n#include \"../Util/IO/container-io.hpp\"\
    \n\n#include \"../Util/IO/var-declaration-with-input.hpp\"\n\n#include \"../Util/IO/println.hpp\"\
    \n\n#include \"../Util/chminmax.hpp\"\n// }}}\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n    cout <<\
    \ std::fixed << std::setprecision(12);\n\n    return 0;\n}\n"
  dependsOn:
  - Util/all-macro.hpp
  - Util/rep-macro.hpp
  - Util/int-alias.hpp
  - Util/int-infinity.hpp
  - Util/IO/container-io.hpp
  - Util/IO/var-declaration-with-input.hpp
  - Util/IO/println.hpp
  - Util/chminmax.hpp
  isVerificationFile: false
  path: export/template-prototype.cpp
  requiredBy: []
  timestamp: '2020-09-19 13:34:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: export/template-prototype.cpp
layout: document
redirect_from:
- /library/export/template-prototype.cpp
- /library/export/template-prototype.cpp.html
title: export/template-prototype.cpp
---
