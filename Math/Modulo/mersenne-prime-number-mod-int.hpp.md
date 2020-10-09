---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "MersennePrimeNumberModInt (\u6CD5\u304C\u30E1\u30EB\u30BB\u30F3\
      \u30CC\u7D20\u6570\u306EModInt\u7279\u6B8A\u5316)"
    links: []
  bundledCode: "#line 2 \"Math/Modulo/mersenne-prime-number-mod-int.hpp\"\n#include\
    \ <cassert>\n#include <cstdint>\n#include <cmath>\n#include <iostream>\n#include\
    \ <type_traits>\n\n/**\n * @brief MersennePrimeNumberModInt (\u6CD5\u304C\u30E1\
    \u30EB\u30BB\u30F3\u30CC\u7D20\u6570\u306EModInt\u7279\u6B8A\u5316)\n */\nnamespace\
    \ internal {\n\ntemplate <class ModHolder>\nclass ModInt;\n\nconstexpr int exponentOfMersennePrimeNumber(uint_fast64_t\
    \ x) {\n    if (x == (1ull << 61) - 1) return 61;\n    if (x == (1ull << 31) -\
    \ 1) return 31;\n    if (x == (1ull << 19) - 1) return 19;\n    if (x == (1ull\
    \ << 17) - 1) return 17;\n    if (x == (1ull << 13) - 1) return 13;\n    if (x\
    \ == (1ull << 7) - 1) return 7;\n    if (x == (1ull << 5) - 1) return 5;\n   \
    \ if (x == (1ull << 3) - 1) return 3;\n    if (x == (1ull << 2) - 1) return 2;\n\
    \    return -1;\n}\n\ntemplate <uint_fast64_t Mod>\nstruct MersennePrimeNumberModHolder\
    \ {\n    static constexpr uint_fast64_t mod = Mod;\n    static constexpr uint32_t\
    \ exp = exponentOfMersennePrimeNumber(Mod);\n    static_assert(exponentOfMersennePrimeNumber(Mod)\
    \ != -1, \"Mod value is not a mersenne prime number.\");\n};\n\ntemplate <uint_fast64_t\
    \ Mod>\nclass ModInt<MersennePrimeNumberModHolder<Mod>> {\nprivate:\n    using\
    \ u64 = uint_fast64_t;\n    using i64 = int_fast64_t;\n    using largeUint = std::conditional\
    \ < Mod<(1ull << 31), u64, __uint128_t>;\n    using ModHolder = MersennePrimeNumberModHolder<Mod>;\n\
    \    u64 value;\n\npublic:\n    constexpr inline ModInt() noexcept\n        :\
    \ value(0) {}\n\n    constexpr inline ModInt(i64 v) noexcept\n        : value(ModInt::normalized(v))\
    \ {}\n\n    static constexpr inline const ModInt raw(u64 v) noexcept {\n     \
    \   ModInt ret;\n        ret.value = v;\n        return ret;\n    }\n\n    static\
    \ constexpr ModInt nullopt() noexcept { return ModInt::raw(Mod); }\n\n    constexpr\
    \ bool isNull() const noexcept { return *this == ModInt::nullopt(); }\n\n    static\
    \ constexpr inline u64 mod() noexcept { return ModHolder::mod; }\n\n    template\
    \ <class T>\n    constexpr explicit operator T() const noexcept {\n        return\
    \ static_cast<T>(value);\n    }\n\n    constexpr u64 val() const noexcept { return\
    \ value; }\n\n    constexpr ModInt& operator+=(const ModInt& rhs) noexcept {\n\
    \        if ((value += rhs.value) >= mod()) value -= mod();\n        return *this;\n\
    \    }\n    constexpr ModInt& operator-=(const ModInt& rhs) noexcept {\n     \
    \   if (value < rhs.value) value += mod();\n        value -= rhs.value;\n    \
    \    return *this;\n    }\n    constexpr ModInt& operator*=(const ModInt& rhs)\
    \ noexcept {\n        value = mul(value, rhs.value);\n        return *this;\n\
    \    }\n    constexpr ModInt& operator/=(const ModInt& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n    constexpr const ModInt inv() const noexcept { return\
    \ ModInt(ModInt::inverse(value, mod())); }\n    constexpr const ModInt operator+()\
    \ const noexcept { return *this; }\n    constexpr const ModInt operator-() const\
    \ noexcept { return ModInt(-static_cast<i64>(value)); }\n\n    constexpr const\
    \ ModInt pow(i64 expv) const noexcept {\n        u64 ret = 1, square = value;\n\
    \        for (u64 p = std::abs(expv); p; p >>= 1) {\n            if (p & 1) ret\
    \ = mul(ret, square);\n            square = mul(square, square);\n        }\n\
    \        return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);\n\
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
    private:\n    static constexpr inline u64 applyMod_u64(u64 x) noexcept {\n   \
    \     x = (x >> ModHolder::exp) + (x & mod());\n        if (x >= mod()) x -= mod();\n\
    \        return x;\n    }\n\n    static constexpr inline u64 applyMod_largeUint(largeUint\
    \ x) noexcept {\n        u64 y = static_cast<u64>(x >> ModHolder::exp) + static_cast<u64>(x\
    \ & mod());\n        if (y >= mod()) y -= mod();\n        return y;\n    }\n\n\
    \    static constexpr inline u64 mul(u64 a, u64 b) noexcept { return applyMod_largeUint(static_cast<largeUint>(a)\
    \ * static_cast<largeUint>(b)); }\n\n    static constexpr u64 normalized(i64 n)\
    \ noexcept {\n        if (n >= 0) return applyMod_u64(n);\n        if (n < -mod())\
    \ n %= mod();\n        return n += mod();\n    }\n\n    static constexpr i64 inverse(i64\
    \ a, i64 m) noexcept {\n        i64 u = 0, v = 1;\n        while (a != 0) {\n\
    \            const auto t = m / a;\n            static_cast<void>(m -= t * a),\
    \ std::swap(m, a);\n            static_cast<void>(u -= t * v), std::swap(u, v);\n\
    \        }\n        assert(m == 1);\n        return u;\n    }\n};\n\n}  // namespace\
    \ internal\n\ntemplate <uint_fast64_t Mod>\nusing MersennePrimeNumberModInt =\
    \ internal::ModInt<internal::MersennePrimeNumberModHolder<Mod>>;\n\nusing ModInt_2pow61_1\
    \ = MersennePrimeNumberModInt<(1ull << 61) - 1>;\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <cmath>\n\
    #include <iostream>\n#include <type_traits>\n\n/**\n * @brief MersennePrimeNumberModInt\
    \ (\u6CD5\u304C\u30E1\u30EB\u30BB\u30F3\u30CC\u7D20\u6570\u306EModInt\u7279\u6B8A\
    \u5316)\n */\nnamespace internal {\n\ntemplate <class ModHolder>\nclass ModInt;\n\
    \nconstexpr int exponentOfMersennePrimeNumber(uint_fast64_t x) {\n    if (x ==\
    \ (1ull << 61) - 1) return 61;\n    if (x == (1ull << 31) - 1) return 31;\n  \
    \  if (x == (1ull << 19) - 1) return 19;\n    if (x == (1ull << 17) - 1) return\
    \ 17;\n    if (x == (1ull << 13) - 1) return 13;\n    if (x == (1ull << 7) - 1)\
    \ return 7;\n    if (x == (1ull << 5) - 1) return 5;\n    if (x == (1ull << 3)\
    \ - 1) return 3;\n    if (x == (1ull << 2) - 1) return 2;\n    return -1;\n}\n\
    \ntemplate <uint_fast64_t Mod>\nstruct MersennePrimeNumberModHolder {\n    static\
    \ constexpr uint_fast64_t mod = Mod;\n    static constexpr uint32_t exp = exponentOfMersennePrimeNumber(Mod);\n\
    \    static_assert(exponentOfMersennePrimeNumber(Mod) != -1, \"Mod value is not\
    \ a mersenne prime number.\");\n};\n\ntemplate <uint_fast64_t Mod>\nclass ModInt<MersennePrimeNumberModHolder<Mod>>\
    \ {\nprivate:\n    using u64 = uint_fast64_t;\n    using i64 = int_fast64_t;\n\
    \    using largeUint = std::conditional < Mod<(1ull << 31), u64, __uint128_t>;\n\
    \    using ModHolder = MersennePrimeNumberModHolder<Mod>;\n    u64 value;\n\n\
    public:\n    constexpr inline ModInt() noexcept\n        : value(0) {}\n\n   \
    \ constexpr inline ModInt(i64 v) noexcept\n        : value(ModInt::normalized(v))\
    \ {}\n\n    static constexpr inline const ModInt raw(u64 v) noexcept {\n     \
    \   ModInt ret;\n        ret.value = v;\n        return ret;\n    }\n\n    static\
    \ constexpr ModInt nullopt() noexcept { return ModInt::raw(Mod); }\n\n    constexpr\
    \ bool isNull() const noexcept { return *this == ModInt::nullopt(); }\n\n    static\
    \ constexpr inline u64 mod() noexcept { return ModHolder::mod; }\n\n    template\
    \ <class T>\n    constexpr explicit operator T() const noexcept {\n        return\
    \ static_cast<T>(value);\n    }\n\n    constexpr u64 val() const noexcept { return\
    \ value; }\n\n    constexpr ModInt& operator+=(const ModInt& rhs) noexcept {\n\
    \        if ((value += rhs.value) >= mod()) value -= mod();\n        return *this;\n\
    \    }\n    constexpr ModInt& operator-=(const ModInt& rhs) noexcept {\n     \
    \   if (value < rhs.value) value += mod();\n        value -= rhs.value;\n    \
    \    return *this;\n    }\n    constexpr ModInt& operator*=(const ModInt& rhs)\
    \ noexcept {\n        value = mul(value, rhs.value);\n        return *this;\n\
    \    }\n    constexpr ModInt& operator/=(const ModInt& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n    constexpr const ModInt inv() const noexcept { return\
    \ ModInt(ModInt::inverse(value, mod())); }\n    constexpr const ModInt operator+()\
    \ const noexcept { return *this; }\n    constexpr const ModInt operator-() const\
    \ noexcept { return ModInt(-static_cast<i64>(value)); }\n\n    constexpr const\
    \ ModInt pow(i64 expv) const noexcept {\n        u64 ret = 1, square = value;\n\
    \        for (u64 p = std::abs(expv); p; p >>= 1) {\n            if (p & 1) ret\
    \ = mul(ret, square);\n            square = mul(square, square);\n        }\n\
    \        return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);\n\
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
    private:\n    static constexpr inline u64 applyMod_u64(u64 x) noexcept {\n   \
    \     x = (x >> ModHolder::exp) + (x & mod());\n        if (x >= mod()) x -= mod();\n\
    \        return x;\n    }\n\n    static constexpr inline u64 applyMod_largeUint(largeUint\
    \ x) noexcept {\n        u64 y = static_cast<u64>(x >> ModHolder::exp) + static_cast<u64>(x\
    \ & mod());\n        if (y >= mod()) y -= mod();\n        return y;\n    }\n\n\
    \    static constexpr inline u64 mul(u64 a, u64 b) noexcept { return applyMod_largeUint(static_cast<largeUint>(a)\
    \ * static_cast<largeUint>(b)); }\n\n    static constexpr u64 normalized(i64 n)\
    \ noexcept {\n        if (n >= 0) return applyMod_u64(n);\n        if (n < -mod())\
    \ n %= mod();\n        return n += mod();\n    }\n\n    static constexpr i64 inverse(i64\
    \ a, i64 m) noexcept {\n        i64 u = 0, v = 1;\n        while (a != 0) {\n\
    \            const auto t = m / a;\n            static_cast<void>(m -= t * a),\
    \ std::swap(m, a);\n            static_cast<void>(u -= t * v), std::swap(u, v);\n\
    \        }\n        assert(m == 1);\n        return u;\n    }\n};\n\n}  // namespace\
    \ internal\n\ntemplate <uint_fast64_t Mod>\nusing MersennePrimeNumberModInt =\
    \ internal::ModInt<internal::MersennePrimeNumberModHolder<Mod>>;\n\nusing ModInt_2pow61_1\
    \ = MersennePrimeNumberModInt<(1ull << 61) - 1>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Modulo/mersenne-prime-number-mod-int.hpp
  requiredBy: []
  timestamp: '2020-10-10 05:51:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Modulo/mersenne-prime-number-mod-int.hpp
layout: document
redirect_from:
- /library/Math/Modulo/mersenne-prime-number-mod-int.hpp
- /library/Math/Modulo/mersenne-prime-number-mod-int.hpp.html
title: "MersennePrimeNumberModInt (\u6CD5\u304C\u30E1\u30EB\u30BB\u30F3\u30CC\u7D20\
  \u6570\u306EModInt\u7279\u6B8A\u5316)"
---
