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


# :heavy_check_mark: test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dada0dcc232b029913f2cd4354c73c4b">test/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 12:07:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Math/Number-Theory/is-prime.hpp.html">isPrime() (素数判定 $O(\sqrt n)$) <small>(Math/Number-Theory/is-prime.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/Util/IO/io-setup.hpp.html">ioSetup() (iostreamの高速化と実数出力の設定) <small>(Util/IO/io-setup.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>

#include "../../Math/Number-Theory/is-prime.hpp"
#include "../../Util/IO/io-setup.hpp"

int main() {
    ioSetup();

    int N;
    std::cin >> N;

    int ans = 0;
    while (N--) {
        int x;
        std::cin >> x;
        if (isPrime(x)) ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>

#line 2 "Math/Number-Theory/is-prime.hpp"
#include <cstdint>

/**
 * @brief isPrime() (素数判定 $O(\sqrt n)$)
 */
bool isPrime(int64_t n) {
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;
    for (int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
#line 2 "Util/IO/io-setup.hpp"
#include <iomanip>
#line 4 "Util/IO/io-setup.hpp"

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
#line 7 "test/AOJ/ALDS1_1_C-Prime-Numbers.test.cpp"

int main() {
    ioSetup();

    int N;
    std::cin >> N;

    int ans = 0;
    while (N--) {
        int x;
        std::cin >> x;
        if (isPrime(x)) ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

