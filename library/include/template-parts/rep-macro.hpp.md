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


# :heavy_check_mark: repマクロ <small>(include/template-parts/rep-macro.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d5567e78d3674558c180d2f4feaa863b">include/template-parts</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/template-parts/rep-macro.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 11:03:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/DSL_1_A.test.cpp.html">test/DSL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @brief repマクロ
 */
#define rep(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i < (t); ++i)
#define repc(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i <= (t); ++i)
#define repr(i, t, s) for (i64 i = i64(t); i >= i64(s); --i)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "include/template-parts/rep-macro.hpp"

/**
 * @brief repマクロ
 */
#define rep(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i < (t); ++i)
#define repc(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i <= (t); ++i)
#define repr(i, t, s) for (i64 i = i64(t); i >= i64(s); --i)

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

