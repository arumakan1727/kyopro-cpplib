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
    path: Math/Number-Theory/prime-factorize.hpp
    title: "primeFactorize() (\u7D20\u56E0\u6570\u5206\u89E3 $O(\\sqrt n)$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/helloworld/osa_k.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#line 5 \"Math/Number-Theory/eratosthenes-sieve.hpp\"\
    \n\n/**\n * @brief Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9)\n * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    \ */\nclass EratosthenesSieve {\nprivate:\n    int m_size;\n    std::vector<int>\
    \ m_minFactor;\n\npublic:\n    EratosthenesSieve() = default;\n\n    //! [0, n]\
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
    \ es.minFactor(n);\n    }\n    return ret;\n}\n#line 3 \"Math/Number-Theory/prime-factorize.hpp\"\
    \n\n/**\n * @brief primeFactorize() (\u7D20\u56E0\u6570\u5206\u89E3 $O(\\sqrt\
    \ n)$)\n */\ntemplate <class Integer>\nstd::map<Integer, int> primeFactorize(Integer\
    \ n) {\n    std::map<Integer, int> res;\n    for (Integer i = 2; i * i <= n; ++i)\
    \ {\n        while (n % i == 0) {\n            ++res[i];\n            n /= i;\n\
    \        }\n    }\n    if (n != 1) res[n] = 1;\n    return res;\n}\n#line 7 \"\
    test/helloworld/osa_k.test.cpp\"\n\nconstexpr int N = 1e4;\n\nvoid test_osa_k()\
    \ {\n    const auto sieve = EratosthenesSieve(N);\n    \n    for (int i = 2; i\
    \ <= N; ++i) {\n        const auto expected = primeFactorize(i);\n        const\
    \ auto got = osa_k(i, sieve);\n        assert(got == expected);\n    }\n\n   \
    \ std::clog << __func__ << \" : OK\" << std::endl;\n}\n\nint main() {\n    std::cout\
    \ << \"Hello World\" << std::endl;\n\n    test_osa_k();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../Math/Number-Theory/eratosthenes-sieve.hpp\"\
    \n#include \"../../Math/Number-Theory/osa_k.hpp\"\n#include \"../../Math/Number-Theory/prime-factorize.hpp\"\
    \n\nconstexpr int N = 1e4;\n\nvoid test_osa_k() {\n    const auto sieve = EratosthenesSieve(N);\n\
    \    \n    for (int i = 2; i <= N; ++i) {\n        const auto expected = primeFactorize(i);\n\
    \        const auto got = osa_k(i, sieve);\n        assert(got == expected);\n\
    \    }\n\n    std::clog << __func__ << \" : OK\" << std::endl;\n}\n\nint main()\
    \ {\n    std::cout << \"Hello World\" << std::endl;\n\n    test_osa_k();\n\n \
    \   return 0;\n}\n"
  dependsOn:
  - Math/Number-Theory/eratosthenes-sieve.hpp
  - Math/Number-Theory/osa_k.hpp
  - Math/Number-Theory/prime-factorize.hpp
  isVerificationFile: true
  path: test/helloworld/osa_k.test.cpp
  requiredBy: []
  timestamp: '2020-10-25 20:18:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/helloworld/osa_k.test.cpp
layout: document
redirect_from:
- /verify/test/helloworld/osa_k.test.cpp
- /verify/test/helloworld/osa_k.test.cpp.html
title: test/helloworld/osa_k.test.cpp
---
