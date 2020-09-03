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


# :warning: 型エイリアス <small>(include/template-parts/type-alias.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d5567e78d3674558c180d2f4feaa863b">include/template-parts</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/template-parts/type-alias.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 11:03:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <functional>
#include <limits>
#include <queue>
#include <vector>

/**
 * @brief 型エイリアス
 */
using i64 = int64_t;
using u64 = uint64_t;
using usize = size_t;
using ld = long double;
template <class T>
using MaxHeap = std::priority_queue<T, std::vector<T>>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "include/template-parts/type-alias.hpp"
#include <cstdint>
#include <functional>
#include <limits>
#include <queue>
#include <vector>

/**
 * @brief 型エイリアス
 */
using i64 = int64_t;
using u64 = uint64_t;
using usize = size_t;
using ld = long double;
template <class T>
using MaxHeap = std::priority_queue<T, std::vector<T>>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

