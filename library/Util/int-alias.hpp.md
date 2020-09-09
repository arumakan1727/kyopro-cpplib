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


# :question: int-alias (整数型のエイリアス) <small>(Util/int-alias.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#23e8a4b4f7cc1898ef12b4e6e48852bb">Util</a>
* <a href="{{ site.github.repository_url }}/blob/master/Util/int-alias.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 04:00:43+09:00




## Required by

* :heavy_check_mark: <a href="../Algorithm/pow-doubling.hpp.html">pow() (繰り返し二乗法) <small>(Algorithm/pow-doubling.hpp)</small></a>
* :question: <a href="../Math/Modulo/mod-int.hpp.html">Mod-Int (コンパイル時mod型と実行時mod型) <small>(Math/Modulo/mod-int.hpp)</small></a>
* :warning: <a href="../export/template-prototype.cpp.html">export/template-prototype.cpp</a>


## Verified with

* :x: <a href="../../verify/test/AOJ/0264-Finite-Field-Calculator.test.cpp.html">test/AOJ/0264-Finite-Field-Calculator.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/AOJ/DPL_5_A.test.cpp.html">test/AOJ/DPL_5_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>

/**
 * @brief int-alias (整数型のエイリアス)
 */
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Util/int-alias.hpp"
#include <cstdint>

/**
 * @brief int-alias (整数型のエイリアス)
 */
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

