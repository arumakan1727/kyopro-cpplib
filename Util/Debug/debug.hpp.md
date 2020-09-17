---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Util/int-infinity.hpp
    title: "int-infinity (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Debug
    links: []
  bundledCode: "#line 2 \"Util/Debug/debug.hpp\"\n#include <cstdint>\n#include <iostream>\n\
    #include <iomanip>\n\n#line 3 \"Util/int-infinity.hpp\"\n\n/**\n * @brief int-infinity\
    \ (\u6574\u6570\u306E\u30C7\u30AB\u30A4\u5024)\n * 2\u500D\u3057\u3066\u3082\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044 & memset()\u306B\u3082\u4F7F\
    \u3048\u308B (\u9700\u8981\u3042\u308B\uFF1F)\n */\nconstexpr std::int32_t INF\
    \ = 0x3f3f3f3f;\nconstexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;\n#line 7\
    \ \"Util/Debug/debug.hpp\"\n\n/**\n * @brief Debug\n */\ntemplate <class A, class\
    \ B>\nstd::ostream& operator<<(std::ostream& os, const std::pair<A, B>& t) {\n\
    \    return os << '{' << std::get<0>(t) << \", \" << std::get<1>(t) << '}';\n\
    }\ntemplate <class A, class B, class C>\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::tuple<A, B, C>& t) {\n    return os << '{' << std::get<0>(t)\
    \ << \", \" << std::get<1>(t) << \", \" << std::get<2>(t) << '}';\n}\n\ntemplate\
    \ <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 4, std::nullptr_t>\
    \ = nullptr>\nconstexpr T infinity() {\n    return INF;\n}\n\ntemplate <class\
    \ T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 8, std::nullptr_t>\
    \ = nullptr>\nconstexpr T infinity() {\n    return LINF;\n}\n\n#ifdef LOCAL_DEBUG\n\
    \nclass Debug {\nprivate:\n    int w_ = 4;\n    int valueOffset_ = 0;\n    int\
    \ indexOffset_ = 0;\n    bool negativeValAsNull_ = true;\n    static constexpr\
    \ int32_t inf32_ = INF;\n    static constexpr int64_t inf64_ = LINF;\n\npublic:\n\
    \    std::ostream& os = std::cerr;\n\n    Debug() = default;\n\n    void line()\
    \ const { os << \"---------------------------------------------------\\n\"; }\n\
    \    void flush() const { os << std::flush; }\n    void w(int w) { w_ = w; }\n\
    \    void valueOffset(int v) { valueOffset_ = v; }\n    void indexOffset(int v)\
    \ { indexOffset_ = v; }\n    void negativeValAsNull(bool f) { negativeValAsNull_\
    \ = f; }\n\n    template <class T>\n    void show(const T& x) const {\n      \
    \  put(x), os << '\\n';\n    }\n\n    template <class T, class U, class... Tail>\n\
    \    void show(const T& x, const U& y, const Tail&... tail) const {\n        put(x);\n\
    \        os << \",  \";\n        show(y, tail...);\n    }\n\n    template <class\
    \ Arr>\n    void showArray(const Arr& a) const {\n        showArray(a, 0, a.size());\n\
    \    }\n\n    template <class Arr>\n    void showArray(const Arr& a, size_t begin,\
    \ size_t end) const {\n        os << '\\n';\n        for (size_t i = begin; i\
    \ < end; ++i) os << '[' << std::setw(w_) << (i + indexOffset_) << \"] \";\n  \
    \      os << '\\n';\n        for (size_t i = begin; i < end; ++i) os << ' ' <<\
    \ std::setw(w_), put(a[i]), os << \"  \";\n        os << '\\n';\n    }\n\n   \
    \ template <class Table>\n    void showTable(const Table& t) const {\n       \
    \ showTable(t, 0, t.size(), 0, t[0].size());\n    }\n\n    template <class Table>\n\
    \    void showTable(const Table& t, size_t yBegin, size_t yEnd, size_t xBegin,\
    \ size_t xEnd) const {\n        os << '\\n';\n        os << std::string(1 + 2\
    \ + 1, ' ');\n        for (size_t j = xBegin; j < xEnd; ++j) os << '[' << std::setw(w_)\
    \ << (j + indexOffset_) << \"] \";\n        os << '\\n';\n\n        for (size_t\
    \ i = yBegin; i < yEnd; ++i) {\n            os << '[' << std::setw(2) << (i +\
    \ indexOffset_) << \"]\";\n            for (size_t j = xBegin; j < xEnd; ++j)\
    \ os << ' ' << std::setw(w_), put(t[i][j]), os << \"  \";\n            os << '\\\
    n';\n        }\n    }\n\nprivate:\n    template <class T>\n    void put(const\
    \ T& x) const {\n        if constexpr (std::is_same_v<T, char>) {\n          \
    \  os << '\\'' << x << '\\'';\n        } else if constexpr (std::is_same_v<T,\
    \ bool>) {\n            os << std::setw(w_) << (x ? \"1\" : \"0\");\n        }\
    \ else if constexpr (std::is_integral_v<T>) {\n            os << std::setw(w_)\
    \ << convert(x);\n        } else if constexpr (std::is_convertible_v<T, std::string_view>)\
    \ {\n            os << std::setw(w_) << std::quoted(x);\n        } else {\n  \
    \          os << std::setw(w_) << x;\n        }\n    }\n\n    template <class\
    \ T>\n    std::string convert(const T& x) const {\n        if constexpr (std::is_signed_v<T>)\
    \ {\n            if (x <= -infinity<T>()) return \"-INF\";\n            if (negativeValAsNull_\
    \ && x < 0) return \"-\";\n        }\n        if (x >= infinity<T>()) return \"\
    INF\";\n        return std::to_string(x + valueOffset_);\n    }\n};\n\n#define\
    \ dump(...)                                                                  \
    \                  \\\n    debug.os << \"line\" << std::setw(3) << std::setfill('0')\
    \ << __LINE__ << std::setfill(' ') << \": \" \\\n             << \"[\" << #__VA_ARGS__\
    \ << \"]: \",                                                        \\\n    \
    \    debug.show(__VA_ARGS__)\n\n#else\n\n#define DEF_FUNC(funcName) \\\n    template\
    \ <class... T>  \\\n    void funcName(T&&...) {}\n\nstruct Debug {\n    DEF_FUNC(line)\n\
    \    DEF_FUNC(flush)\n    DEF_FUNC(w)\n    DEF_FUNC(valueOffset)\n    DEF_FUNC(indexOffset)\n\
    \    DEF_FUNC(negativeValAsNull)\n    DEF_FUNC(inf32)\n    DEF_FUNC(inf64)\n \
    \   DEF_FUNC(show)\n    DEF_FUNC(showArray)\n    DEF_FUNC(showTable)\n};\n\n#undef\
    \ DEF_FUNC\n#define dump(...) ((void)0)\n\n#endif\n\nDebug debug;\n"
  code: "#pragma once\n#include <cstdint>\n#include <iostream>\n#include <iomanip>\n\
    \n#include \"../int-infinity.hpp\"\n\n/**\n * @brief Debug\n */\ntemplate <class\
    \ A, class B>\nstd::ostream& operator<<(std::ostream& os, const std::pair<A, B>&\
    \ t) {\n    return os << '{' << std::get<0>(t) << \", \" << std::get<1>(t) <<\
    \ '}';\n}\ntemplate <class A, class B, class C>\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::tuple<A, B, C>& t) {\n    return os << '{' << std::get<0>(t)\
    \ << \", \" << std::get<1>(t) << \", \" << std::get<2>(t) << '}';\n}\n\ntemplate\
    \ <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 4, std::nullptr_t>\
    \ = nullptr>\nconstexpr T infinity() {\n    return INF;\n}\n\ntemplate <class\
    \ T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 8, std::nullptr_t>\
    \ = nullptr>\nconstexpr T infinity() {\n    return LINF;\n}\n\n#ifdef LOCAL_DEBUG\n\
    \nclass Debug {\nprivate:\n    int w_ = 4;\n    int valueOffset_ = 0;\n    int\
    \ indexOffset_ = 0;\n    bool negativeValAsNull_ = true;\n    static constexpr\
    \ int32_t inf32_ = INF;\n    static constexpr int64_t inf64_ = LINF;\n\npublic:\n\
    \    std::ostream& os = std::cerr;\n\n    Debug() = default;\n\n    void line()\
    \ const { os << \"---------------------------------------------------\\n\"; }\n\
    \    void flush() const { os << std::flush; }\n    void w(int w) { w_ = w; }\n\
    \    void valueOffset(int v) { valueOffset_ = v; }\n    void indexOffset(int v)\
    \ { indexOffset_ = v; }\n    void negativeValAsNull(bool f) { negativeValAsNull_\
    \ = f; }\n\n    template <class T>\n    void show(const T& x) const {\n      \
    \  put(x), os << '\\n';\n    }\n\n    template <class T, class U, class... Tail>\n\
    \    void show(const T& x, const U& y, const Tail&... tail) const {\n        put(x);\n\
    \        os << \",  \";\n        show(y, tail...);\n    }\n\n    template <class\
    \ Arr>\n    void showArray(const Arr& a) const {\n        showArray(a, 0, a.size());\n\
    \    }\n\n    template <class Arr>\n    void showArray(const Arr& a, size_t begin,\
    \ size_t end) const {\n        os << '\\n';\n        for (size_t i = begin; i\
    \ < end; ++i) os << '[' << std::setw(w_) << (i + indexOffset_) << \"] \";\n  \
    \      os << '\\n';\n        for (size_t i = begin; i < end; ++i) os << ' ' <<\
    \ std::setw(w_), put(a[i]), os << \"  \";\n        os << '\\n';\n    }\n\n   \
    \ template <class Table>\n    void showTable(const Table& t) const {\n       \
    \ showTable(t, 0, t.size(), 0, t[0].size());\n    }\n\n    template <class Table>\n\
    \    void showTable(const Table& t, size_t yBegin, size_t yEnd, size_t xBegin,\
    \ size_t xEnd) const {\n        os << '\\n';\n        os << std::string(1 + 2\
    \ + 1, ' ');\n        for (size_t j = xBegin; j < xEnd; ++j) os << '[' << std::setw(w_)\
    \ << (j + indexOffset_) << \"] \";\n        os << '\\n';\n\n        for (size_t\
    \ i = yBegin; i < yEnd; ++i) {\n            os << '[' << std::setw(2) << (i +\
    \ indexOffset_) << \"]\";\n            for (size_t j = xBegin; j < xEnd; ++j)\
    \ os << ' ' << std::setw(w_), put(t[i][j]), os << \"  \";\n            os << '\\\
    n';\n        }\n    }\n\nprivate:\n    template <class T>\n    void put(const\
    \ T& x) const {\n        if constexpr (std::is_same_v<T, char>) {\n          \
    \  os << '\\'' << x << '\\'';\n        } else if constexpr (std::is_same_v<T,\
    \ bool>) {\n            os << std::setw(w_) << (x ? \"1\" : \"0\");\n        }\
    \ else if constexpr (std::is_integral_v<T>) {\n            os << std::setw(w_)\
    \ << convert(x);\n        } else if constexpr (std::is_convertible_v<T, std::string_view>)\
    \ {\n            os << std::setw(w_) << std::quoted(x);\n        } else {\n  \
    \          os << std::setw(w_) << x;\n        }\n    }\n\n    template <class\
    \ T>\n    std::string convert(const T& x) const {\n        if constexpr (std::is_signed_v<T>)\
    \ {\n            if (x <= -infinity<T>()) return \"-INF\";\n            if (negativeValAsNull_\
    \ && x < 0) return \"-\";\n        }\n        if (x >= infinity<T>()) return \"\
    INF\";\n        return std::to_string(x + valueOffset_);\n    }\n};\n\n#define\
    \ dump(...)                                                                  \
    \                  \\\n    debug.os << \"line\" << std::setw(3) << std::setfill('0')\
    \ << __LINE__ << std::setfill(' ') << \": \" \\\n             << \"[\" << #__VA_ARGS__\
    \ << \"]: \",                                                        \\\n    \
    \    debug.show(__VA_ARGS__)\n\n#else\n\n#define DEF_FUNC(funcName) \\\n    template\
    \ <class... T>  \\\n    void funcName(T&&...) {}\n\nstruct Debug {\n    DEF_FUNC(line)\n\
    \    DEF_FUNC(flush)\n    DEF_FUNC(w)\n    DEF_FUNC(valueOffset)\n    DEF_FUNC(indexOffset)\n\
    \    DEF_FUNC(negativeValAsNull)\n    DEF_FUNC(inf32)\n    DEF_FUNC(inf64)\n \
    \   DEF_FUNC(show)\n    DEF_FUNC(showArray)\n    DEF_FUNC(showTable)\n};\n\n#undef\
    \ DEF_FUNC\n#define dump(...) ((void)0)\n\n#endif\n\nDebug debug;\n"
  dependsOn:
  - Util/int-infinity.hpp
  isVerificationFile: false
  path: Util/Debug/debug.hpp
  requiredBy: []
  timestamp: '2020-09-17 10:59:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Util/Debug/debug.hpp
layout: document
redirect_from:
- /library/Util/Debug/debug.hpp
- /library/Util/Debug/debug.hpp.html
title: Debug
---
