---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/eratosthenes-sieve.hpp
    title: "Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
      )"
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/osa_k.hpp
    title: "osa_k() (\u524D\u8A08\u7B97 $O(N \\log \\log N)$, \u7D20\u56E0\u6570\u5206\
      \u89E3 $O(\\log N)$)"
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/divisor-count-table.hpp
    title: "divisorCountTable (\u7D04\u6570\u306E\u500B\u6570\u306E\u30C6\u30FC\u30D6\
      \u30EB, $O(N \\log N)$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/helloworld/divisor-count-table.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#line 5 \"Math/Number-Theory/eratosthenes-sieve.hpp\"\
    \n\n/**\n * @brief Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9)\n * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    \ */\nclass EratosthenesSieve {\nprivate:\n    int m_size;\n    std::vector<int>\
    \ m_minFactor;\n\npublic:\n    EratosthenesSieve() = default;\n\n    // [0, n]\
    \ \u306E\u7BC4\u56F2\u3067\u7BE9\u3092\u69CB\u7BC9\u3059\u308B\n    explicit EratosthenesSieve(int\
    \ n_)\n        : m_size(n_ + 1)\n        , m_minFactor(m_size) {\n        std::iota(m_minFactor.begin(),\
    \ m_minFactor.end(), 0);\n        for (int i = 2; i * i < m_size; ++i) {\n   \
    \         if (m_minFactor[i] < i) continue;\n            for (int j = i * i; j\
    \ < m_size; j += i) {\n                if (m_minFactor[j] == j) m_minFactor[j]\
    \ = i;\n            }\n        }\n        m_minFactor[0] = -1;\n        if (n_\
    \ >= 1) m_minFactor[1] = -1;\n    }\n\n    bool isPrime(int x) const {\n     \
    \   assert(0 <= x && x < m_size);\n        return m_minFactor[x] == x;\n    }\n\
    \n    int minFactor(int x) const {\n        assert(0 <= x && x < m_size);\n  \
    \      return m_minFactor[x];\n    }\n};\n#line 2 \"Math/Number-Theory/osa_k.hpp\"\
    \n\n#line 4 \"Math/Number-Theory/osa_k.hpp\"\n\n#line 6 \"Math/Number-Theory/osa_k.hpp\"\
    \n\n/**\n * @brief osa_k() (\u524D\u8A08\u7B97 $O(N \\log \\log N)$, \u7D20\u56E0\
    \u6570\u5206\u89E3 $O(\\log N)$)\n * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    \ */\nstd::map<int, int> osa_k(int n, const EratosthenesSieve& es) {\n    std::map<int,\
    \ int> ret;\n    while (n > 1) {\n        ++ret[es.minFactor(n)];\n        n /=\
    \ es.minFactor(n);\n    }\n    return ret;\n}\n#line 2 \"Math/Number-Theory/divisor-count-table.hpp\"\
    \n\n#line 4 \"Math/Number-Theory/divisor-count-table.hpp\"\n\n/**\n * @brief divisorCountTable\
    \ (\u7D04\u6570\u306E\u500B\u6570\u306E\u30C6\u30FC\u30D6\u30EB, $O(N \\log N)$)\n\
    \ * cnt[i] = i \u306E\u7D04\u6570\u306E\u500B\u6570; \u7BC4\u56F2\u306F\u9589\u533A\
    \u9593 [0, N]\n */\nstd::vector<int> divisorCountTable(int N) {\n    std::vector<int>\
    \ cnt(N + 1);\n    for (int d = 1; d <= N; ++d) {\n        for (int i = d; i <=\
    \ N; i += d) ++cnt[i];\n    }\n    return cnt;\n}\n#line 7 \"test/helloworld/divisor-count-table.test.cpp\"\
    \n\nconstexpr int N = 1e5;\n\nint divisorCount(int n, const EratosthenesSieve&\
    \ sieve) {\n    int ret = 1;\n    for (const auto [value, cnt] : osa_k(n, sieve))\
    \ {\n        ret *= (cnt + 1);\n    }\n    return ret;\n}\n\nvoid test_divisorCountTable()\
    \ {\n    const auto dct = divisorCountTable(N);\n    const auto sieve = EratosthenesSieve(N);\n\
    \n    for (int i = 1; i <= N; ++i) {\n        const auto expected = divisorCount(i,\
    \ sieve);\n        const auto got = dct[i];\n        assert(got == expected);\n\
    \    }\n\n    std::clog << __func__ << \" : OK\" << std::endl;\n}\n\nint main()\
    \ {\n    std::cout << \"Hello World\" << std::endl;\n\n    test_divisorCountTable();\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../Math/Number-Theory/eratosthenes-sieve.hpp\"\
    \n#include \"../../Math/Number-Theory/osa_k.hpp\"\n#include \"../../Math/Number-Theory/divisor-count-table.hpp\"\
    \n\nconstexpr int N = 1e5;\n\nint divisorCount(int n, const EratosthenesSieve&\
    \ sieve) {\n    int ret = 1;\n    for (const auto [value, cnt] : osa_k(n, sieve))\
    \ {\n        ret *= (cnt + 1);\n    }\n    return ret;\n}\n\nvoid test_divisorCountTable()\
    \ {\n    const auto dct = divisorCountTable(N);\n    const auto sieve = EratosthenesSieve(N);\n\
    \n    for (int i = 1; i <= N; ++i) {\n        const auto expected = divisorCount(i,\
    \ sieve);\n        const auto got = dct[i];\n        assert(got == expected);\n\
    \    }\n\n    std::clog << __func__ << \" : OK\" << std::endl;\n}\n\nint main()\
    \ {\n    std::cout << \"Hello World\" << std::endl;\n\n    test_divisorCountTable();\n\
    \n    return 0;\n}\n"
  dependsOn:
  - Math/Number-Theory/eratosthenes-sieve.hpp
  - Math/Number-Theory/osa_k.hpp
  - Math/Number-Theory/divisor-count-table.hpp
  isVerificationFile: true
  path: test/helloworld/divisor-count-table.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 12:52:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/helloworld/divisor-count-table.test.cpp
layout: document
redirect_from:
- /verify/test/helloworld/divisor-count-table.test.cpp
- /verify/test/helloworld/divisor-count-table.test.cpp.html
title: test/helloworld/divisor-count-table.test.cpp
---
