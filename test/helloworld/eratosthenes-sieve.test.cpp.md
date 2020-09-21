---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/eratosthenes-sieve.hpp
    title: "Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
      )"
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/is-prime.hpp
    title: "isPrime() (\u7D20\u6570\u5224\u5B9A $O(\\sqrt n)$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/helloworld/eratosthenes-sieve.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <bits/stdc++.h>\n\n#line 5 \"Math/Number-Theory/eratosthenes-sieve.hpp\"\n\n\
    /**\n * @brief Eratosthenes-Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9)\n * @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n */\n\
    class EratosthenesSieve {\nprivate:\n    int m_size;\n    std::vector<int> m_minFactor;\n\
    \npublic:\n    EratosthenesSieve() = default;\n\n    // [0, n] \u306E\u7BC4\u56F2\
    \u3067\u7BE9\u3092\u69CB\u7BC9\u3059\u308B\n    explicit EratosthenesSieve(int\
    \ n_)\n        : m_size(n_ + 1)\n        , m_minFactor(m_size) {\n        std::iota(m_minFactor.begin(),\
    \ m_minFactor.end(), 0);\n        for (int i = 2; i * i < m_size; ++i) {\n   \
    \         if (m_minFactor[i] < i) continue;\n            for (int j = i * i; j\
    \ < m_size; j += i) {\n                if (m_minFactor[j] == j) m_minFactor[j]\
    \ = i;\n            }\n        }\n        m_minFactor[0] = -1;\n        if (n_\
    \ >= 1) m_minFactor[1] = -1;\n    }\n\n    bool isPrime(int x) const {\n     \
    \   assert(0 <= x && x < m_size);\n        return m_minFactor[x] == x;\n    }\n\
    \n    int minFactor(int x) const {\n        assert(0 <= x && x < m_size);\n  \
    \      return m_minFactor[x];\n    }\n};\n#line 3 \"Math/Number-Theory/is-prime.hpp\"\
    \n\n/**\n * @brief isPrime() (\u7D20\u6570\u5224\u5B9A $O(\\sqrt n)$)\n */\nconstexpr\
    \ bool isPrime(int64_t n) {\n    if (n == 2) return true;\n    if (n <= 1 || n\
    \ % 2 == 0) return false;\n    for (int64_t i = 3; i * i <= n; i += 2) {\n   \
    \     if (n % i == 0) return false;\n    }\n    return true;\n}\n#line 6 \"test/helloworld/eratosthenes-sieve.test.cpp\"\
    \n\nconstexpr int N = 1e4;\nEratosthenesSieve sieve(N);\n\nvoid test_isPrime()\
    \ {\n    for (int i = 0; i <= N; ++i) {\n        assert(sieve.isPrime(i) == isPrime(i));\n\
    \    }\n\n    std::clog << __func__ << \" : OK\" << std::endl;\n}\n\nvoid test_minFactor()\
    \ {\n\n    const auto minFactor = [](int n) {\n        if (n % 2 == 0) return\
    \ 2;\n        for (int i = 3; i < n; ++i)\n            if (n % i == 0) return\
    \ i;\n        return -1;\n    };\n\n    for (int i = 2; i <= N; ++i) {\n     \
    \   if (sieve.isPrime(i)) {\n            assert(sieve.minFactor(i) == i);\n  \
    \      } else {\n            assert(sieve.minFactor(i) == minFactor(i));\n   \
    \     }\n    }\n\n    std::clog << __func__ << \" : OK\" << std::endl;\n}\n\n\
    int main() {\n    std::cout << \"Hello World\" << std::endl;\n\n    test_isPrime();\n\
    \    test_minFactor();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../Math/Number-Theory/eratosthenes-sieve.hpp\"\
    \n#include \"../../Math/Number-Theory/is-prime.hpp\"\n\nconstexpr int N = 1e4;\n\
    EratosthenesSieve sieve(N);\n\nvoid test_isPrime() {\n    for (int i = 0; i <=\
    \ N; ++i) {\n        assert(sieve.isPrime(i) == isPrime(i));\n    }\n\n    std::clog\
    \ << __func__ << \" : OK\" << std::endl;\n}\n\nvoid test_minFactor() {\n\n   \
    \ const auto minFactor = [](int n) {\n        if (n % 2 == 0) return 2;\n    \
    \    for (int i = 3; i < n; ++i)\n            if (n % i == 0) return i;\n    \
    \    return -1;\n    };\n\n    for (int i = 2; i <= N; ++i) {\n        if (sieve.isPrime(i))\
    \ {\n            assert(sieve.minFactor(i) == i);\n        } else {\n        \
    \    assert(sieve.minFactor(i) == minFactor(i));\n        }\n    }\n\n    std::clog\
    \ << __func__ << \" : OK\" << std::endl;\n}\n\nint main() {\n    std::cout <<\
    \ \"Hello World\" << std::endl;\n\n    test_isPrime();\n    test_minFactor();\n\
    \n    return 0;\n}\n"
  dependsOn:
  - Math/Number-Theory/eratosthenes-sieve.hpp
  - Math/Number-Theory/is-prime.hpp
  isVerificationFile: true
  path: test/helloworld/eratosthenes-sieve.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 11:43:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/helloworld/eratosthenes-sieve.test.cpp
layout: document
redirect_from:
- /verify/test/helloworld/eratosthenes-sieve.test.cpp
- /verify/test/helloworld/eratosthenes-sieve.test.cpp.html
title: test/helloworld/eratosthenes-sieve.test.cpp
---
