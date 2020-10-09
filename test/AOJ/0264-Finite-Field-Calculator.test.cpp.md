---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Modulo/mod-int.hpp
    title: "Mod-Int (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642mod\u578B\u3068\u5B9F\u884C\
      \u6642mod\u578B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#
  bundledCode: "#line 1 \"test/AOJ/0264-Finite-Field-Calculator.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#\"\
    \n#include <cassert>\n#include <cctype>\n#include <cstdio>\n#include <string>\n\
    #include <vector>\n#include <sstream>\n#include <stdexcept>\n\n#line 2 \"Math/Modulo/mod-int.hpp\"\
    \n#include <cstdint>\n#line 4 \"Math/Modulo/mod-int.hpp\"\n#include <iostream>\n\
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
    \ = StaticModInt<998244353>;\n\ntemplate <int ID>\nusing DynamicModInt = internal::ModInt<internal::DynamicModHolder<ID>>;\n\
    #line 11 \"test/AOJ/0264-Finite-Field-Calculator.test.cpp\"\n\nusing namespace\
    \ std;\nusing Mint = DynamicModInt<0>;\nusing Itr = string::const_iterator;\n\n\
    Mint expr(Itr&);\nMint term(Itr&);\nMint factor(Itr&);\nMint number(Itr&);\n\n\
    Mint expr(Itr& p) {\n    Mint res = term(p);\n    while (*p == '+' || *p == '-')\
    \ {\n        if (*p == '+') {\n            res += term(++p);\n        } else {\n\
    \            res -= term(++p);\n        }\n    }\n    return res;\n}\n\nMint term(Itr&\
    \ p) {\n    Mint res = factor(p);\n    while (*p == '*' || *p == '/') {\n    \
    \    if (*p == '*') {\n            res *= factor(++p);\n        } else {\n   \
    \         const auto v = factor(++p);\n            if (v == 0) throw std::runtime_error(\"\
    Divide by zero\");\n            res /= v;\n        }\n    }\n    return res;\n\
    }\n\nMint factor(Itr& p) {\n    if (*p == '(') {\n        const auto res = expr(++p);\n\
    \        assert(*p == ')');\n        ++p;\n        return res;\n    }\n    assert(isdigit(*p));\n\
    \    return number(p);\n}\n\nMint number(Itr& p) {\n    int res = 0;\n    while\
    \ (isdigit(*p)) {\n        res = res * 10 + (*p - '0');\n        ++p;\n    }\n\
    \    return Mint::raw(res);\n}\n\nstring removeSpace(const char* s) {\n    string\
    \ res;\n    res.reserve(100010);\n\n    istringstream iss(s);\n    string part;\n\
    \    while (iss >> part) res += move(part);\n\n    return res;\n}\n\nint main()\
    \ {\n    static char line[100100];\n\n    int p;\n    while (scanf(\" %d :\",\
    \ &p), p) {\n        Mint::setMod(p);\n\n        fgets(line, sizeof(line), stdin);\n\
    \        const string s = removeSpace(line);\n\n        try {\n            Itr\
    \ itr = s.cbegin();\n            auto ans = expr(itr);\n            printf(\"\
    %s = %d (mod %ld)\\n\", s.c_str(), int(ans), Mint::mod());\n        } catch (const\
    \ std::runtime_error& e) {\n            puts(\"NG\");\n        }\n    }\n\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#\"\
    \n#include <cassert>\n#include <cctype>\n#include <cstdio>\n#include <string>\n\
    #include <vector>\n#include <sstream>\n#include <stdexcept>\n\n#include \"../../Math/Modulo/mod-int.hpp\"\
    \n\nusing namespace std;\nusing Mint = DynamicModInt<0>;\nusing Itr = string::const_iterator;\n\
    \nMint expr(Itr&);\nMint term(Itr&);\nMint factor(Itr&);\nMint number(Itr&);\n\
    \nMint expr(Itr& p) {\n    Mint res = term(p);\n    while (*p == '+' || *p ==\
    \ '-') {\n        if (*p == '+') {\n            res += term(++p);\n        } else\
    \ {\n            res -= term(++p);\n        }\n    }\n    return res;\n}\n\nMint\
    \ term(Itr& p) {\n    Mint res = factor(p);\n    while (*p == '*' || *p == '/')\
    \ {\n        if (*p == '*') {\n            res *= factor(++p);\n        } else\
    \ {\n            const auto v = factor(++p);\n            if (v == 0) throw std::runtime_error(\"\
    Divide by zero\");\n            res /= v;\n        }\n    }\n    return res;\n\
    }\n\nMint factor(Itr& p) {\n    if (*p == '(') {\n        const auto res = expr(++p);\n\
    \        assert(*p == ')');\n        ++p;\n        return res;\n    }\n    assert(isdigit(*p));\n\
    \    return number(p);\n}\n\nMint number(Itr& p) {\n    int res = 0;\n    while\
    \ (isdigit(*p)) {\n        res = res * 10 + (*p - '0');\n        ++p;\n    }\n\
    \    return Mint::raw(res);\n}\n\nstring removeSpace(const char* s) {\n    string\
    \ res;\n    res.reserve(100010);\n\n    istringstream iss(s);\n    string part;\n\
    \    while (iss >> part) res += move(part);\n\n    return res;\n}\n\nint main()\
    \ {\n    static char line[100100];\n\n    int p;\n    while (scanf(\" %d :\",\
    \ &p), p) {\n        Mint::setMod(p);\n\n        fgets(line, sizeof(line), stdin);\n\
    \        const string s = removeSpace(line);\n\n        try {\n            Itr\
    \ itr = s.cbegin();\n            auto ans = expr(itr);\n            printf(\"\
    %s = %d (mod %ld)\\n\", s.c_str(), int(ans), Mint::mod());\n        } catch (const\
    \ std::runtime_error& e) {\n            puts(\"NG\");\n        }\n    }\n\n  \
    \  return 0;\n}"
  dependsOn:
  - Math/Modulo/mod-int.hpp
  isVerificationFile: true
  path: test/AOJ/0264-Finite-Field-Calculator.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 05:22:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/0264-Finite-Field-Calculator.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/0264-Finite-Field-Calculator.test.cpp
- /verify/test/AOJ/0264-Finite-Field-Calculator.test.cpp.html
title: test/AOJ/0264-Finite-Field-Calculator.test.cpp
---
