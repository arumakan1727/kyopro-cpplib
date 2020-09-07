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


# :heavy_check_mark: pow() (繰り返し二乗法) <small>(include/math/pow-doubling.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b9ef8917edb15b1d9148383038c25f58">include/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/math/pow-doubling.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 12:59:37+09:00




## Depends on

* :heavy_check_mark: <a href="../template-parts/type-alias.hpp.html">型エイリアス <small>(include/template-parts/type-alias.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/DPL_5_A.test.cpp.html">test/DPL_5_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cmath>
#include "../template-parts/type-alias.hpp"

/**
 * @brief pow() (繰り返し二乗法)
 */
template <class Integer>
Integer pow(const Integer& n, const i64 exp) {
    Integer ret = 1, square = n;
    for (u64 p = std::abs(exp); p; p >>= 1) {
        if (p & 1) ret *= square;
        square *= square;
    }
    return (exp < 0) ? (1 / ret) : ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "include/math/pow-doubling.hpp"
#include <cmath>
#line 2 "include/template-parts/type-alias.hpp"
#include <cstdint>
#include <functional>
#include <queue>
#include <vector>

/**
 * @brief 型エイリアス
 */
#define let const auto
using i64 = int64_t;
using u64 = uint64_t;
using usize = size_t;
template <class T>
using MaxHeap = std::priority_queue<T, std::vector<T>>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 4 "include/math/pow-doubling.hpp"

/**
 * @brief pow() (繰り返し二乗法)
 */
template <class Integer>
Integer pow(const Integer& n, const i64 exp) {
    Integer ret = 1, square = n;
    for (u64 p = std::abs(exp); p; p >>= 1) {
        if (p & 1) ret *= square;
        square *= square;
    }
    return (exp < 0) ? (1 / ret) : ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

