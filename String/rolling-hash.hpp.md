---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: String/rabin-karp.hpp
    title: "rabinKarp() (\u30E9\u30D3\u30F3\u30AB\u30FC\u30D7\u6CD5, RollingHash\u3092\
      \u7528\u3044\u305F\u6587\u5B57\u5217\u691C\u7D22 $O(|s|)$)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_14_B-String-Search.test.cpp
    title: test/AOJ/ALDS1_14_B-String-Search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/helloworld/rolling-hash.test.cpp
    title: test/helloworld/rolling-hash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "Rolling-Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
      \u30E5, mod\u5024 $2^{61} - 1$ \u56FA\u5B9A)"
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 2 \"String/rolling-hash.hpp\"\n\n#include <cassert>\n#include\
    \ <string>\n#include <vector>\n#include <functional>\n\n/**\n * @brief Rolling-Hash\
    \ (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5, mod\u5024 $2^{61} -\
    \ 1$ \u56FA\u5B9A)\n * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \ */\ntemplate <std::uint_fast64_t Base>\nclass RollingHash {\npublic:\n    using\
    \ u64 = std::uint_fast64_t;\n    using u128 = __uint128_t;\n    static constexpr\
    \ u64 MOD = (1uL << 61) - 1;\n    static constexpr u64 BASE = Base;\n\nprivate:\n\
    \    std::vector<u64> m_hash;\n\npublic:\n    RollingHash() = default;\n\n   \
    \ template <class InputIter>\n    RollingHash(InputIter begin, InputIter end)\n\
    \        : m_hash(std::distance(begin, end) + 1, 0) {\n        if (powArray().empty())\
    \ {\n            powArray().reserve(1e6);\n            powArray().emplace_back(1);\n\
    \        }\n        growPowArray(m_hash.size());\n\n        std::size_t i;\n \
    \       InputIter itr;\n        for (itr = begin, i = 0; itr != end; ++itr, ++i)\
    \ {\n            m_hash[i + 1] = add(mul(m_hash[i], BASE), *itr);\n        }\n\
    \    }\n\n    // \u6587\u5B57\u5217\u5168\u4F53\u306E\u30CF\u30C3\u30B7\u30E5\u5024\
    \n    u64 hash() const { return m_hash.back(); }\n\n    // \u534A\u958B\u533A\u9593\
    \ [l, r) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\n    u64 rangeHash(std::size_t l,\
    \ std::size_t r) const {\n        assert(l < r && r < m_hash.size());\n      \
    \  return add(m_hash[r], MOD - mul(m_hash[l], powArray()[r - l]));\n    }\n\n\
    \    // rangeHash(begin, begin + length) \u3068\u7B49\u4FA1\n    u64 substr(std::size_t\
    \ begin, std::size_t length) const { return rangeHash(begin, begin + length);\
    \ }\n\n    // \u3082\u3068\u306E\u6587\u5B57\u5217\u306E\u9577\u3055\n    std::size_t\
    \ size() const { return m_hash.size() - 1; }\n\n    // \u9023\u7D50\u3057\u305F\
    \u6587\u5B57\u5217 (leftStr + rightStr) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\n\
    \    static u64 concat(u64 leftHash, u64 rightHash, std::size_t rightLength) {\n\
    \        growPowArray(rightLength);\n        return add(mul(leftHash, powArray()[rightLength]),\
    \ rightHash);\n    }\n\nprivate:\n    static inline std::vector<u64>& powArray()\
    \ {\n        static std::vector<u64> p;\n        return p;\n    }\n\n    static\
    \ constexpr inline u64 add(u64 a, u64 b) noexcept {\n        if ((a += b) >= MOD)\
    \ a -= MOD;\n        return a;\n    }\n\n    static constexpr inline u64 mul(u128\
    \ a, u128 b) noexcept {\n        const auto c = a * b;\n        return add(static_cast<u64>(c\
    \ >> 61), static_cast<u64>(c & MOD));\n    }\n\n    static inline void growPowArray(std::size_t\
    \ len) {\n        ++len;\n        while (powArray().size() < len) {\n        \
    \    powArray().emplace_back(mul(powArray().back(), BASE));\n        }\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <cassert>\n#include <string>\n#include <vector>\n\
    #include <functional>\n\n/**\n * @brief Rolling-Hash (\u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5, mod\u5024 $2^{61} - 1$ \u56FA\u5B9A)\n * @see\
    \ https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n */\ntemplate <std::uint_fast64_t\
    \ Base>\nclass RollingHash {\npublic:\n    using u64 = std::uint_fast64_t;\n \
    \   using u128 = __uint128_t;\n    static constexpr u64 MOD = (1uL << 61) - 1;\n\
    \    static constexpr u64 BASE = Base;\n\nprivate:\n    std::vector<u64> m_hash;\n\
    \npublic:\n    RollingHash() = default;\n\n    template <class InputIter>\n  \
    \  RollingHash(InputIter begin, InputIter end)\n        : m_hash(std::distance(begin,\
    \ end) + 1, 0) {\n        if (powArray().empty()) {\n            powArray().reserve(1e6);\n\
    \            powArray().emplace_back(1);\n        }\n        growPowArray(m_hash.size());\n\
    \n        std::size_t i;\n        InputIter itr;\n        for (itr = begin, i\
    \ = 0; itr != end; ++itr, ++i) {\n            m_hash[i + 1] = add(mul(m_hash[i],\
    \ BASE), *itr);\n        }\n    }\n\n    // \u6587\u5B57\u5217\u5168\u4F53\u306E\
    \u30CF\u30C3\u30B7\u30E5\u5024\n    u64 hash() const { return m_hash.back(); }\n\
    \n    // \u534A\u958B\u533A\u9593 [l, r) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\n\
    \    u64 rangeHash(std::size_t l, std::size_t r) const {\n        assert(l < r\
    \ && r < m_hash.size());\n        return add(m_hash[r], MOD - mul(m_hash[l], powArray()[r\
    \ - l]));\n    }\n\n    // rangeHash(begin, begin + length) \u3068\u7B49\u4FA1\
    \n    u64 substr(std::size_t begin, std::size_t length) const { return rangeHash(begin,\
    \ begin + length); }\n\n    // \u3082\u3068\u306E\u6587\u5B57\u5217\u306E\u9577\
    \u3055\n    std::size_t size() const { return m_hash.size() - 1; }\n\n    // \u9023\
    \u7D50\u3057\u305F\u6587\u5B57\u5217 (leftStr + rightStr) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\n    static u64 concat(u64 leftHash, u64 rightHash, std::size_t rightLength)\
    \ {\n        growPowArray(rightLength);\n        return add(mul(leftHash, powArray()[rightLength]),\
    \ rightHash);\n    }\n\nprivate:\n    static inline std::vector<u64>& powArray()\
    \ {\n        static std::vector<u64> p;\n        return p;\n    }\n\n    static\
    \ constexpr inline u64 add(u64 a, u64 b) noexcept {\n        if ((a += b) >= MOD)\
    \ a -= MOD;\n        return a;\n    }\n\n    static constexpr inline u64 mul(u128\
    \ a, u128 b) noexcept {\n        const auto c = a * b;\n        return add(static_cast<u64>(c\
    \ >> 61), static_cast<u64>(c & MOD));\n    }\n\n    static inline void growPowArray(std::size_t\
    \ len) {\n        ++len;\n        while (powArray().size() < len) {\n        \
    \    powArray().emplace_back(mul(powArray().back(), BASE));\n        }\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: String/rolling-hash.hpp
  requiredBy:
  - String/rabin-karp.hpp
  timestamp: '2020-09-20 14:53:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_14_B-String-Search.test.cpp
  - test/helloworld/rolling-hash.test.cpp
documentation_of: String/rolling-hash.hpp
layout: document
redirect_from:
- /library/String/rolling-hash.hpp
- /library/String/rolling-hash.hpp.html
title: "Rolling-Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5, mod\u5024\
  \ $2^{61} - 1$ \u56FA\u5B9A)"
---