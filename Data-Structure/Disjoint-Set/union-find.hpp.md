---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Minimum-Spanning-Tree/kruskal.hpp
    title: "kruskal() (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_A.test.cpp
    title: test/AOJ/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
    title: test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Union-Find (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020)"
    links: []
  bundledCode: "#line 2 \"Data-Structure/Disjoint-Set/union-find.hpp\"\n#include <cassert>\n\
    #include <cstdint>\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief Union-Find (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
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
    \ v) { return v.empty(); }), result.end());\n        return result;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief Union-Find (\u7D20\u96C6\
    \u5408\u30C7\u30FC\u30BF\u69CB\u9020)\n * @note path-compression + union-by-size\n\
    \ */\nclass UnionFind {\nprivate:\n    int n;\n    mutable std::vector<int> p;\n\
    \npublic:\n    UnionFind() = default;\n\n    explicit UnionFind(int n_)\n    \
    \    : n(n_)\n        , p(n_, -1) {}\n\n    int unite(int x, int y) {\n      \
    \  x = leader(x), y = leader(y);\n        if (x == y) return x;\n        if (p[y]\
    \ < p[x]) std::swap(x, y);\n        p[x] += p[y];\n        p[y] = x;\n       \
    \ return x;\n    }\n\n    int leader(int x) const { return p[x] < 0 ? x : p[x]\
    \ = leader(p[x]); }\n\n    bool same(int x, int y) const { return leader(x) ==\
    \ leader(y); }\n\n    int size(int x) const { return -p[leader(x)]; }\n\n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<int> leaderBuf(n), groupSize(n);\n   \
    \     for (int i = 0; i < n; i++) ++groupSize[leaderBuf[i] = leader(i)];\n\n \
    \       std::vector<std::vector<int>> result(n);\n        for (int i = 0; i <\
    \ n; i++) result[i].reserve(groupSize[i]);\n        for (int i = 0; i < n; i++)\
    \ result[leaderBuf[i]].push_back(i);\n        result.erase(std::remove_if(result.begin(),\
    \ result.end(), [](const std::vector<int>& v) { return v.empty(); }), result.end());\n\
    \        return result;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data-Structure/Disjoint-Set/union-find.hpp
  requiredBy:
  - Graph/Minimum-Spanning-Tree/kruskal.hpp
  timestamp: '2020-09-13 19:39:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_1_A.test.cpp
  - test/AOJ/GRL_2_A-Minimum-Spanning-Tree.test.cpp
documentation_of: Data-Structure/Disjoint-Set/union-find.hpp
layout: document
redirect_from:
- /library/Data-Structure/Disjoint-Set/union-find.hpp
- /library/Data-Structure/Disjoint-Set/union-find.hpp.html
title: "Union-Find (\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020)"
---
