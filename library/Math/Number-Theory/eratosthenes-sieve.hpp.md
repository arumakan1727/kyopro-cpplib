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


# :warning: Eratosthenes-Sieve (エラトステネスの篩) <small>(Math/Number-Theory/eratosthenes-sieve.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#4def0f0d6848bdd7ffa44d10031ae87a">Math/Number-Theory</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Number-Theory/eratosthenes-sieve.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 12:07:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <vector>
#include <numeric>

/**
 * @brief Eratosthenes-Sieve (エラトステネスの篩)
 */
class EratosthenesSieve {
private:
    int n_;
    std::vector<int> minFactor_;

public:
    EratosthenesSieve() = default;

    explicit EratosthenesSieve(int n)
        : n_(n)
        , minFactor_(n) {
        std::iota(minFactor_.begin(), minFactor_.end(), 0);
        for (int i = 2; i * i < n; ++i) {
            if (minFactor_[i] < i) continue;
            for (int j = i * i; j < n; j += i) {
                if (minFactor_[j] == j) minFactor_[j] = i;
            }
        }
        if (n >= 0) minFactor_[0] = -1;
        if (n >= 1) minFactor_[1] = -1;
    }

    bool isPrime(int x) const {
        assert(0 <= x && x < n_);
        return minFactor_[x] == x;
    }

    int minFactor(int x) const {
        assert(0 <= x && x < n_);
        return minFactor_[x];
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Math/Number-Theory/eratosthenes-sieve.hpp"
#include <cassert>
#include <vector>
#include <numeric>

/**
 * @brief Eratosthenes-Sieve (エラトステネスの篩)
 */
class EratosthenesSieve {
private:
    int n_;
    std::vector<int> minFactor_;

public:
    EratosthenesSieve() = default;

    explicit EratosthenesSieve(int n)
        : n_(n)
        , minFactor_(n) {
        std::iota(minFactor_.begin(), minFactor_.end(), 0);
        for (int i = 2; i * i < n; ++i) {
            if (minFactor_[i] < i) continue;
            for (int j = i * i; j < n; j += i) {
                if (minFactor_[j] == j) minFactor_[j] = i;
            }
        }
        if (n >= 0) minFactor_[0] = -1;
        if (n >= 1) minFactor_[1] = -1;
    }

    bool isPrime(int x) const {
        assert(0 <= x && x < n_);
        return minFactor_[x] == x;
    }

    int minFactor(int x) const {
        assert(0 <= x && x < n_);
        return minFactor_[x];
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

