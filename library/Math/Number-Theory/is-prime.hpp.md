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


# :warning: isPrime() (素数判定 $O(\sqrt n)$) <small>(Math/Number-Theory/is-prime.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#4def0f0d6848bdd7ffa44d10031ae87a">Math/Number-Theory</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Number-Theory/is-prime.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 11:30:43+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>

/**
 * @brief isPrime() (素数判定 $O(\sqrt n)$)
 */
bool isPrime(int64_t n) {
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;
    for (int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Math/Number-Theory/is-prime.hpp"
#include <cstdint>

/**
 * @brief isPrime() (素数判定 $O(\sqrt n)$)
 */
bool isPrime(int64_t n) {
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;
    for (int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

