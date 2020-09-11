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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Union-Find (素集合データ構造) <small>(Data-Structure/Disjoint-Set/union-find.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#510221fd93ed01153e9d07e085298835">Data-Structure/Disjoint-Set</a>
* <a href="{{ site.github.repository_url }}/blob/master/Data-Structure/Disjoint-Set/union-find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 10:57:57+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/AOJ/DSL_1_A.test.cpp.html">test/AOJ/DSL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <vector>

/**
 * @brief Union-Find (素集合データ構造)
 * @note path-compression + union-by-size
 */
class UnionFind {
private:
    int n;
    mutable std::vector<int> p;

public:
    UnionFind() = default;

    explicit UnionFind(int n_)
        : n(n_)
        , p(n_, -1) {}

    int unite(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        x = leader(x), y = leader(y);
        if (x == y) return x;
        if (p[y] < p[x]) std::swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return x;
    }

    int leader(int x) const {
        assert(0 <= x && x < n);
        if (p[x] < 0) return x;
        return p[x] = leader(p[x]);
    }

    bool same(int x, int y) const {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return leader(x) == leader(y);
    }

    int size(int x) const {
        assert(0 <= x && x < n);
        return -p[leader(x)];
    }

    std::vector<std::vector<int>> groups() const {
        std::vector<int> leaderBuf(n), groupSize(n);
        for (int i = 0; i < n; i++) ++groupSize[leaderBuf[i] = leader(i)];

        std::vector<std::vector<int>> result(n);
        for (int i = 0; i < n; i++) result[i].reserve(groupSize[i]);
        for (int i = 0; i < n; i++) result[leaderBuf[i]].push_back(i);
        result.erase(std::remove_if(result.begin(), result.end(), [&](const std::vector<int>& v) { return v.empty(); }), result.end());
        return result;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Data-Structure/Disjoint-Set/union-find.hpp"
#include <cassert>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <vector>

/**
 * @brief Union-Find (素集合データ構造)
 * @note path-compression + union-by-size
 */
class UnionFind {
private:
    int n;
    mutable std::vector<int> p;

public:
    UnionFind() = default;

    explicit UnionFind(int n_)
        : n(n_)
        , p(n_, -1) {}

    int unite(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        x = leader(x), y = leader(y);
        if (x == y) return x;
        if (p[y] < p[x]) std::swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return x;
    }

    int leader(int x) const {
        assert(0 <= x && x < n);
        if (p[x] < 0) return x;
        return p[x] = leader(p[x]);
    }

    bool same(int x, int y) const {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return leader(x) == leader(y);
    }

    int size(int x) const {
        assert(0 <= x && x < n);
        return -p[leader(x)];
    }

    std::vector<std::vector<int>> groups() const {
        std::vector<int> leaderBuf(n), groupSize(n);
        for (int i = 0; i < n; i++) ++groupSize[leaderBuf[i] = leader(i)];

        std::vector<std::vector<int>> result(n);
        for (int i = 0; i < n; i++) result[i].reserve(groupSize[i]);
        for (int i = 0; i < n; i++) result[leaderBuf[i]].push_back(i);
        result.erase(std::remove_if(result.begin(), result.end(), [&](const std::vector<int>& v) { return v.empty(); }), result.end());
        return result;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

