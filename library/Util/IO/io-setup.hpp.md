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


# :heavy_check_mark: ioSetup() (iostreamの高速化と実数出力の設定) <small>(Util/IO/io-setup.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a8d3eea1c7cba0485906562328c7d47">Util/IO</a>
* <a href="{{ site.github.repository_url }}/blob/master/Util/IO/io-setup.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 04:00:43+09:00




## Required by

* :warning: <a href="../../export/template-prototype.cpp.html">export/template-prototype.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp.html">test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/AOJ/DSL_1_A.test.cpp.html">test/AOJ/DSL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iomanip>
#include <iostream>

/**
 * @brief ioSetup() (iostreamの高速化と実数出力の設定)
 */
void ioSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(11);
    std::cerr << std::fixed << std::setprecision(11);
    std::clog << std::fixed << std::setprecision(11);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Util/IO/io-setup.hpp"
#include <iomanip>
#include <iostream>

/**
 * @brief ioSetup() (iostreamの高速化と実数出力の設定)
 */
void ioSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(11);
    std::cerr << std::fixed << std::setprecision(11);
    std::clog << std::fixed << std::setprecision(11);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

