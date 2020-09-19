---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"export/template.cpp\"\n#include <bits/stdc++.h>\n// header\
    \ {{{\n#define all(x) std::begin(x), std::end(x)\n#define rall(x) std::rbegin(x),\
    \ std::rend(x)\n#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_end = (end); i < i##_end; ++i)\n#define repc(i, begin, last)\
    \ for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin), i##_last\
    \ = (last); i <= i##_last; ++i)\n#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_last = (last); i >= i##_last; --i)\n#define let const auto\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nconstexpr std::int32_t\
    \ INF = 0x3f3f3f3f;\nconstexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, Container& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << &\" \"[it == std::begin(v)] << *it;\n    return os;\n}\n\ntemplate\
    \ <class T>\nstd::istream& operator,(std::istream& is, T& rhs) {\n    return is\
    \ >> rhs;\n}\n\n#define var(type, ...) \\\n    type __VA_ARGS__;  \\\n    std::cin\
    \ >> __VA_ARGS__\n\ninline void println() {\n    std::cout << '\\n';\n}\ntemplate\
    \ <class Head, class... Tail>\ninline void println(Head&& head, Tail&&... tail)\
    \ {\n    std::cout << head << &\" \"[!sizeof...(tail)];\n    println(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <class T, class U>\ninline bool chmin(T& a, const U& b) {\n    return\
    \ b < a && (a = b, true);\n}\n\ntemplate <class T, class U>\ninline bool chmax(T&\
    \ a, const U& b) {\n    return b > a && (a = b, true);\n}\n// }}}\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << std::fixed << std::setprecision(12);\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n// header {{{\n#define all(x) std::begin(x), std::end(x)\n\
    #define rall(x) std::rbegin(x), std::rend(x)\n#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_end = (end); i < i##_end; ++i)\n#define repc(i, begin, last)\
    \ for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin), i##_last\
    \ = (last); i <= i##_last; ++i)\n#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_last = (last); i >= i##_last; --i)\n#define let const auto\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nconstexpr std::int32_t\
    \ INF = 0x3f3f3f3f;\nconstexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, Container& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << &\" \"[it == std::begin(v)] << *it;\n    return os;\n}\n\ntemplate\
    \ <class T>\nstd::istream& operator,(std::istream& is, T& rhs) {\n    return is\
    \ >> rhs;\n}\n\n#define var(type, ...) \\\n    type __VA_ARGS__;  \\\n    std::cin\
    \ >> __VA_ARGS__\n\ninline void println() {\n    std::cout << '\\n';\n}\ntemplate\
    \ <class Head, class... Tail>\ninline void println(Head&& head, Tail&&... tail)\
    \ {\n    std::cout << head << &\" \"[!sizeof...(tail)];\n    println(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <class T, class U>\ninline bool chmin(T& a, const U& b) {\n    return\
    \ b < a && (a = b, true);\n}\n\ntemplate <class T, class U>\ninline bool chmax(T&\
    \ a, const U& b) {\n    return b > a && (a = b, true);\n}\n// }}}\n\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << std::fixed << std::setprecision(12);\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: export/template.cpp
  requiredBy: []
  timestamp: '2020-09-19 04:36:29+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: export/template.cpp
layout: document
redirect_from:
- /library/export/template.cpp
- /library/export/template.cpp.html
title: export/template.cpp
---
