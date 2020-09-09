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


# :heavy_check_mark: pow() (繰り返し二乗法) <small>(Algorithm/pow-doubling.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4afa80e77a07f7488ce4d1bdd8c4977a">Algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/Algorithm/pow-doubling.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 04:00:43+09:00




## Depends on

* :heavy_check_mark: <a href="../Util/int-alias.hpp.html">int-alias (整数型のエイリアス) <small>(Util/int-alias.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/AOJ/DPL_5_A.test.cpp.html">test/AOJ/DPL_5_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cmath>
#include "../Util/int-alias.hpp"

/**
 * @brief pow() (繰り返し二乗法)
 */
template <class Integer>
Integer pow(const Integer& n, const i64 expv) {
    Integer ret = 1, square = n;
    for (u64 p = std::abs(expv); p; p >>= 1) {
        if (p & 1) ret *= square;
        square *= square;
    }
    return (expv < 0) ? (1 / ret) : ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Algorithm/pow-doubling.hpp"
#include <cmath>
#line 2 "Util/int-alias.hpp"
#include <cstdint>

/**
 * @brief int-alias (整数型のエイリアス)
 */
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;
#line 4 "Algorithm/pow-doubling.hpp"

/**
 * @brief pow() (繰り返し二乗法)
 */
template <class Integer>
Integer pow(const Integer& n, const i64 expv) {
    Integer ret = 1, square = n;
    for (u64 p = std::abs(expv); p; p >>= 1) {
        if (p & 1) ret *= square;
        square *= square;
    }
    return (expv < 0) ? (1 / ret) : ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

