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


# :heavy_check_mark: Compile-Time-Mod-Holder (コンパイル時modを保持する型) <small>(Math/Modulo/compile-time-mod-holder.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ee048ce79e556b7fa2b3b7d2fb796245">Math/Modulo</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Modulo/compile-time-mod-holder.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 04:00:43+09:00




## Depends on

* :heavy_check_mark: <a href="../../Util/int-alias.hpp.html">int-alias (整数型のエイリアス) <small>(Util/int-alias.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/DPL_5_A.test.cpp.html">test/DPL_5_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../../Util/int-alias.hpp"

/**
 * @brief Compile-Time-Mod-Holder (コンパイル時modを保持する型)
 *
 * ModInt のテンプレートパラメータに渡して使う。
 */
template <i64 Mod>
struct CompileTimeModHolder {
    static constexpr i64 mod = Mod;
};

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
#line 3 "Math/Modulo/compile-time-mod-holder.hpp"

/**
 * @brief Compile-Time-Mod-Holder (コンパイル時modを保持する型)
 *
 * ModInt のテンプレートパラメータに渡して使う。
 */
template <i64 Mod>
struct CompileTimeModHolder {
    static constexpr i64 mod = Mod;
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

