---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: test/DSL_1_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/DSL_1_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-03 10:58:01+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/include/data-structure/union-find.hpp.html">Union-Find (素集合データ構造) <small>(include/data-structure/union-find.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/include/template-parts/io-setup.hpp.html">iostream の高速化 <small>(include/template-parts/io-setup.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/include/template-parts/rep-macro.hpp.html">repマクロ <small>(include/template-parts/rep-macro.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include <bits/stdc++.h>

#include "../include/data-structure/union-find.hpp"
#include "../include/template-parts/io-setup.hpp"
#include "../include/template-parts/rep-macro.hpp"
using namespace std;

int main() {
    ioSetup();
    constexpr char LF = '\n';

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << uf.same(x, y) << LF;
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/DSL_1_A.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include <bits/stdc++.h>

#line 5 "include/data-structure/union-find.hpp"

/**
 * @brief Union-Find (素集合データ構造)
 * @note path-compression + union-by-size
 */
struct UnionFind {
    mutable std::vector<int> p;

    UnionFind() = default;
    explicit UnionFind(size_t n) : p(n, -1) {}

    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (p[y] < p[x]) std::swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return true;
    }

    int root(int x) const {
        if (p[x] < 0) return x;
        return p[x] = root(p[x]);
    }

    bool same(int x, int y) const {
        return root(x) == root(y);
    }

    int size(int x) const {
        return -p[root(x)];
    }
};
#line 4 "include/template-parts/io-setup.hpp"

/**
 * @brief iostream の高速化
 */
void ioSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(11);
    std::cerr << std::fixed << std::setprecision(11);
    std::clog << std::fixed << std::setprecision(11);
}
#line 2 "include/template-parts/rep-macro.hpp"

/**
 * @brief repマクロ
 */
#define rep(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i < (t); ++i)
#define repc(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i <= (t); ++i)
#define repr(i, t, s) for (i64 i = i64(t); i >= i64(s); --i)
#line 7 "test/DSL_1_A.test.cpp"
using namespace std;

int main() {
    ioSetup();
    constexpr char LF = '\n';

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << uf.same(x, y) << LF;
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
