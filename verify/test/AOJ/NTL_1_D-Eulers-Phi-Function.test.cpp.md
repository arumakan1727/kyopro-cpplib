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


# :heavy_check_mark: test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dada0dcc232b029913f2cd4354c73c4b">test/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 11:30:43+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Math/Number-Theory/totient-func.hpp.html">totient() (オイラーのトーシェント関数) <small>(Math/Number-Theory/totient-func.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>

#include "../../Math/Number-Theory/totient-func.hpp"

int main() {
    int n;
    std::cin >> n;
    std::cout << totient(n) << std::endl;

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>

#line 2 "Math/Number-Theory/totient-func.hpp"

/**
 * @brief totient() (オイラーのトーシェント関数)
 */
template <class Integer>
Integer totient(Integer n) {
    Integer ret = n;
    for (Integer i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) ret -= ret / n;
    return ret;
}
#line 6 "test/AOJ/NTL_1_D-Eulers-Phi-Function.test.cpp"

int main() {
    int n;
    std::cin >> n;
    std::cout << totient(n) << std::endl;

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

