---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/rolling-hash.hpp
    title: "Rolling-Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5,\
      \ mod\u5024 $2^61 - 1$ \u56FA\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: String/rabin-karp.hpp
    title: "rabinKarp() (\u30E9\u30D3\u30F3\u30AB\u30FC\u30D7\u6CD5, RollingHash\u3092\
      \u7528\u3044\u305F\u6587\u5B57\u5217\u691C\u7D22 $O(|s|)$)"
  - icon: ':heavy_check_mark:'
    path: Util/IO/println.hpp
    title: "println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\
      \u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)"
  - icon: ':heavy_check_mark:'
    path: Util/all-macro.hpp
    title: "all()\u30DE\u30AF\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/AOJ/ALDS1_14_B-String-Search.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <iostream>\n#include <string>\n#include <vector>\n\n#line 2 \"String/rolling-hash.hpp\"\
    \n\n#include <cassert>\n#line 6 \"String/rolling-hash.hpp\"\n#include <functional>\n\
    \n/**\n * @brief Rolling-Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
    \u30E5, mod\u5024 $2^61 - 1$ \u56FA\u5B9A)\n * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \ */\nclass RollingHash {\npublic:\n    using u64 = std::uint_fast64_t;\n    using\
    \ u128 = __uint128_t;\n    static constexpr u64 MOD = (1uL << 61) - 1;\n    static\
    \ constexpr u64 BASE = 17273747;\n\nprivate:\n    static std::vector<u64> s_pow;\n\
    \    std::vector<u64> m_hash;\n\npublic:\n    RollingHash() = default;\n\n   \
    \ template <class InputIter>\n    RollingHash(InputIter begin, InputIter end)\n\
    \        : m_hash(std::distance(begin, end) + 1, 0) {\n        if (s_pow.empty())\
    \ {\n            s_pow.reserve(1e6);\n            s_pow.emplace_back(1);\n   \
    \     }\n        growPowArray(m_hash.size());\n\n        std::size_t i;\n    \
    \    InputIter itr;\n        for (itr = begin, i = 0; itr != end; ++itr, ++i)\
    \ {\n            m_hash[i + 1] = add(mul(m_hash[i], BASE), xorShift(static_cast<u64>(*itr\
    \ + 1)));\n        }\n    }\n\n    // \u6587\u5B57\u5217\u5168\u4F53\u306E\u30CF\
    \u30C3\u30B7\u30E5\u5024\n    u64 hash() const { return m_hash.back(); }\n\n \
    \   // \u534A\u958B\u533A\u9593 [l, r) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\n\
    \    u64 rangeHash(std::size_t l, std::size_t r) const {\n        assert(l < r\
    \ && r < m_hash.size());\n        return add(m_hash[r], MOD - mul(m_hash[l], s_pow[r\
    \ - l]));\n    }\n\n    // rangeHash(begin, begin + length) \u3068\u7B49\u4FA1\
    \n    u64 substr(std::size_t begin, std::size_t length) const { return rangeHash(begin,\
    \ begin + length); }\n\n    // \u3082\u3068\u306E\u6587\u5B57\u5217\u306E\u9577\
    \u3055\n    std::size_t size() const { return m_hash.size() - 1; }\n\n    // \u9023\
    \u7D50\u3057\u305F\u6587\u5B57\u5217 (leftStr + rightStr) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\n    static u64 concat(u64 leftHash, u64 rightHash, std::size_t leftLength)\
    \ {\n        growPowArray(leftLength);\n        return add(mul(rightHash, s_pow[leftLength]),\
    \ leftHash);\n    }\n\nprivate:\n    static constexpr inline u64 add(u64 a, u64\
    \ b) noexcept {\n        if ((a += b) >= MOD) a -= MOD;\n        return a;\n \
    \   }\n\n    static constexpr inline u64 mul(u128 a, u128 b) noexcept {\n    \
    \    const auto c = a * b;\n        return add(static_cast<u64>(c >> 61), static_cast<u64>(c\
    \ & MOD));\n    }\n\n    static constexpr inline u64 xorShift(u64 x) noexcept\
    \ {\n        x ^= x << 13;\n        x ^= x >> 17;\n        x ^= x << 5;\n    \
    \    return x;\n    }\n\n    static void growPowArray(std::size_t len) {\n   \
    \     ++len;\n        while (s_pow.size() < len) {\n            s_pow.emplace_back(mul(s_pow.back(),\
    \ BASE));\n        }\n    }\n};\n\nstd::vector<RollingHash::u64> RollingHash::s_pow;\n\
    #line 2 \"String/rabin-karp.hpp\"\n\n#line 5 \"String/rabin-karp.hpp\"\n\n/**\n\
    \ * @brief rabinKarp() (\u30E9\u30D3\u30F3\u30AB\u30FC\u30D7\u6CD5, RollingHash\u3092\
    \u7528\u3044\u305F\u6587\u5B57\u5217\u691C\u7D22 $O(|s|)$)\n * s \u306E\u4E2D\u3067\
    \ pattern \u304C\u51FA\u73FE\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\
    \u5168\u3066\u6C42\u3081\u3066 vector \u3068\u3057\u3066\u8FD4\u3059(\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\u306F\u6607\u9806)\u3002\n */\nstd::vector<std::size_t>\
    \ rabinKarp(const RollingHash& s, const RollingHash& pattern) {\n    const auto\
    \ sLen = s.size();\n    const auto patLen = pattern.size();\n\n    std::vector<std::size_t>\
    \ foundIndexes;\n    foundIndexes.reserve(sLen);\n\n    for (std::size_t i = 0;\
    \ i + patLen <= sLen; ++i) {\n        if (s.substr(i, patLen) == pattern.hash())\
    \ foundIndexes.emplace_back(i);\n    }\n\n    foundIndexes.shrink_to_fit();\n\
    \    return foundIndexes;\n}\n#line 3 \"Util/IO/println.hpp\"\n#include <utility>\n\
    \n/**\n * @brief println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\
    \u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)\n */\ninline\
    \ void println() {\n    std::cout << '\\n';\n}\ntemplate <class Head, class...\
    \ Tail>\ninline void println(Head&& head, Tail&&... tail) {\n    std::cout <<\
    \ head << &\" \"[!sizeof...(tail)];\n    println(std::forward<Tail>(tail)...);\n\
    }\n#line 2 \"Util/all-macro.hpp\"\n\n/**\n * @brief all()\u30DE\u30AF\u30ED\n\
    \ */\n#define all(x) std::begin(x), std::end(x)\n#define rall(x) std::rbegin(x),\
    \ std::rend(x)\n#line 11 \"test/AOJ/ALDS1_14_B-String-Search.test.cpp\"\n\nint\
    \ main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \n    std::string T, P;\n    std::cin >> T >> P;\n\n    const RollingHash rolHashT(all(T));\n\
    \    const RollingHash rolHashP(all(P));\n\n    for (const auto foundIndex : rabinKarp(rolHashT,\
    \ rolHashP)) {\n        println(foundIndex);\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../String/rolling-hash.hpp\"\
    \n#include \"../../String/rabin-karp.hpp\"\n#include \"../../Util/IO/println.hpp\"\
    \n#include \"../../Util/all-macro.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios_base::sync_with_stdio(false);\n\n    std::string T, P;\n    std::cin\
    \ >> T >> P;\n\n    const RollingHash rolHashT(all(T));\n    const RollingHash\
    \ rolHashP(all(P));\n\n    for (const auto foundIndex : rabinKarp(rolHashT, rolHashP))\
    \ {\n        println(foundIndex);\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - String/rolling-hash.hpp
  - String/rabin-karp.hpp
  - Util/IO/println.hpp
  - Util/all-macro.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_14_B-String-Search.test.cpp
  requiredBy: []
  timestamp: '2020-09-19 13:35:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_14_B-String-Search.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_14_B-String-Search.test.cpp
- /verify/test/AOJ/ALDS1_14_B-String-Search.test.cpp.html
title: test/AOJ/ALDS1_14_B-String-Search.test.cpp
---
