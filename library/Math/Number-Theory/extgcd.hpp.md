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


# :heavy_check_mark: extgcd() (拡張ユークリッドの互除法) <small>(Math/Number-Theory/extgcd.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#4def0f0d6848bdd7ffa44d10031ae87a">Math/Number-Theory</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Number-Theory/extgcd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 11:30:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp.html">test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @brief extgcd() (拡張ユークリッドの互除法)
 */
// ax + by = gcd(a, b) の整数解 (x, y) を求める
template <class T>
T extgcd(T a, T b, T& x, T& y) {
    T g = a;
    if (b != 0) {
        g = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return g;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Math/Number-Theory/extgcd.hpp"

/**
 * @brief extgcd() (拡張ユークリッドの互除法)
 */
// ax + by = gcd(a, b) の整数解 (x, y) を求める
template <class T>
T extgcd(T a, T b, T& x, T& y) {
    T g = a;
    if (b != 0) {
        g = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return g;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

