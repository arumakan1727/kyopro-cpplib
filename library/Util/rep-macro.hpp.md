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


# :warning: rep()マクロ <small>(Util/rep-macro.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#23e8a4b4f7cc1898ef12b4e6e48852bb">Util</a>
* <a href="{{ site.github.repository_url }}/blob/master/Util/rep-macro.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 04:00:43+09:00




## Required by

* :warning: <a href="../export/template-prototype.cpp.html">export/template-prototype.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @brief rep()マクロ
 */
#define rep(i, begin, end) for (int64_t i{begin}, i##_end{end}; i < i##_end; ++i)
#define repc(i, begin, last) for (int64_t i{begin}, i##_last{last}; i <= i##_last; ++i)
#define repr(i, begin, last) for (int64_t i{begin}, i##_last{last}; i >= i##_last; --i)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Util/rep-macro.hpp"

/**
 * @brief rep()マクロ
 */
#define rep(i, begin, end) for (int64_t i{begin}, i##_end{end}; i < i##_end; ++i)
#define repc(i, begin, last) for (int64_t i{begin}, i##_last{last}; i <= i##_last; ++i)
#define repr(i, begin, last) for (int64_t i{begin}, i##_last{last}; i >= i##_last; --i)

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

