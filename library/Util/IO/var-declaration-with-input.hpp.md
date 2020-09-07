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


# :warning: 複数変数宣言をして同時に入力もするやつ <small>(Util/IO/var-declaration-with-input.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a8d3eea1c7cba0485906562328c7d47">Util/IO</a>
* <a href="{{ site.github.repository_url }}/blob/master/Util/IO/var-declaration-with-input.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 04:00:43+09:00




## Required by

* :warning: <a href="../../export/template-prototype.cpp.html">export/template-prototype.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>

/**
 * @brief 複数変数宣言をして同時に入力もするやつ
 */
template <class T>
std::istream& operator,(std::istream& is, T& rhs) {
    return is >> rhs;
}

#define var(type, ...) \
    type __VA_ARGS__;  \
    std::cin >> __VA_ARGS__

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Util/IO/var-declaration-with-input.hpp"
#include <iostream>

/**
 * @brief 複数変数宣言をして同時に入力もするやつ
 */
template <class T>
std::istream& operator,(std::istream& is, T& rhs) {
    return is >> rhs;
}

#define var(type, ...) \
    type __VA_ARGS__;  \
    std::cin >> __VA_ARGS__

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

