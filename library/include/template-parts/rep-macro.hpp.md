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


# :heavy_check_mark: rep()マクロ <small>(include/template-parts/rep-macro.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d5567e78d3674558c180d2f4feaa863b">include/template-parts</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/template-parts/rep-macro.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 19:19:20+09:00




## Required by

* :warning: <a href="template.cpp.html">include/template-parts/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/DSL_1_A.test.cpp.html">test/DSL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @brief rep()マクロ
 */
#define rep2(i, n) for (size_t i = 0; i < (n); ++i)
#define rep3(i, s, e) for (int64_t i = int64_t(s); i < int64_t(e); ++i)
#define GET_4TH_ARG(dummy1, dummy2, dummy3, NAME, ...) NAME
#define rep(...) GET_4TH_ARG(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define repc(i, s, t) for (int64_t i = int64_t(s); i <= int64_t(t); ++i)
#define repr(i, s, t) for (int64_t i = int64_t(s); i >= int64_t(t); --i)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "include/template-parts/rep-macro.hpp"

/**
 * @brief rep()マクロ
 */
#define rep2(i, n) for (size_t i = 0; i < (n); ++i)
#define rep3(i, s, e) for (int64_t i = int64_t(s); i < int64_t(e); ++i)
#define GET_4TH_ARG(dummy1, dummy2, dummy3, NAME, ...) NAME
#define rep(...) GET_4TH_ARG(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define repc(i, s, t) for (int64_t i = int64_t(s); i <= int64_t(t); ++i)
#define repr(i, s, t) for (int64_t i = int64_t(s); i >= int64_t(t); --i)

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

