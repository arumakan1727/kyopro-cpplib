---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data-Structure/Disjoint-Set/union-find.hpp
    title: "Union-Find (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/AOJ/DSL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include <bits/stdc++.h>\n\n#line 7 \"Data-Structure/Disjoint-Set/union-find.hpp\"\
    \n\n/**\n * @brief Union-Find (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
    )\n * @note path-compression + union-by-size\n */\nclass UnionFind {\nprivate:\n\
    \    int n;\n    mutable std::vector<int> p;\n\npublic:\n    UnionFind() = default;\n\
    \n    explicit UnionFind(int n_)\n        : n(n_)\n        , p(n_, -1) {}\n\n\
    \    int unite(int x, int y) {\n        x = leader(x), y = leader(y);\n      \
    \  if (x == y) return x;\n        if (p[y] < p[x]) std::swap(x, y);\n        p[x]\
    \ += p[y];\n        p[y] = x;\n        return x;\n    }\n\n    int leader(int\
    \ x) const { return p[x] < 0 ? x : p[x] = leader(p[x]); }\n\n    bool same(int\
    \ x, int y) const { return leader(x) == leader(y); }\n\n    int size(int x) const\
    \ { return -p[leader(x)]; }\n\n    std::vector<std::vector<int>> groups() const\
    \ {\n        std::vector<int> leaderBuf(n), groupSize(n);\n        for (int i\
    \ = 0; i < n; i++) ++groupSize[leaderBuf[i] = leader(i)];\n\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) result[i].reserve(groupSize[i]);\n\
    \        for (int i = 0; i < n; i++) result[leaderBuf[i]].push_back(i);\n    \
    \    result.erase(std::remove_if(result.begin(), result.end(), [](const std::vector<int>&\
    \ v) { return v.empty(); }), result.end());\n        return result;\n    }\n};\n\
    #line 5 \"test/AOJ/DSL_1_A.test.cpp\"\nusing namespace std;\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\n  \
    \  constexpr char LF = '\\n';\n\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind\
    \ uf(N);\n    while (Q--) {\n        int com, x, y;\n        cin >> com >> x >>\
    \ y;\n\n        if (com == 0) {\n            uf.unite(x, y);\n        } else {\n\
    \            cout << uf.same(x, y) << LF;\n        }\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"../../Data-Structure/Disjoint-Set/union-find.hpp\"\
    \nusing namespace std;\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \n    constexpr char LF = '\\n';\n\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind\
    \ uf(N);\n    while (Q--) {\n        int com, x, y;\n        cin >> com >> x >>\
    \ y;\n\n        if (com == 0) {\n            uf.unite(x, y);\n        } else {\n\
    \            cout << uf.same(x, y) << LF;\n        }\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - Data-Structure/Disjoint-Set/union-find.hpp
  isVerificationFile: true
  path: test/AOJ/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 10:59:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_1_A.test.cpp
- /verify/test/AOJ/DSL_1_A.test.cpp.html
title: test/AOJ/DSL_1_A.test.cpp
---
