---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Modulo/mod-int.hpp
    title: "Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642mod\u578B\u3068\u5B9F\u884C\
      \u6642mod\u578B)"
  - icon: ':heavy_check_mark:'
    path: Algorithm/doubling-pow.hpp
    title: "doubling-pow() (\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: Util/int-alias.hpp
    title: "int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)"
  - icon: ':heavy_check_mark:'
    path: Util/IO/println.hpp
    title: "println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\
      \u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ/DPL_5_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja\"\
    \n\n#include <iostream>\n#include <type_traits>\n\n#line 2 \"Math/Modulo/mod-int.hpp\"\
    \n#include <cstdint>\n#include <cassert>\n#line 5 \"Math/Modulo/mod-int.hpp\"\n\
    #include <limits>\n\n/**\n * @brief Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\
    mod\u578B\u3068\u5B9F\u884C\u6642mod\u578B)\n */\nnamespace impl {\n\ntemplate\
    \ <class ModHolder>\nclass ModInt {\nprivate:\n    int64_t value;\n\npublic:\n\
    \    constexpr ModInt()\n        : value(0) {}\n    constexpr ModInt(int64_t v)\n\
    \        : value(ModInt::normalized(v)) {}\n\n    constexpr ModInt(const ModInt&\
    \ v) = default;\n\n    static constexpr ModInt raw(int64_t v) {\n        ModInt\
    \ ret;\n        ret.value = v;\n        return ret;\n    }\n\n    static constexpr\
    \ ModInt nullopt() { return ModInt::raw(std::numeric_limits<int64_t>::min());\
    \ }\n\n    constexpr bool isNull() const { return *this == ModInt::nullopt();\
    \ }\n\n    static constexpr int64_t mod() { return ModHolder::mod; }\n\n    static\
    \ int64_t setMod(int64_t m) {\n        assert(m >= 1);\n        return ModHolder::mod\
    \ = m;\n    }\n\n    template <class T>\n    constexpr explicit operator T() const\
    \ {\n        return static_cast<T>(value);\n    }\n    constexpr ModInt& operator+=(const\
    \ ModInt& rhs) {\n        if ((value += rhs.value) >= mod()) value -= mod();\n\
    \        return *this;\n    }\n    constexpr ModInt& operator-=(const ModInt&\
    \ rhs) {\n        if ((value -= rhs.value) < 0) value += mod();\n        return\
    \ *this;\n    }\n    constexpr ModInt& operator*=(const ModInt& rhs) {\n     \
    \   (value *= rhs.value) %= mod();\n        return *this;\n    }\n    constexpr\
    \ ModInt& operator/=(const ModInt& rhs) { return *this *= rhs.inv(); }\n    constexpr\
    \ const ModInt inv() const { return ModInt(ModInt::inverse(value, mod())); }\n\
    \    constexpr const ModInt operator+() const { return *this; }\n    constexpr\
    \ const ModInt operator-() const { return ModInt(-value); }\n\n    constexpr const\
    \ ModInt pow(int64_t expv) const {\n        int64_t ret = 1, square = value;\n\
    \        for (uint64_t p = std::abs(expv); p; p >>= 1) {\n            if (p &\
    \ 1) (ret *= square) %= mod();\n            (square *= square) %= mod();\n   \
    \     }\n        return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);\n\
    \    }\n\n    friend constexpr bool operator==(const ModInt& lhs, const ModInt&\
    \ rhs) { return lhs.value == rhs.value; }\n    friend constexpr bool operator!=(const\
    \ ModInt& lhs, const ModInt& rhs) { return lhs.value != rhs.value; }\n    friend\
    \ constexpr const ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return\
    \ ModInt(lhs) += rhs; }\n    friend constexpr const ModInt operator-(const ModInt&\
    \ lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }\n    friend constexpr\
    \ const ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs)\
    \ *= rhs; }\n    friend constexpr const ModInt operator/(const ModInt& lhs, const\
    \ ModInt& rhs) { return ModInt(lhs) /= rhs; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const ModInt& x) {\n#ifdef LOCAL_DEBUG\n        if (x.isNull()) return os\
    \ << \"{nullopt}\";\n#endif\n        return os << x.value;\n    }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, ModInt& x) {\n        is >> x.value;\n\
    \        x.value = ModInt::normalized(x.value);\n        return is;\n    }\n\n\
    private:\n    static constexpr int64_t normalized(int64_t n) {\n        n = (-mod()\
    \ <= n && n < mod() ? n : n % mod());\n        if (n < 0) n += mod();\n      \
    \  return n;\n    }\n\n    static constexpr int64_t inverse(int64_t a, int64_t\
    \ m) {\n        int64_t u = 0, v = 1;\n        while (a != 0) {\n            const\
    \ auto t = m / a;\n            m -= t * a, std::swap(m, a);\n            u -=\
    \ t * v, std::swap(u, v);\n        }\n        assert(m == 1);\n        return\
    \ u;\n    }\n};\n\ntemplate <int64_t Mod>\nstruct StaticModHolder {\n    static\
    \ constexpr int64_t mod = Mod;\n};\n\ntemplate <auto ID>\nstruct DynamicModHolder\
    \ {\n    static int64_t mod;\n};\ntemplate <auto ID>\nint64_t DynamicModHolder<ID>::mod;\n\
    \n}  // namespace impl\n\ntemplate <int64_t Mod>\nusing StaticModInt = impl::ModInt<impl::StaticModHolder<Mod>>;\n\
    \nusing ModInt1000000007 = StaticModInt<int(1e9) + 7>;\nusing ModInt998244353\
    \ = StaticModInt<998244353>;\n\ntemplate <auto ID>\nusing DynamicModInt = impl::ModInt<impl::DynamicModHolder<ID>>;\n\
    #line 2 \"Algorithm/doubling-pow.hpp\"\n#include <cmath>\n#line 3 \"Util/int-alias.hpp\"\
    \n\n/**\n * @brief int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\
    \u30B9)\n */\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n#line 4 \"\
    Algorithm/doubling-pow.hpp\"\n\n/**\n * @brief doubling-pow() (\u7E70\u308A\u8FD4\
    \u3057\u4E8C\u4E57\u6CD5)\n */\ntemplate <class Integer>\nconstexpr Integer doublingPow(const\
    \ Integer& n, const i64 expv) {\n    Integer ret = 1, square = n;\n    for (u64\
    \ p = std::abs(expv); p; p >>= 1) {\n        if (p & 1) ret *= square;\n     \
    \   square *= square;\n    }\n    return (expv < 0) ? (1 / ret) : ret;\n}\n#line\
    \ 3 \"Util/IO/println.hpp\"\n#include <utility>\n\n/**\n * @brief println() (\u53EF\
    \u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\
    \u3057\u3066\u6539\u884C\u3059\u308B)\n */\ninline void println() {\n    std::cout\
    \ << '\\n';\n}\ntemplate <class Head, class... Tail>\ninline void println(Head&&\
    \ head, Tail&&... tail) {\n    std::cout << head << &\" \"[!sizeof...(tail)];\n\
    \    println(std::forward<Tail>(tail)...);\n}\n#line 9 \"test/AOJ/DPL_5_A.test.cpp\"\
    \n\nint main() {\n    using Mint = ModInt1000000007;\n\n    int n;\n    std::cin\
    \ >> n;\n\n    Mint k;\n    std::cin >> k;\n\n    const auto ans1 = k.pow(n);\n\
    \    const auto ans2 = doublingPow(k, n);\n\n    static_assert(std::is_same_v<decltype(ans1),\
    \ decltype(ans2)>);\n    assert(ans1 == ans2);\n\n\n    println(ans1);\n\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja\"\
    \n\n#include <iostream>\n#include <type_traits>\n\n#include \"../../Math/Modulo/mod-int.hpp\"\
    \n#include \"../../Algorithm/doubling-pow.hpp\"\n#include \"../../Util/IO/println.hpp\"\
    \n\nint main() {\n    using Mint = ModInt1000000007;\n\n    int n;\n    std::cin\
    \ >> n;\n\n    Mint k;\n    std::cin >> k;\n\n    const auto ans1 = k.pow(n);\n\
    \    const auto ans2 = doublingPow(k, n);\n\n    static_assert(std::is_same_v<decltype(ans1),\
    \ decltype(ans2)>);\n    assert(ans1 == ans2);\n\n\n    println(ans1);\n\n   \
    \ return 0;\n}\n"
  dependsOn:
  - Math/Modulo/mod-int.hpp
  - Algorithm/doubling-pow.hpp
  - Util/int-alias.hpp
  - Util/IO/println.hpp
  isVerificationFile: true
  path: test/AOJ/DPL_5_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 10:59:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DPL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL_5_A.test.cpp
- /verify/test/AOJ/DPL_5_A.test.cpp.html
title: test/AOJ/DPL_5_A.test.cpp
---
