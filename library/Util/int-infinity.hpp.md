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


# :warning: int-infinity (整数のデカイ値) <small>(Util/int-infinity.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#23e8a4b4f7cc1898ef12b4e6e48852bb">Util</a>
* <a href="{{ site.github.repository_url }}/blob/master/Util/int-infinity.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 10:56:20+09:00




## Required by

* :warning: <a href="Debug/debug.hpp.html">Debug <small>(Util/Debug/debug.hpp)</small></a>
* :warning: <a href="../export/template-prototype.cpp.html">export/template-prototype.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <limits>
#include <type_traits>

/**
 * @brief int-infinity (整数のデカイ値)
 * 2倍してもオーバーフローしない & memset()にも使える (需要ある？)
 */
constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 4, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return INF;
}

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 8, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return LINF;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Util/int-infinity.hpp"
#include <cstdint>
#include <limits>
#include <type_traits>

/**
 * @brief int-infinity (整数のデカイ値)
 * 2倍してもオーバーフローしない & memset()にも使える (需要ある？)
 */
constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 4, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return INF;
}

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 8, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return LINF;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

