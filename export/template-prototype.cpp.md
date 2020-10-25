---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Util/Debug/debug.hpp
    title: Debug
  - icon: ':warning:'
    path: Util/IO/container-output.hpp
    title: "std::ostream\u306B\u3088\u308B\u30B3\u30F3\u30C6\u30CA\u306E\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Util/IO/println.hpp
    title: "println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\
      \u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)"
  - icon: ':heavy_check_mark:'
    path: Util/IO/read.hpp
    title: "read() (n\u500B\u5165\u529B\u3057\u3066Container\u306B\u683C\u7D0D\u3057\
      \u3066\u8FD4\u3059)"
  - icon: ':heavy_check_mark:'
    path: Util/IO/var-declaration-with-input.hpp
    title: "\u8907\u6570\u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\u6642\u306B\
      \u5165\u529B\u3082\u3059\u308B\u3084\u3064"
  - icon: ':heavy_check_mark:'
    path: Util/all-macro.hpp
    title: "all()\u30DE\u30AF\u30ED"
  - icon: ':heavy_check_mark:'
    path: Util/chminmax.hpp
    title: chmin(), chmax()
  - icon: ':heavy_check_mark:'
    path: Util/int-alias.hpp
    title: "int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)"
  - icon: ':heavy_check_mark:'
    path: Util/int-infinity.hpp
    title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
  - icon: ':heavy_check_mark:'
    path: Util/makeVec.hpp
    title: "makeVec() (\u591A\u6B21\u5143std::vector\u306E\u751F\u6210)"
  - icon: ':heavy_check_mark:'
    path: Util/rep-macro.hpp
    title: "rep()\u30DE\u30AF\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"export/template-prototype.cpp\"\n#include <bits/stdc++.h>\n\
    // header {{{\n#line 2 \"Util/all-macro.hpp\"\n\n/**\n * @brief all()\u30DE\u30AF\
    \u30ED\n */\n#define all(x) std::begin(x), std::end(x)\n#define rall(x) std::rbegin(x),\
    \ std::rend(x)\n#line 2 \"Util/rep-macro.hpp\"\n\n/**\n * @brief rep()\u30DE\u30AF\
    \u30ED\n */\n#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_end = (end); i < i##_end; ++i)\n#define repc(i, begin, last)\
    \ for (std::make_signed_t<std::remove_cv_t<decltype(last)>> i = (begin), i##_last\
    \ = (last); i <= i##_last; ++i)\n#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(begin)>>\
    \ i = (begin), i##_last = (last); i >= i##_last; --i)\n#line 5 \"export/template-prototype.cpp\"\
    \n#define let const auto\n#line 3 \"Util/int-alias.hpp\"\n\n/**\n * @brief int-alias\
    \ (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)\n */\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\n#line 3 \"Util/int-infinity.hpp\"\n\n/**\n * @brief int-infinity\
    \ (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)\n * 2\u500D\u3057\u3066\u3082\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 & memset()\u306B\u3082\u4F7F\
    \u3048\u308B (\u9700\u8981\u3042\u308B\uFF1F)\n */\nconstexpr int32_t INF = 0x3f3f3f3f;\n\
    constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n#line 8 \"export/template-prototype.cpp\"\
    \n\n#line 4 \"Util/IO/read.hpp\"\n\n/**\n * @brief read() (n\u500B\u5165\u529B\
    \u3057\u3066Container\u306B\u683C\u7D0D\u3057\u3066\u8FD4\u3059)\n */\ntemplate\
    \ <class T = int, template <class, class...> class Container = std::vector>\n\
    Container<T> read(size_t n) {\n    Container<T> ret(n);\n    for (auto& e : ret)\
    \ std::cin >> e;\n    return ret;\n}\n#line 10 \"export/template-prototype.cpp\"\
    \n\n#line 3 \"Util/IO/container-output.hpp\"\n\n/**\n * @brief std::ostream\u306B\
    \u3088\u308B\u30B3\u30F3\u30C6\u30CA\u306E\u51FA\u529B\n */\ntemplate <class Container,\
    \ class = typename Container::value_type, std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream&\
    \ os, const Container& v) {\n    for (auto it = std::begin(v); it != std::end(v);\
    \ ++it) os << &\" \"[it == std::begin(v)] << *it;\n    return os;\n}\n#line 12\
    \ \"export/template-prototype.cpp\"\n\n#line 3 \"Util/IO/var-declaration-with-input.hpp\"\
    \n\n/**\n * @brief \u8907\u6570\u5909\u6570\u5BA3\u8A00\u3092\u3057\u3066\u540C\
    \u6642\u306B\u5165\u529B\u3082\u3059\u308B\u3084\u3064\n */\ntemplate <class T>\n\
    std::istream& operator,(std::istream& is, T& rhs) {\n    return is >> rhs;\n}\n\
    \n#define var(type, ...) \\\n    type __VA_ARGS__;  \\\n    std::cin >> __VA_ARGS__\n\
    #line 14 \"export/template-prototype.cpp\"\n\n#line 4 \"Util/IO/println.hpp\"\n\
    \n/**\n * @brief println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\
    \u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)\n */\ninline\
    \ void println() {\n    std::cout << '\\n';\n}\ntemplate <class Head, class...\
    \ Tail>\ninline void println(Head&& head, Tail&&... tail) {\n    std::cout <<\
    \ head << &\" \"[!sizeof...(tail)];\n    println(std::forward<Tail>(tail)...);\n\
    }\n#line 16 \"export/template-prototype.cpp\"\n\n#line 2 \"Util/chminmax.hpp\"\
    \n\n/**\n * @brief chmin(), chmax()\n */\ntemplate <class T, class U>\ninline\
    \ bool chmin(T& a, const U& b) {\n    return b < a && (a = b, true);\n}\n\ntemplate\
    \ <class T, class U>\ninline bool chmax(T& a, const U& b) {\n    return b > a\
    \ && (a = b, true);\n}\n#line 18 \"export/template-prototype.cpp\"\n\n#line 3\
    \ \"Util/makeVec.hpp\"\n\n/**\n * @brief makeVec() (\u591A\u6B21\u5143std::vector\u306E\
    \u751F\u6210)\n */\ntemplate <class T>\ninline std::vector<T> makeVec(size_t sz,\
    \ const T& initValue) {\n    return std::vector<T>(sz, initValue);\n}\ntemplate\
    \ <class T, class... Args>\ninline auto makeVec(size_t sz, Args... args) {\n \
    \   return std::vector<decltype(makeVec<T>(args...))>(sz, makeVec<T>(args...));\n\
    }\n#line 20 \"export/template-prototype.cpp\"\n// }}}\n\n// debug {{{\n#line 5\
    \ \"Util/Debug/debug.hpp\"\n\n#line 7 \"Util/Debug/debug.hpp\"\n\n/**\n * @brief\
    \ Debug\n */\n#ifdef LOCAL_DEBUG\n\nnamespace dbg {\n\nint w_ = 4;\nbool negativeValAsNull_\
    \ = true;\nstd::ostream* os = &std::cerr;\n\ntemplate <class T, std::enable_if_t<!std::is_arithmetic<T>::value,\
    \ std::nullptr_t> = nullptr>\nvoid put(const T& x) {\n    *os << std::setw(w_)\
    \ << x;\n}\ntemplate <class T, std::enable_if_t<std::is_signed<T>::value, std::nullptr_t>\
    \ = nullptr>\nvoid put(const T& x) {\n    if (x <= -INF)\n        *os << std::setw(w_)\
    \ << \"-INF\";\n    else if (negativeValAsNull_ && x < 0)\n        *os << std::setw(w_)\
    \ << \" - \";\n    else if (x >= INF)\n        *os << std::setw(w_) << \"INF\"\
    ;\n    else\n        *os << std::setw(w_) << x;\n}\ntemplate <class T, std::enable_if_t<std::is_unsigned<T>::value,\
    \ std::nullptr_t> = nullptr>\nvoid put(const T& x) {\n    if (static_cast<int64_t>(x)\
    \ >= static_cast<int64_t>(INF))\n        *os << std::setw(w_) << \"INF\";\n  \
    \  else\n        *os << std::setw(w_) << x;\n}\ntemplate <class A, class B>\n\
    void put(const std::pair<A, B>& t) {\n    *os << '(' << std::setw(w_) << std::get<0>(t)\
    \ << \",  \" << std::setw(w_) << std::get<1>(t) << ')';\n}\ntemplate <class A,\
    \ class B, class C>\nvoid put(const std::tuple<A, B, C>& t) {\n    *os << '('\
    \ << std::setw(w_) << std::get<0>(t) << \",  \" << std::setw(w_) << std::get<1>(t)\
    \ << \",  \" << std::setw(w_) << std::get<2>(t) << ')';\n}\n\ntemplate <class\
    \ Arr>\nvoid showArrayH__(const Arr& a, size_t begin, size_t end) {\n    for (size_t\
    \ i = begin; i < end; ++i) *os << '[' << std::setw(dbg::w_) << i << \"] \";\n\
    \    *os << '\\n';\n    for (size_t i = begin; i < end; ++i) *os << ' ', dbg::put(a[i]),\
    \ *os << \"  \";\n    *os << '\\n';\n}\ntemplate <class Arr>\nvoid showArrayV__(const\
    \ Arr& a, size_t begin, size_t end) {\n    for (size_t i = begin; i < end; ++i)\n\
    \        *os << '[' << std::setw(2) << i << ']', dbg::put(a[i]), *os << \"\\n\"\
    ;\n    *os << std::flush;\n}\ntemplate <class Table>\nvoid showTable__(const Table&\
    \ t, size_t yBegin, size_t yEnd, size_t xBegin, size_t xEnd) {\n    *os << std::string(1\
    \ + 2 + 1, ' ');\n    for (size_t j = xBegin; j < xEnd; ++j) *os << '[' << std::setw(dbg::w_)\
    \ << j << \"] \";\n    *os << '\\n';\n\n    for (size_t i = yBegin; i < yEnd;\
    \ ++i) {\n        *os << '[' << std::setw(2) << i << \"]\";\n        for (size_t\
    \ j = xBegin; j < xEnd; ++j) *os << ' ', dbg::put(t[i][j]), *os << \"  \";\n \
    \       *os << '\\n';\n    }\n}\n\n}  // namespace dbg\n\nvoid debug_setw(int\
    \ w) {\n    dbg::w_ = w;\n}\nvoid debug_negativeValAsNull(bool f) {\n    dbg::negativeValAsNull_\
    \ = f;\n}\nvoid debug_setOstream(std::ostream& os) {\n    dbg::os = &os;\n}\n\
    void debug_hr() {\n    *dbg::os << \"----------------------------------------------------------------------\\\
    n\";\n}\nvoid debug_println() {\n    *dbg::os << std::endl;\n}\ntemplate <class\
    \ Head, class... Tail>\nvoid debug_println(const Head& head, const Tail&... tail)\
    \ {\n    dbg::put(head);\n    debug_println(tail...);\n}\n\n#define putDbgPrefix()\
    \ *dbg::os << __func__ << '(' << std::setfill('0') << std::setw(3) << __LINE__\
    \ << std::setfill(' ') << \"): \"\n#define showArrayH(a, beginIdx, endIdx) (void)(putDbgPrefix()\
    \ << #a << \":\\n\"), dbg::showArrayH__(a, beginIdx, endIdx)\n#define showArrayV(a,\
    \ beginIdx, endIdx) (void)(putDbgPrefix() << #a << \":\\n\"), dbg::showArrayV__(a,\
    \ beginIdx, endIdx)\n#define showTable(t, yBegin, yEnd, xBegin, xEnd) (void)(putDbgPrefix()\
    \ << #t << \":\\n\"), dbg::showTable__(t, yBegin, yEnd, xBegin, xEnd)\n#define\
    \ dbgMsg_(x) \"  |  \" #x \" = \", x\n#define dump1(a) (void)(putDbgPrefix()),\
    \ debug_println(#a \" = \", a)\n#define dump2(a, b) (void)(putDbgPrefix()), debug_println(#a\
    \ \" = \", a, dbgMsg_(b))\n#define dump3(a, b, c) (void)(putDbgPrefix()), debug_println(#a\
    \ \" = \", a, dbgMsg_(b), dbgMsg_(c))\n#define dump4(a, b, c, d) (void)(putDbgPrefix()),\
    \ debug_println(#a \" = \", a, dbgMsg_(b), dbgMsg_(c), dbgMsg_(d))\n#define dump5(a,\
    \ b, c, d, e) (void)(putDbgPrefix()), debug_println(#a \" = \", a, dbgMsg_(b),\
    \ dbgMsg_(c), dbgMsg_(d), dbgMsg_(e))\n#define dump6(a, b, c, d, e, f) (void)(putDbgPrefix()),\
    \ debug_println(#a \" = \", a, dbgMsg_(b), dbgMsg_(c), dbgMsg_(d), dbgMsg_(e),\
    \ dbgMsg_(f))\n#define dump7(a, b, c, d, e, f, g) (void)(putDbgPrefix()), debug_println(#a\
    \ \" = \", a, dbgMsg_(b), dbgMsg_(c), dbgMsg_(d), dbgMsg_(e), dbgMsg_(f), dbgMsg_(g))\n\
    #define GET_8TH_ARG(dummy1, dummy2, dummy3, dummy4, dummy5, dummy6, dumy7, NAME,\
    \ ...) NAME\n#define dump(...) GET_8TH_ARG(__VA_ARGS__, dump7, dump6, dump5, dump4,\
    \ dump3, dump2, dump1)(__VA_ARGS__)\n\n#else\n\n#define debug_setw(...) ((void)0)\n\
    #define debug_negativeValAsNull(...) ((void)0)\n#define debug_setOstream(...)\
    \ ((void)0)\n#define debug_hr(...) ((void)0)\n#define debug_println(...) ((void)0)\n\
    #define showArrayH(...) ((void)0)\n#define showArrayV(...) ((void)0)\n#define\
    \ showTable(...) ((void)0)\n#define dump(...) ((void)0)\n\n#endif\n#line 24 \"\
    export/template-prototype.cpp\"\n// }}}\n\nusing namespace std;\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\n    return\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\n// header {{{\n#include \"../Util/all-macro.hpp\"\
    \n#include \"../Util/rep-macro.hpp\"\n#define let const auto\n#include \"../Util/int-alias.hpp\"\
    \n#include \"../Util/int-infinity.hpp\"\n\n#include \"../Util/IO/read.hpp\"\n\n\
    #include \"../Util/IO/container-output.hpp\"\n\n#include \"../Util/IO/var-declaration-with-input.hpp\"\
    \n\n#include \"../Util/IO/println.hpp\"\n\n#include \"../Util/chminmax.hpp\"\n\
    \n#include \"../Util/makeVec.hpp\"\n// }}}\n\n// debug {{{\n#include \"../Util/Debug/debug.hpp\"\
    \n// }}}\n\nusing namespace std;\n\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \n    return 0;\n}\n"
  dependsOn:
  - Util/all-macro.hpp
  - Util/rep-macro.hpp
  - Util/int-alias.hpp
  - Util/int-infinity.hpp
  - Util/IO/read.hpp
  - Util/IO/container-output.hpp
  - Util/IO/var-declaration-with-input.hpp
  - Util/IO/println.hpp
  - Util/chminmax.hpp
  - Util/makeVec.hpp
  - Util/Debug/debug.hpp
  isVerificationFile: false
  path: export/template-prototype.cpp
  requiredBy: []
  timestamp: '2020-10-25 20:18:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: export/template-prototype.cpp
layout: document
redirect_from:
- /library/export/template-prototype.cpp
- /library/export/template-prototype.cpp.html
title: export/template-prototype.cpp
---
