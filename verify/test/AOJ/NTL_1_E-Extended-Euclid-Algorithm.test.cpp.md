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


# :heavy_check_mark: test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dada0dcc232b029913f2cd4354c73c4b">test/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 11:30:43+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Math/Number-Theory/extgcd.hpp.html">extgcd() (拡張ユークリッドの互除法) <small>(Math/Number-Theory/extgcd.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/Util/int-alias.hpp.html">int-alias (整数型のエイリアス) <small>(Util/int-alias.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>

#include "../../Math/Number-Theory/extgcd.hpp"
#include "../../Util/int-alias.hpp"

int main() {
    i64 a, b, x, y;
    std::cin >> a >> b;
    extgcd(a, b, x, y);
    std::cout << x << ' ' << y << std::endl;

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>

#line 2 "Math/Number-Theory/extgcd.hpp"

/**
 * @brief extgcd() (拡張ユークリッドの互除法)
 */
// ax + by = gcd(a, b) の整数解 (x, y) を求める
template <class T>
T extgcd(T a, T b, T& x, T& y) {
    T g = a;
    if (b != 0) {
        g = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return g;
}
#line 2 "Util/int-alias.hpp"
#include <cstdint>

/**
 * @brief int-alias (整数型のエイリアス)
 */
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;
#line 7 "test/AOJ/NTL_1_E-Extended-Euclid-Algorithm.test.cpp"

int main() {
    i64 a, b, x, y;
    std::cin >> a >> b;
    extgcd(a, b, x, y);
    std::cout << x << ' ' << y << std::endl;

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

