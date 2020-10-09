---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/Combinatorics/factorials.hpp
    title: "factorials (\u968E\u4E57, \u968E\u4E57\u306E\u9006\u5143, nCr, nPr)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0264-Finite-Field-Calculator.test.cpp
    title: test/AOJ/0264-Finite-Field-Calculator.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1501-Grid.test.cpp
    title: test/AOJ/1501-Grid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_5_A.test.cpp
    title: test/AOJ/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_B-Power.test.cpp
    title: test/AOJ/NTL_1_B-Power.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642mod\u578B\u3068\u5B9F\
      \u884C\u6642mod\u578B)"
    links: []
  bundledCode: "#line 2 \"Math/Modulo/mod-int.hpp\"\n#include <cstdint>\n#include\
    \ <cassert>\n#include <iostream>\n#include <limits>\n\n/**\n * @brief Mod-Int\
    \ (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642mod\u578B\u3068\u5B9F\u884C\u6642mod\u578B\
    )\n */\nnamespace internal {\n\ntemplate <class ModHolder>\nclass ModInt {\nprivate:\n\
    \    int64_t value;\n\npublic:\n    constexpr ModInt() noexcept\n        : value(0)\
    \ {}\n\n    constexpr ModInt(int64_t v) noexcept\n        : value(ModInt::normalized(v))\
    \ {}\n\n    static constexpr const ModInt raw(int64_t v) noexcept {\n        ModInt\
    \ ret;\n        ret.value = v;\n        return ret;\n    }\n\n    static constexpr\
    \ ModInt nullopt() noexcept { return ModInt::raw(std::numeric_limits<int64_t>::min());\
    \ }\n\n    constexpr bool isNull() const noexcept { return *this == ModInt::nullopt();\
    \ }\n\n    static constexpr int64_t mod() { return ModHolder::mod; }\n\n    static\
    \ int64_t setMod(int64_t m) noexcept {\n        assert(m >= 1);\n        return\
    \ ModHolder::mod = m;\n    }\n\n    template <class T>\n    constexpr explicit\
    \ operator T() const noexcept {\n        return static_cast<T>(value);\n    }\n\
    \    constexpr ModInt& operator+=(const ModInt& rhs) noexcept {\n        if ((value\
    \ += rhs.value) >= mod()) value -= mod();\n        return *this;\n    }\n    constexpr\
    \ ModInt& operator-=(const ModInt& rhs) noexcept {\n        if ((value -= rhs.value)\
    \ < 0) value += mod();\n        return *this;\n    }\n    constexpr ModInt& operator*=(const\
    \ ModInt& rhs) noexcept {\n        (value *= rhs.value) %= mod();\n        return\
    \ *this;\n    }\n    constexpr ModInt& operator/=(const ModInt& rhs) noexcept\
    \ { return *this *= rhs.inv(); }\n    constexpr const ModInt inv() const noexcept\
    \ { return ModInt(ModInt::inverse(value, mod())); }\n    constexpr const ModInt\
    \ operator+() const noexcept { return *this; }\n    constexpr const ModInt operator-()\
    \ const noexcept { return ModInt(-value); }\n\n    constexpr const ModInt pow(int64_t\
    \ expv) const noexcept {\n        int64_t ret = 1, square = value;\n        for\
    \ (uint64_t p = std::abs(expv); p; p >>= 1) {\n            if (p & 1) (ret *=\
    \ square) %= mod();\n            (square *= square) %= mod();\n        }\n   \
    \     return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);\n\
    \    }\n\n    friend constexpr bool operator==(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return lhs.value == rhs.value; }\n    friend constexpr bool\
    \ operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.value\
    \ != rhs.value; }\n    friend constexpr const ModInt operator+(const ModInt& lhs,\
    \ const ModInt& rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend constexpr\
    \ const ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept { return\
    \ ModInt(lhs) -= rhs; }\n    friend constexpr const ModInt operator*(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend\
    \ constexpr const ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const ModInt& x) {\n#ifdef LOCAL_DEBUG\n        if (x.isNull()) return os\
    \ << \"{nullopt}\";\n#endif\n        return os << x.value;\n    }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, ModInt& x) {\n        is >> x.value;\n\
    \        x.value = ModInt::normalized(x.value);\n        return is;\n    }\n\n\
    private:\n    static constexpr int64_t normalized(int64_t n) {\n        n = (-mod()\
    \ <= n && n < mod() ? n : n % mod());\n        if (n < 0) n += mod();\n      \
    \  return n;\n    }\n\n    static constexpr int64_t inverse(int64_t a, int64_t\
    \ m) {\n        int64_t u = 0, v = 1;\n        while (a != 0) {\n            const\
    \ auto t = m / a;\n            static_cast<void>(m -= t * a), std::swap(m, a);\n\
    \            static_cast<void>(u -= t * v), std::swap(u, v);\n        }\n    \
    \    assert(m == 1);\n        return u;\n    }\n};\n\ntemplate <int64_t Mod>\n\
    struct StaticModHolder {\n    static constexpr int64_t mod = Mod;\n};\n\ntemplate\
    \ <int ID>\nstruct DynamicModHolder {\n    static int64_t mod;\n};\ntemplate <int\
    \ ID>\nint64_t DynamicModHolder<ID>::mod;\n\n}  // namespace internal\n\ntemplate\
    \ <int64_t Mod>\nusing StaticModInt = internal::ModInt<internal::StaticModHolder<Mod>>;\n\
    \nusing ModInt1000000007 = StaticModInt<int(1e9) + 7>;\nusing ModInt998244353\
    \ = StaticModInt<998244353>;\n\ntemplate <int ID>\nusing DynamicModInt = internal::ModInt<internal::DynamicModHolder<ID>>;\n"
  code: "#pragma once\n#include <cstdint>\n#include <cassert>\n#include <iostream>\n\
    #include <limits>\n\n/**\n * @brief Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\
    mod\u578B\u3068\u5B9F\u884C\u6642mod\u578B)\n */\nnamespace internal {\n\ntemplate\
    \ <class ModHolder>\nclass ModInt {\nprivate:\n    int64_t value;\n\npublic:\n\
    \    constexpr ModInt() noexcept\n        : value(0) {}\n\n    constexpr ModInt(int64_t\
    \ v) noexcept\n        : value(ModInt::normalized(v)) {}\n\n    static constexpr\
    \ const ModInt raw(int64_t v) noexcept {\n        ModInt ret;\n        ret.value\
    \ = v;\n        return ret;\n    }\n\n    static constexpr ModInt nullopt() noexcept\
    \ { return ModInt::raw(std::numeric_limits<int64_t>::min()); }\n\n    constexpr\
    \ bool isNull() const noexcept { return *this == ModInt::nullopt(); }\n\n    static\
    \ constexpr int64_t mod() { return ModHolder::mod; }\n\n    static int64_t setMod(int64_t\
    \ m) noexcept {\n        assert(m >= 1);\n        return ModHolder::mod = m;\n\
    \    }\n\n    template <class T>\n    constexpr explicit operator T() const noexcept\
    \ {\n        return static_cast<T>(value);\n    }\n    constexpr ModInt& operator+=(const\
    \ ModInt& rhs) noexcept {\n        if ((value += rhs.value) >= mod()) value -=\
    \ mod();\n        return *this;\n    }\n    constexpr ModInt& operator-=(const\
    \ ModInt& rhs) noexcept {\n        if ((value -= rhs.value) < 0) value += mod();\n\
    \        return *this;\n    }\n    constexpr ModInt& operator*=(const ModInt&\
    \ rhs) noexcept {\n        (value *= rhs.value) %= mod();\n        return *this;\n\
    \    }\n    constexpr ModInt& operator/=(const ModInt& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n    constexpr const ModInt inv() const noexcept { return\
    \ ModInt(ModInt::inverse(value, mod())); }\n    constexpr const ModInt operator+()\
    \ const noexcept { return *this; }\n    constexpr const ModInt operator-() const\
    \ noexcept { return ModInt(-value); }\n\n    constexpr const ModInt pow(int64_t\
    \ expv) const noexcept {\n        int64_t ret = 1, square = value;\n        for\
    \ (uint64_t p = std::abs(expv); p; p >>= 1) {\n            if (p & 1) (ret *=\
    \ square) %= mod();\n            (square *= square) %= mod();\n        }\n   \
    \     return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);\n\
    \    }\n\n    friend constexpr bool operator==(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return lhs.value == rhs.value; }\n    friend constexpr bool\
    \ operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.value\
    \ != rhs.value; }\n    friend constexpr const ModInt operator+(const ModInt& lhs,\
    \ const ModInt& rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend constexpr\
    \ const ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept { return\
    \ ModInt(lhs) -= rhs; }\n    friend constexpr const ModInt operator*(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend\
    \ constexpr const ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const ModInt& x) {\n#ifdef LOCAL_DEBUG\n        if (x.isNull()) return os\
    \ << \"{nullopt}\";\n#endif\n        return os << x.value;\n    }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, ModInt& x) {\n        is >> x.value;\n\
    \        x.value = ModInt::normalized(x.value);\n        return is;\n    }\n\n\
    private:\n    static constexpr int64_t normalized(int64_t n) {\n        n = (-mod()\
    \ <= n && n < mod() ? n : n % mod());\n        if (n < 0) n += mod();\n      \
    \  return n;\n    }\n\n    static constexpr int64_t inverse(int64_t a, int64_t\
    \ m) {\n        int64_t u = 0, v = 1;\n        while (a != 0) {\n            const\
    \ auto t = m / a;\n            static_cast<void>(m -= t * a), std::swap(m, a);\n\
    \            static_cast<void>(u -= t * v), std::swap(u, v);\n        }\n    \
    \    assert(m == 1);\n        return u;\n    }\n};\n\ntemplate <int64_t Mod>\n\
    struct StaticModHolder {\n    static constexpr int64_t mod = Mod;\n};\n\ntemplate\
    \ <int ID>\nstruct DynamicModHolder {\n    static int64_t mod;\n};\ntemplate <int\
    \ ID>\nint64_t DynamicModHolder<ID>::mod;\n\n}  // namespace internal\n\ntemplate\
    \ <int64_t Mod>\nusing StaticModInt = internal::ModInt<internal::StaticModHolder<Mod>>;\n\
    \nusing ModInt1000000007 = StaticModInt<int(1e9) + 7>;\nusing ModInt998244353\
    \ = StaticModInt<998244353>;\n\ntemplate <int ID>\nusing DynamicModInt = internal::ModInt<internal::DynamicModHolder<ID>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Modulo/mod-int.hpp
  requiredBy:
  - Math/Combinatorics/factorials.hpp
  timestamp: '2020-10-10 05:22:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL_5_A.test.cpp
  - test/AOJ/1501-Grid.test.cpp
  - test/AOJ/NTL_1_B-Power.test.cpp
  - test/AOJ/0264-Finite-Field-Calculator.test.cpp
documentation_of: Math/Modulo/mod-int.hpp
layout: document
redirect_from:
- /library/Math/Modulo/mod-int.hpp
- /library/Math/Modulo/mod-int.hpp.html
title: "Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642mod\u578B\u3068\u5B9F\u884C\u6642\
  mod\u578B)"
---
