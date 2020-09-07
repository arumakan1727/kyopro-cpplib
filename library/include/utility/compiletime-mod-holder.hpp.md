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


# :heavy_check_mark: Compiletime Mod Holder (コンパイル時modを保持する型) <small>(include/utility/compiletime-mod-holder.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ce9b21bbcd79b0c5e05b6d6a43e6fbc8">include/utility</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/utility/compiletime-mod-holder.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 12:59:37+09:00




## Depends on

* :heavy_check_mark: <a href="../template-parts/type-alias.hpp.html">型エイリアス <small>(include/template-parts/type-alias.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/DPL_5_A.test.cpp.html">test/DPL_5_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../template-parts/type-alias.hpp"

/**
 * @brief Compiletime Mod Holder (コンパイル時modを保持する型)
 *
 * ModInt のテンプレートパラメータに渡して使う。
 */
template <i64 Mod>
struct CompiletimeModHolder {
    static constexpr i64 mod = Mod;
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "include/template-parts/type-alias.hpp"
#include <cstdint>
#include <functional>
#include <queue>
#include <vector>

/**
 * @brief 型エイリアス
 */
#define let const auto
using i64 = int64_t;
using u64 = uint64_t;
using usize = size_t;
template <class T>
using MaxHeap = std::priority_queue<T, std::vector<T>>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 3 "include/utility/compiletime-mod-holder.hpp"

/**
 * @brief Compiletime Mod Holder (コンパイル時modを保持する型)
 *
 * ModInt のテンプレートパラメータに渡して使う。
 */
template <i64 Mod>
struct CompiletimeModHolder {
    static constexpr i64 mod = Mod;
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

