---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Data-Structure/Range-Accumulate/cumulative-sum.hpp
    title: "CumulativeSum (\u7D2F\u7A4D\u548C)"
  - icon: ':warning:'
    path: Data-Structure/Range-Accumulate/foldLR.hpp
    title: FoldLR
  - icon: ':heavy_check_mark:'
    path: Util/IO/println.hpp
    title: "println() (\u53EF\u5909\u500B\u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\
      \u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\u3059\u308B)"
  - icon: ':warning:'
    path: Util/IO/read.hpp
    title: "read() (n\u500B\u5165\u529B\u3057\u3066Container\u306B\u683C\u7D0D\u3057\
      \u3066\u8FD4\u3059)"
  - icon: ':heavy_check_mark:'
    path: Util/all-macro.hpp
    title: "all()\u30DE\u30AF\u30ED"
  - icon: ':heavy_check_mark:'
    path: Util/int-alias.hpp
    title: "int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static-range-sum.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#include <cassert>\n#include <iostream>\n#include <vector>\n\n#line 2 \"Data-Structure/Range-Accumulate/cumulative-sum.hpp\"\
    \n#include <functional>\n#include <valarray>\n#include <utility>\n\n/**\n * @brief\
    \ CumulativeSum (\u7D2F\u7A4D\u548C)\n */\ntemplate <class T>\nstruct CumulativeSum\
    \ {\n    std::valarray<T> data;\n\n    CumulativeSum() = default;\n\n    template\
    \ <class Container>\n    explicit CumulativeSum(const Container& container)\n\
    \        : CumulativeSum(container.cbegin(), container.cend()) {}\n\n    template\
    \ <class InputItr>\n    CumulativeSum(InputItr begin, InputItr end)\n        :\
    \ data(std::distance(begin, end) + 1) {\n        size_t i;\n        InputItr itr;\n\
    \        for (i = 0, itr = begin; itr != end; ++i, ++itr) {\n            data[i\
    \ + 1] = data[i] + *itr;\n        }\n    }\n\n    //! [0, r)\n    const T prefixSum(size_t\
    \ r) const { return data[r]; }\n\n    //! [l, r)\n    const T sum(size_t l, size_t\
    \ r) const { return prefixSum(r) - prefixSum(l); }\n};\n#line 3 \"Data-Structure/Range-Accumulate/foldLR.hpp\"\
    \n\n/**\n * @brief FoldLR\n */\ntemplate <class T>\nclass FoldLR {\n    std::vector<T>\
    \ m_foldL, m_foldR;\n    T m_e;\n\npublic:\n    FoldLR() = default;\n\n    template\
    \ <class BidirectionalItr, class Op>\n    FoldLR(BidirectionalItr begin, BidirectionalItr\
    \ end, const T& e, Op op)\n        : FoldLR(begin, end, e, op, op) {}\n\n    /**\n\
    \     * foldLeftOp: (T, Elem) -> T\n     * foldRightOp: (Elem, T) -> T\n     */\n\
    \    template <class BidirectionalItr, class FoldLeftOp, class FoldRightOp>\n\
    \    FoldLR(BidirectionalItr begin, BidirectionalItr end, const T& e, FoldLeftOp\
    \ foldLeftOp, FoldRightOp foldRightOp)\n        : m_foldL(std::distance(begin,\
    \ end) + 1, e)\n        , m_foldR(std::distance(begin, end) + 1, e)\n        ,\
    \ m_e(e) {\n        size_t i;\n        BidirectionalItr itr;\n        for (i =\
    \ 0, itr = begin; itr != end; ++i, ++itr) {\n            m_foldL[i + 1] = foldLeftOp(m_foldL[i],\
    \ *itr);\n        }\n        for (i = m_foldR.size() - 1, itr = std::prev(end);\
    \ i > 0; --i, --itr) {\n            m_foldR[i - 1] = foldRightOp(*itr, m_foldR[i]);\n\
    \        }\n    }\n\n    /**\n     * [0, r)\n     * ((((e op a[0]) op a[1]) op\
    \ a[2]) ... op a[r - 1])\n     * foldL(0) returns e();\n     */\n    const T foldL(size_t\
    \ r) const { return m_foldL[r]; }\n\n    /**\n     * [l, N)\n     * (a[l] op ...\
    \ (a[N - 3] op (a[N - 2] op (a[N - 1] op e))))\n     * foldR(N) returns e();\n\
    \     */\n    const T foldR(size_t l) const { return m_foldR[l]; }\n\n    const\
    \ T e() const { return m_e; }\n};\n#line 8 \"test/yosupo/static-range-sum.cpp\"\
    \n\n#line 4 \"Util/IO/println.hpp\"\n\n/**\n * @brief println() (\u53EF\u5909\u500B\
    \u306E\u5024\u3092\u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\
    \u6539\u884C\u3059\u308B)\n */\ninline void println() {\n    std::cout << '\\\
    n';\n}\ntemplate <class Head, class... Tail>\ninline void println(Head&& head,\
    \ Tail&&... tail) {\n    std::cout << head << &\" \"[!sizeof...(tail)];\n    println(std::forward<Tail>(tail)...);\n\
    }\n#line 4 \"Util/IO/read.hpp\"\n\n/**\n * @brief read() (n\u500B\u5165\u529B\u3057\
    \u3066Container\u306B\u683C\u7D0D\u3057\u3066\u8FD4\u3059)\n */\ntemplate <class\
    \ T = int, template <class, class...> class Container = std::vector>\nContainer<T>\
    \ read(size_t n) {\n    Container<T> ret(n);\n    for (auto& e : ret) std::cin\
    \ >> e;\n    return ret;\n}\n#line 2 \"Util/int-alias.hpp\"\n#include <cstdint>\n\
    \n/**\n * @brief int-alias (\u6574\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9\
    )\n */\nusing i64 = int64_t;\nusing u64 = uint64_t;\n#line 2 \"Util/all-macro.hpp\"\
    \n\n/**\n * @brief all()\u30DE\u30AF\u30ED\n */\n#define all(x) std::begin(x),\
    \ std::end(x)\n#define rall(x) std::rbegin(x), std::rend(x)\n#line 13 \"test/yosupo/static-range-sum.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \n    int N, Q;\n    std::cin >> N >> Q;\n\n    auto a = read<int>(N);\n\n   \
    \ CumulativeSum<i64> cum(a);\n\n    FoldLR<i64> fold(all(a), 0, [](i64 x1, i64\
    \ x2) { return x1 + x2; });\n\n    while (Q--) {\n        int l, r;\n        std::cin\
    \ >> l >> r;\n\n        const auto ans1 = cum.sum(l, r);\n        const auto ans2\
    \ = fold.foldL(r) - fold.foldL(l);\n        const auto ans3 = fold.foldR(l) -\
    \ fold.foldR(r);\n\n        assert(ans2 == ans1);\n        assert(ans3 == ans1);\n\
    \n        println(ans1);\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <cassert>\n#include <iostream>\n#include <vector>\n\n#include \"../../Data-Structure/Range-Accumulate/cumulative-sum.hpp\"\
    \n#include \"../../Data-Structure/Range-Accumulate/foldLR.hpp\"\n\n#include \"\
    ../../Util/IO/println.hpp\"\n#include \"../../Util/IO/read.hpp\"\n#include \"\
    ../../Util/int-alias.hpp\"\n#include \"../../Util/all-macro.hpp\"\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n\n    auto a = read<int>(N);\n\n    CumulativeSum<i64>\
    \ cum(a);\n\n    FoldLR<i64> fold(all(a), 0, [](i64 x1, i64 x2) { return x1 +\
    \ x2; });\n\n    while (Q--) {\n        int l, r;\n        std::cin >> l >> r;\n\
    \n        const auto ans1 = cum.sum(l, r);\n        const auto ans2 = fold.foldL(r)\
    \ - fold.foldL(l);\n        const auto ans3 = fold.foldR(l) - fold.foldR(r);\n\
    \n        assert(ans2 == ans1);\n        assert(ans3 == ans1);\n\n        println(ans1);\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn:
  - Data-Structure/Range-Accumulate/cumulative-sum.hpp
  - Data-Structure/Range-Accumulate/foldLR.hpp
  - Util/IO/println.hpp
  - Util/IO/read.hpp
  - Util/int-alias.hpp
  - Util/all-macro.hpp
  isVerificationFile: false
  path: test/yosupo/static-range-sum.cpp
  requiredBy: []
  timestamp: '2020-10-10 05:48:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/static-range-sum.cpp
layout: document
redirect_from:
- /library/test/yosupo/static-range-sum.cpp
- /library/test/yosupo/static-range-sum.cpp.html
title: test/yosupo/static-range-sum.cpp
---
