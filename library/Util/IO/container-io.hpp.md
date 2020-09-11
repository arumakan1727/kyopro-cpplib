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


# :warning: コンテナの入出力 <small>(Util/IO/container-io.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a8d3eea1c7cba0485906562328c7d47">Util/IO</a>
* <a href="{{ site.github.repository_url }}/blob/master/Util/IO/container-io.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 10:56:20+09:00




## Required by

* :warning: <a href="../../export/template-prototype.cpp.html">export/template-prototype.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>

/**
 * @brief コンテナの入出力
 */
template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container, std::string>, std::nullptr_t> = nullptr>
std::istream& operator>>(std::istream& is, Container& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container, std::string>, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& v) {
    for (auto it = std::begin(v); it != std::end(v); ++it) os << " " + (it == std::begin(v)) << *it;
    return os;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Util/IO/container-io.hpp"
#include <iostream>

/**
 * @brief コンテナの入出力
 */
template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container, std::string>, std::nullptr_t> = nullptr>
std::istream& operator>>(std::istream& is, Container& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container, std::string>, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& v) {
    for (auto it = std::begin(v); it != std::end(v); ++it) os << " " + (it == std::begin(v)) << *it;
    return os;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

