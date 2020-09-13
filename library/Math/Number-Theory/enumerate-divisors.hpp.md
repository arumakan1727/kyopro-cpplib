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


# :warning: enumerateDivisors() (約数列挙) <small>(Math/Number-Theory/enumerate-divisors.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#4def0f0d6848bdd7ffa44d10031ae87a">Math/Number-Theory</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Number-Theory/enumerate-divisors.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 11:30:43+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <algorithm>
#include <vector>

/**
 * @brief enumerateDivisors() (約数列挙)
 */
template <class Integer>
std::vector<Integer> enumerateDivisors(Integer n) {
    std::vector<Integer> divisors;
    Integer i;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) divisors.push_back(i), divisors.push_back(n / i);
    }
    if (i * i == n) divisors.push_back(i);
    std::sort(divisors.begin(), divisors.end());
    return divisors;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Math/Number-Theory/enumerate-divisors.hpp"
#include <cstdint>
#include <algorithm>
#include <vector>

/**
 * @brief enumerateDivisors() (約数列挙)
 */
template <class Integer>
std::vector<Integer> enumerateDivisors(Integer n) {
    std::vector<Integer> divisors;
    Integer i;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) divisors.push_back(i), divisors.push_back(n / i);
    }
    if (i * i == n) divisors.push_back(i);
    std::sort(divisors.begin(), divisors.end());
    return divisors;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

