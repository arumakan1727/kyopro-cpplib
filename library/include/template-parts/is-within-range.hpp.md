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


# :warning: within() (半開区間内に含まれているかの判定) <small>(include/template-parts/is-within-range.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d5567e78d3674558c180d2f4feaa863b">include/template-parts</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/template-parts/is-within-range.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 19:19:20+09:00




## Required by

* :warning: <a href="template.cpp.html">include/template-parts/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @brief within() (半開区間内に含まれているかの判定)
 */
template <class Value, class ValueBegin, class ValueEnd>
inline bool within(const Value& v, const ValueBegin& begin, const ValueEnd& end) {
    return begin <= v && v < end;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "include/template-parts/is-within-range.hpp"

/**
 * @brief within() (半開区間内に含まれているかの判定)
 */
template <class Value, class ValueBegin, class ValueEnd>
inline bool within(const Value& v, const ValueBegin& begin, const ValueEnd& end) {
    return begin <= v && v < end;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

