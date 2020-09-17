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
  bundledCode: "#line 1 \"export/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#if 1  // {{{\n\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ rall(x) std::rbegin(x), std::rend(x)\n#define rep(i, begin, end) for (int64_t\
    \ i{begin}, i##_end{end}; i < i##_end; ++i)\n#define repc(i, begin, last) for\
    \ (int64_t i{begin}, i##_last{last}; i <= i##_last; ++i)\n#define repr(i, begin,\
    \ last) for (int64_t i{begin}, i##_last{last}; i >= i##_last; --i)\n\n#define\
    \ let const auto\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing\
    \ i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing usize = std::size_t;\n\
    \nconstexpr int32_t INF = 0x3f3f3f3f;\nconstexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n\
    \ntemplate <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 4,\
    \ std::nullptr_t> = nullptr>\nconstexpr T infinity() {\n    return INF;\n}\n\n\
    template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 8, std::nullptr_t>\
    \ = nullptr>\nconstexpr T infinity() {\n    return LINF;\n}\n\nvoid ioSetup()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \    std::cout << std::fixed << std::setprecision(11);\n    std::cerr << std::fixed\
    \ << std::setprecision(11);\n    std::clog << std::fixed << std::setprecision(11);\n\
    }\n\ntemplate <class T>\nstd::istream& operator,(std::istream& is, T& rhs) {\n\
    \    return is >> rhs;\n}\n\n#define var(type, ...) \\\n    type __VA_ARGS__;\
    \  \\\n    std::cin >> __VA_ARGS__\n\ninline void println() {\n    std::cout <<\
    \ '\\n';\n}\ntemplate <class Head, class... Tail>\ninline void println(Head&&\
    \ head, Tail&&... tail) {\n    std::cout << head << \" \" + (!sizeof...(tail));\n\
    \    println(std::forward<Tail>(tail)...);\n}\n\ntemplate <class Container, class\
    \ = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, Container& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << \" \" + (it == std::begin(v)) << *it;\n    return os;\n}\n\ntemplate\
    \ <class InputItr>\nvoid join(std::ostream& os, InputItr begin, InputItr end,\
    \ const char* delim, const char* last = \"\\n\") {\n    const char* tmp[] = {delim,\
    \ \"\"};\n    for (auto it = begin; it != end; ++it) os << tmp[it == begin] <<\
    \ *it;\n    os << last;\n}\n\ntemplate <class T>\ninline void bye(const T& x)\
    \ {\n    std::cout << x << '\\n', exit(0);\n}\n\ntemplate <class T, class U>\n\
    inline bool chmin(T& a, const U& b) {\n    return b < a && (a = b, true);\n}\n\
    \ntemplate <class T, class U>\ninline bool chmax(T& a, const U& b) {\n    return\
    \ b > a && (a = b, true);\n}\n\ninline int64_t divceil(int64_t a, int64_t b) {\n\
    \    return (a + b - 1) / b;\n}\n\n#endif  // }}}\n\n// constexpr int MOD = int(1e9)\
    \ + 7;\n// constexpr int MOD = 998244353;\n\nsigned main() {\n    ioSetup();\n\
    \n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#if 1  // {{{\n\n#define\
    \ all(x) std::begin(x), std::end(x)\n#define rall(x) std::rbegin(x), std::rend(x)\n\
    #define rep(i, begin, end) for (int64_t i{begin}, i##_end{end}; i < i##_end; ++i)\n\
    #define repc(i, begin, last) for (int64_t i{begin}, i##_last{last}; i <= i##_last;\
    \ ++i)\n#define repr(i, begin, last) for (int64_t i{begin}, i##_last{last}; i\
    \ >= i##_last; --i)\n\n#define let const auto\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using usize = std::size_t;\n\nconstexpr int32_t INF = 0x3f3f3f3f;\nconstexpr int64_t\
    \ LINF = 0x3f3f3f3f3f3f3f3fLL;\n\ntemplate <class T, std::enable_if_t<std::is_integral_v<T>\
    \ && sizeof(T) == 4, std::nullptr_t> = nullptr>\nconstexpr T infinity() {\n  \
    \  return INF;\n}\n\ntemplate <class T, std::enable_if_t<std::is_integral_v<T>\
    \ && sizeof(T) == 8, std::nullptr_t> = nullptr>\nconstexpr T infinity() {\n  \
    \  return LINF;\n}\n\nvoid ioSetup() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \    std::cout << std::fixed << std::setprecision(11);\n    std::cerr << std::fixed\
    \ << std::setprecision(11);\n    std::clog << std::fixed << std::setprecision(11);\n\
    }\n\ntemplate <class T>\nstd::istream& operator,(std::istream& is, T& rhs) {\n\
    \    return is >> rhs;\n}\n\n#define var(type, ...) \\\n    type __VA_ARGS__;\
    \  \\\n    std::cin >> __VA_ARGS__\n\ninline void println() {\n    std::cout <<\
    \ '\\n';\n}\ntemplate <class Head, class... Tail>\ninline void println(Head&&\
    \ head, Tail&&... tail) {\n    std::cout << head << \" \" + (!sizeof...(tail));\n\
    \    println(std::forward<Tail>(tail)...);\n}\n\ntemplate <class Container, class\
    \ = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::istream& operator>>(std::istream&\
    \ is, Container& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n\ntemplate\
    \ <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << \" \" + (it == std::begin(v)) << *it;\n    return os;\n}\n\ntemplate\
    \ <class InputItr>\nvoid join(std::ostream& os, InputItr begin, InputItr end,\
    \ const char* delim, const char* last = \"\\n\") {\n    const char* tmp[] = {delim,\
    \ \"\"};\n    for (auto it = begin; it != end; ++it) os << tmp[it == begin] <<\
    \ *it;\n    os << last;\n}\n\ntemplate <class T>\ninline void bye(const T& x)\
    \ {\n    std::cout << x << '\\n', exit(0);\n}\n\ntemplate <class T, class U>\n\
    inline bool chmin(T& a, const U& b) {\n    return b < a && (a = b, true);\n}\n\
    \ntemplate <class T, class U>\ninline bool chmax(T& a, const U& b) {\n    return\
    \ b > a && (a = b, true);\n}\n\ninline int64_t divceil(int64_t a, int64_t b) {\n\
    \    return (a + b - 1) / b;\n}\n\n#endif  // }}}\n\n// constexpr int MOD = int(1e9)\
    \ + 7;\n// constexpr int MOD = 998244353;\n\nsigned main() {\n    ioSetup();\n\
    \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: export/template.cpp
  requiredBy: []
  timestamp: '2020-09-11 10:56:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: export/template.cpp
layout: document
redirect_from:
- /library/export/template.cpp
- /library/export/template.cpp.html
title: export/template.cpp
---
