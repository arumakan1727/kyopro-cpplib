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


# :warning: tuple の出力 <small>(include/template-parts/tuple-print.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d5567e78d3674558c180d2f4feaa863b">include/template-parts</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/template-parts/tuple-print.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 11:03:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>
#include <iostream>
#include <tuple>
#include <utility>

/**
 * @brief tuple の出力
 */
template <class Tuple, size_t... I>
std::array<int, sizeof...(I)> tuple_print_impl(std::ostream &os, Tuple &&t, std::index_sequence<I...>) {
    return {{(void(os << (I == 0 ? "" : ", ") << std::get<I>(t)), 0)...}};
}

template <class Tuple, class Value = typename std::tuple_element_t<0, Tuple>>
std::ostream &operator<<(std::ostream &os, Tuple &&t) {
    os << '{';
    tuple_print_impl(os, std::forward<Tuple>(t), std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
    return os << '}';
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "include/template-parts/tuple-print.hpp"
#include <array>
#include <iostream>
#include <tuple>
#include <utility>

/**
 * @brief tuple の出力
 */
template <class Tuple, size_t... I>
std::array<int, sizeof...(I)> tuple_print_impl(std::ostream &os, Tuple &&t, std::index_sequence<I...>) {
    return {{(void(os << (I == 0 ? "" : ", ") << std::get<I>(t)), 0)...}};
}

template <class Tuple, class Value = typename std::tuple_element_t<0, Tuple>>
std::ostream &operator<<(std::ostream &os, Tuple &&t) {
    os << '{';
    tuple_print_impl(os, std::forward<Tuple>(t), std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
    return os << '}';
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

