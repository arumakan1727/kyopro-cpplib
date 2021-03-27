---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template (Edge, Graph, MatrixGraph)
  - icon: ':heavy_check_mark:'
    path: Util/Debug/debug.hpp
    title: Debug
  - icon: ':heavy_check_mark:'
    path: Util/int-infinity.hpp
    title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "graph-debug (\u30B0\u30E9\u30D5\u306E\u30C7\u30D0\u30C3\u30B0\
      \u51FA\u529B)"
    links: []
  bundledCode: "#line 2 \"Util/Debug/graph-debug.hpp\"\n#include <iostream>\n#include\
    \ <iomanip>\n\n#line 2 \"Graph/graph-template.hpp\"\n#include <cstdint>\n#include\
    \ <vector>\n#line 5 \"Graph/graph-template.hpp\"\n\n/**\n * @brief graph-template\
    \ (Edge, Graph, MatrixGraph)\n */\n//! \u30B0\u30E9\u30D5\u306E\u8FBA (\u91CD\u307F\
    \u4ED8\u304D)\ntemplate <class T>\nstruct Edge {\n    int from, to;\n    T weight;\n\
    \    int id;\n\n    Edge() = default;\n\n    constexpr explicit Edge(int to_,\
    \ const T& weight_)\n        : Edge(-1, to_, weight_, -1) {}\n\n    constexpr\
    \ Edge(int from_, int to_, const T& weight_, int id_ = -1)\n        : from(from_)\n\
    \        , to(to_)\n        , weight(weight_)\n        , id(id_) {}\n\n    constexpr\
    \ const Edge rev() const { return Edge(to, from, weight, id); }\n\n    template\
    \ <class Int, std::enable_if_t<std::is_integral<Int>::value, std::nullptr_t> =\
    \ nullptr>\n    constexpr operator Int() const {\n        return static_cast<Int>(to);\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& is, Edge& e) { return\
    \ is >> e.from >> e.to >> e.weight; }\n};\n\n//! \u30B0\u30E9\u30D5\u306E\u8FBA\
    \ (\u91CD\u307F\u306A\u3057)\ntemplate <>\nstruct Edge<void> {\n    int from,\
    \ to;\n    int id;\n\n    Edge() = default;\n\n    constexpr explicit Edge(int\
    \ to_)\n        : Edge(-1, to_, -1) {}\n\n    constexpr Edge(int from_, int to_,\
    \ int id_ = -1)\n        : from(from_)\n        , to(to_)\n        , id(id_) {}\n\
    \n    constexpr const Edge rev() const { return Edge(to, from, id); }\n\n    template\
    \ <class Int, std::enable_if_t<std::is_integral<Int>::value, std::nullptr_t> =\
    \ nullptr>\n    constexpr operator Int() const {\n        return static_cast<Int>(to);\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& is, Edge& e) { return\
    \ is >> e.from >> e.to; }\n};\n\ntemplate <class T>\nusing Graph = std::vector<std::vector<Edge<T>>>;\n\
    #line 5 \"Util/Debug/debug.hpp\"\n\n#line 3 \"Util/int-infinity.hpp\"\n\n/**\n\
    \ * @brief int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)\n * 2\u500D\
    \u3057\u3066\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \ & memset()\u306B\u3082\u4F7F\u3048\u308B (\u9700\u8981\u3042\u308B\uFF1F)\n\
    \ */\nconstexpr int32_t INF = 0x3f3f3f3f;\nconstexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n\
    #line 7 \"Util/Debug/debug.hpp\"\n\n/**\n * @brief Debug\n */\n#ifdef LOCAL_DEBUG\n\
    \nnamespace dbg {\n\nint w_ = 4;\nbool negativeValAsNull_ = true;\nstd::ostream*\
    \ os = &std::cerr;\n\ntemplate <class T, std::enable_if_t<!std::is_arithmetic<T>::value,\
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
    \ showTable(...) ((void)0)\n#define dump(...) ((void)0)\n\n#endif\n#line 7 \"\
    Util/Debug/graph-debug.hpp\"\n\n/**\n * @brief graph-debug (\u30B0\u30E9\u30D5\
    \u306E\u30C7\u30D0\u30C3\u30B0\u51FA\u529B)\n */\ntemplate <class T>\nstd::ostream&\
    \ operator<<(std::ostream& os, const Edge<T>& e) {\n    os << std::setw(0) <<\
    \ '(' << std::setfill('0') << std::setw(2) << e.from << \"-\" << std::setw(2)\
    \ << e.to << \", w=\" << std::setw(2) << e.weight;\n    if (e.id != -1) os <<\
    \ \", id=\" << std::setw(2) << e.id;\n    os << std::setfill(' ') << ')';\n  \
    \  return os;\n}\n\ntemplate<>\nstd::ostream& operator<<(std::ostream& os, const\
    \ Edge<void>& e) {\n    os << std::setw(0) << '(' << std::setfill('0') << std::setw(2)\
    \ << e.from << \"-\" << std::setw(2) << e.to;\n    if (e.id != -1) os << \", id=\"\
    \ << std::setw(2) << e.id;\n    os << std::setfill(' ') << ')';\n    return os;\n\
    }\n"
  code: "#pragma once\n#include <iostream>\n#include <iomanip>\n\n#include \"../../Graph/graph-template.hpp\"\
    \n#include \"./debug.hpp\"\n\n/**\n * @brief graph-debug (\u30B0\u30E9\u30D5\u306E\
    \u30C7\u30D0\u30C3\u30B0\u51FA\u529B)\n */\ntemplate <class T>\nstd::ostream&\
    \ operator<<(std::ostream& os, const Edge<T>& e) {\n    os << std::setw(0) <<\
    \ '(' << std::setfill('0') << std::setw(2) << e.from << \"-\" << std::setw(2)\
    \ << e.to << \", w=\" << std::setw(2) << e.weight;\n    if (e.id != -1) os <<\
    \ \", id=\" << std::setw(2) << e.id;\n    os << std::setfill(' ') << ')';\n  \
    \  return os;\n}\n\ntemplate<>\nstd::ostream& operator<<(std::ostream& os, const\
    \ Edge<void>& e) {\n    os << std::setw(0) << '(' << std::setfill('0') << std::setw(2)\
    \ << e.from << \"-\" << std::setw(2) << e.to;\n    if (e.id != -1) os << \", id=\"\
    \ << std::setw(2) << e.id;\n    os << std::setfill(' ') << ')';\n    return os;\n\
    }\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Util/Debug/debug.hpp
  - Util/int-infinity.hpp
  isVerificationFile: false
  path: Util/Debug/graph-debug.hpp
  requiredBy: []
  timestamp: '2020-10-25 20:18:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/Debug/graph-debug.hpp
layout: document
redirect_from:
- /library/Util/Debug/graph-debug.hpp
- /library/Util/Debug/graph-debug.hpp.html
title: "graph-debug (\u30B0\u30E9\u30D5\u306E\u30C7\u30D0\u30C3\u30B0\u51FA\u529B)"
---
