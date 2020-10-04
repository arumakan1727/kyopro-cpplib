---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/rolling-hash.hpp
    title: "Rolling-Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5,\
      \ mod\u5024 $2^{61} - 1$ \u56FA\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: Util/Debug/errln.hpp
    title: "errln() (println()\u306Estderr\u7248, \u30C7\u30D0\u30C3\u30B0\u6642\u306E\
      \u307F\u6709\u52B9)"
  - icon: ':heavy_check_mark:'
    path: Util/all-macro.hpp
    title: "all()\u30DE\u30AF\u30ED"
  - icon: ':heavy_check_mark:'
    path: Util/randoms.hpp
    title: "randoms (randint()\u3068\u304Bchoice()\u3068\u304B)"
  - icon: ':heavy_check_mark:'
    path: Util/rep-macro.hpp
    title: "rep()\u30DE\u30AF\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/helloworld/rolling-hash.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"String/rolling-hash.hpp\"\n\n#line 7 \"String/rolling-hash.hpp\"\
    \n\n/**\n * @brief Rolling-Hash (\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
    \u30E5, mod\u5024 $2^{61} - 1$ \u56FA\u5B9A)\n * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \ */\ntemplate <uint_fast64_t Base>\nclass RollingHash {\npublic:\n    using u64\
    \ = uint_fast64_t;\n    using u128 = __uint128_t;\n    static constexpr u64 MOD\
    \ = (1uL << 61) - 1;\n    static constexpr u64 BASE = Base;\n\nprivate:\n    std::vector<u64>\
    \ m_hash;\n\npublic:\n    RollingHash() = default;\n\n    template <class InputIter>\n\
    \    RollingHash(InputIter begin, InputIter end)\n        : m_hash(std::distance(begin,\
    \ end) + 1, 0) {\n        if (powArray().empty()) {\n            powArray().reserve(1e6);\n\
    \            powArray().emplace_back(1);\n        }\n        growPowArray(m_hash.size());\n\
    \n        size_t i;\n        InputIter itr;\n        for (itr = begin, i = 0;\
    \ itr != end; ++itr, ++i) {\n            m_hash[i + 1] = add(mul(m_hash[i], BASE),\
    \ *itr);\n        }\n    }\n\n    // \u6587\u5B57\u5217\u5168\u4F53\u306E\u30CF\
    \u30C3\u30B7\u30E5\u5024\n    u64 hash() const { return m_hash.back(); }\n\n \
    \   // \u534A\u958B\u533A\u9593 [l, r) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\n\
    \    u64 rangeHash(size_t l, size_t r) const {\n        assert(l < r && r < m_hash.size());\n\
    \        return add(m_hash[r], MOD - mul(m_hash[l], powArray()[r - l]));\n   \
    \ }\n\n    // rangeHash(begin, begin + length) \u3068\u7B49\u4FA1\n    u64 substr(size_t\
    \ begin, size_t length) const { return rangeHash(begin, begin + length); }\n\n\
    \    // \u3082\u3068\u306E\u6587\u5B57\u5217\u306E\u9577\u3055\n    size_t size()\
    \ const { return m_hash.size() - 1; }\n\n    // \u9023\u7D50\u3057\u305F\u6587\
    \u5B57\u5217 (leftStr + rightStr) \u306E\u30CF\u30C3\u30B7\u30E5\u5024\n    static\
    \ u64 concat(u64 leftHash, u64 rightHash, size_t rightLength) {\n        growPowArray(rightLength);\n\
    \        return add(mul(leftHash, powArray()[rightLength]), rightHash);\n    }\n\
    \nprivate:\n    static inline std::vector<u64>& powArray() {\n        static std::vector<u64>\
    \ p;\n        return p;\n    }\n\n    static constexpr inline u64 add(u64 a, u64\
    \ b) noexcept {\n        if ((a += b) >= MOD) a -= MOD;\n        return a;\n \
    \   }\n\n    static constexpr inline u64 mul(u128 a, u128 b) noexcept {\n    \
    \    const auto c = a * b;\n        return add(static_cast<u64>(c >> 61), static_cast<u64>(c\
    \ & MOD));\n    }\n\n    static inline void growPowArray(size_t len) {\n     \
    \   ++len;\n        while (powArray().size() < len) {\n            powArray().emplace_back(mul(powArray().back(),\
    \ BASE));\n        }\n    }\n};\n#line 5 \"test/helloworld/rolling-hash.test.cpp\"\
    \n\n#line 2 \"Util/randoms.hpp\"\n\n#line 5 \"Util/randoms.hpp\"\n\n/**\n * @brief\
    \ randoms (randint()\u3068\u304Bchoice()\u3068\u304B)\n */\nnamespace arumakan::random\
    \ {\n\nstd::mt19937 mt(std::random_device{}());\n\n// \u9589\u533A\u9593[min,\
    \ max] \u306E\u4E71\u6570\u3092\u4E00\u69D8\u5206\u5E03\u3067\u751F\u6210\u3059\
    \u308B\ntemplate <class Integer>\nInteger randint(Integer min, Integer max) {\n\
    \    return std::uniform_int_distribution<Integer>(min, max)(mt);\n}\n\n// dest\
    \ \u306B randint(sizeMin, sizeMax) \u56DE randint(valueMin, valueMax) \u3092\u683C\
    \u7D0D\u3059\u308B\ntemplate <class OutputIter, class Integer>\nOutputIter randomValueContainer(OutputIter\
    \ dest, Integer valueMin, Integer valueMax, size_t sizeMin, size_t sizeMax) {\n\
    \    auto size = randint(sizeMin, sizeMax);\n    while (size--) {\n        *dest\
    \ = randint(valueMin, valueMax);\n        ++dest;\n    }\n    return dest;\n}\n\
    \n// \u8981\u7D20\u6570\u304C randint(sizeMin, sizeMax) \u306E randint(valueMin,\
    \ valueMax) \u3092\u751F\u6210\u3059\u308B\ntemplate <class Container, class Integer>\n\
    Container randomValueContainer(Integer valueMin, Integer valueMax, size_t sizeMin,\
    \ size_t sizeMax) {\n    Container ret;\n    randomValueContainer(std::back_inserter(ret),\
    \ valueMin, valueMax, sizeMin, sizeMax);\n    return ret;\n}\n\n// [begin, end)\
    \ \u306E\u7BC4\u56F2\u306E\u3046\u3061\u3072\u3068\u3064\u3092\u30E9\u30F3\u30C0\
    \u30E0\u306B\u9078\u3093\u3067\u8FD4\u3059\ntemplate <class RandomAccessIter>\n\
    auto choice(RandomAccessIter begin, RandomAccessIter end) {\n    const auto i\
    \ = randint<size_t>(0, std::distance(begin, end));\n    return begin[i];\n}\n\n\
    }  // namespace rand\n#line 2 \"Util/all-macro.hpp\"\n\n/**\n * @brief all()\u30DE\
    \u30AF\u30ED\n */\n#define all(x) std::begin(x), std::end(x)\n#define rall(x)\
    \ std::rbegin(x), std::rend(x)\n#line 2 \"Util/rep-macro.hpp\"\n\n/**\n * @brief\
    \ rep()\u30DE\u30AF\u30ED\n */\n#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>>\
    \ i = (begin), i##_end = (end); i < i##_end; ++i)\n#define repc(i, begin, last)\
    \ for (std::make_signed_t<std::remove_cv_t<decltype(last)>> i = (begin), i##_last\
    \ = (last); i <= i##_last; ++i)\n#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(begin)>>\
    \ i = (begin), i##_last = (last); i >= i##_last; --i)\n#line 2 \"Util/Debug/errln.hpp\"\
    \n\n#line 4 \"Util/Debug/errln.hpp\"\n\n/**\n * @brief errln() (println()\u306E\
    stderr\u7248, \u30C7\u30D0\u30C3\u30B0\u6642\u306E\u307F\u6709\u52B9)\n */\ninline\
    \ void eprintln() {\n    std::clog << std::endl;\n}\ntemplate <class Head, class...\
    \ Tail>\ninline void eprintln(Head&& head, Tail&&... tail) {\n    std::clog <<\
    \ head << &\" \"[!sizeof...(tail)];\n    eprintln(std::forward<Tail>(tail)...);\n\
    }\n\n#ifdef LOCAL_DEBUG\n#define errln(...) std::clog << __FILE__ << \"(\" <<\
    \ __LINE__ << \")[\" << __func__ << \"()]: \", eprintln(__VA_ARGS__)\n#else\n\
    #define errln(...) ((void)0)\n#endif\n#line 10 \"test/helloworld/rolling-hash.test.cpp\"\
    \n\nusing namespace std;\nnamespace rnd = arumakan::random;\nusing RH = RollingHash<17273747>;\n\
    \nconst auto testdatas = []() -> vector<pair<string, RH>> {\n    string s1 = \"\
    a\";\n    string s2 = \"zzzzz\";\n    string s3 = rnd::randomValueContainer<string>('a',\
    \ 'b', 30, 50);\n    string s4 = rnd::randomValueContainer<string>('x', 'z', 30,\
    \ 50);\n\n    return {\n        {s1, RH(all(s1))},\n        {s2, RH(all(s2))},\n\
    \        {s3, RH(all(s3))},\n        {s4, RH(all(s4))},\n    };\n}();\n\nvoid\
    \ test_hash() {\n    for (const auto& [str, rolhash] : testdatas) {\n        assert(rolhash.hash()\
    \ == rolhash.rangeHash(0, str.length()));\n    }\n\n    errln(\"OK\");\n}\n\n\
    void test_rangeHash_and_substr() {\n    for (const auto& [str, rolhash] : testdatas)\
    \ {\n        const auto N = str.length();\n        rep(l1, 0, N) rep(r1, l1 +\
    \ 1, N) {\n            rep(l2, 0, N) rep(r2, l2 + 1, N) {\n                const\
    \ auto len1 = r1 - l1;\n                const auto len2 = r2 - l2;\n\n       \
    \         const bool equality_expected = string_view(str).substr(l1, len1) ==\
    \ string_view(str).substr(l2, len2);\n                const bool equality_rangeHash\
    \ = rolhash.rangeHash(l1, r1) == rolhash.rangeHash(l2, r2);\n                const\
    \ bool equality_substr = rolhash.substr(l1, len1) == rolhash.substr(l2, len2);\n\
    \                assert(equality_rangeHash == equality_expected);\n          \
    \      assert(equality_substr == equality_expected);\n            }\n        }\n\
    \    }\n\n    errln(\"OK\");\n}\n\nvoid test_concat() {\n    vector<int> a{1,\
    \ 2, 3, 1, 2, 3};\n    RH rolhash(all(a));\n\n    const auto N = a.size();\n \
    \   rep(l, 0, N) rep(m, l + 1, N) rep(r, m + 1, N) {\n        const auto leftHash\
    \ = rolhash.rangeHash(l, m);\n        const auto rightHash = rolhash.rangeHash(m,\
    \ r);\n        const auto got = rolhash.concat(leftHash, rightHash, r - m);\n\
    \        const auto expected = rolhash.rangeHash(l, r);\n        assert(got ==\
    \ expected);\n    }\n    errln(\"OK\");\n}\n\nint main() {\n    std::cout << \"\
    Hello World\" << std::endl;\n\n    test_hash();\n    test_rangeHash_and_substr();\n\
    \    test_concat();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../String/rolling-hash.hpp\"\n\n#include\
    \ \"../../Util/randoms.hpp\"\n#include \"../../Util/all-macro.hpp\"\n#include\
    \ \"../../Util/rep-macro.hpp\"\n#include \"../../Util/Debug/errln.hpp\"\n\nusing\
    \ namespace std;\nnamespace rnd = arumakan::random;\nusing RH = RollingHash<17273747>;\n\
    \nconst auto testdatas = []() -> vector<pair<string, RH>> {\n    string s1 = \"\
    a\";\n    string s2 = \"zzzzz\";\n    string s3 = rnd::randomValueContainer<string>('a',\
    \ 'b', 30, 50);\n    string s4 = rnd::randomValueContainer<string>('x', 'z', 30,\
    \ 50);\n\n    return {\n        {s1, RH(all(s1))},\n        {s2, RH(all(s2))},\n\
    \        {s3, RH(all(s3))},\n        {s4, RH(all(s4))},\n    };\n}();\n\nvoid\
    \ test_hash() {\n    for (const auto& [str, rolhash] : testdatas) {\n        assert(rolhash.hash()\
    \ == rolhash.rangeHash(0, str.length()));\n    }\n\n    errln(\"OK\");\n}\n\n\
    void test_rangeHash_and_substr() {\n    for (const auto& [str, rolhash] : testdatas)\
    \ {\n        const auto N = str.length();\n        rep(l1, 0, N) rep(r1, l1 +\
    \ 1, N) {\n            rep(l2, 0, N) rep(r2, l2 + 1, N) {\n                const\
    \ auto len1 = r1 - l1;\n                const auto len2 = r2 - l2;\n\n       \
    \         const bool equality_expected = string_view(str).substr(l1, len1) ==\
    \ string_view(str).substr(l2, len2);\n                const bool equality_rangeHash\
    \ = rolhash.rangeHash(l1, r1) == rolhash.rangeHash(l2, r2);\n                const\
    \ bool equality_substr = rolhash.substr(l1, len1) == rolhash.substr(l2, len2);\n\
    \                assert(equality_rangeHash == equality_expected);\n          \
    \      assert(equality_substr == equality_expected);\n            }\n        }\n\
    \    }\n\n    errln(\"OK\");\n}\n\nvoid test_concat() {\n    vector<int> a{1,\
    \ 2, 3, 1, 2, 3};\n    RH rolhash(all(a));\n\n    const auto N = a.size();\n \
    \   rep(l, 0, N) rep(m, l + 1, N) rep(r, m + 1, N) {\n        const auto leftHash\
    \ = rolhash.rangeHash(l, m);\n        const auto rightHash = rolhash.rangeHash(m,\
    \ r);\n        const auto got = rolhash.concat(leftHash, rightHash, r - m);\n\
    \        const auto expected = rolhash.rangeHash(l, r);\n        assert(got ==\
    \ expected);\n    }\n    errln(\"OK\");\n}\n\nint main() {\n    std::cout << \"\
    Hello World\" << std::endl;\n\n    test_hash();\n    test_rangeHash_and_substr();\n\
    \    test_concat();\n\n    return 0;\n}\n"
  dependsOn:
  - String/rolling-hash.hpp
  - Util/randoms.hpp
  - Util/all-macro.hpp
  - Util/rep-macro.hpp
  - Util/Debug/errln.hpp
  isVerificationFile: true
  path: test/helloworld/rolling-hash.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 18:37:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/helloworld/rolling-hash.test.cpp
layout: document
redirect_from:
- /verify/test/helloworld/rolling-hash.test.cpp
- /verify/test/helloworld/rolling-hash.test.cpp.html
title: test/helloworld/rolling-hash.test.cpp
---
