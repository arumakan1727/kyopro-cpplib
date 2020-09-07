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


# :heavy_check_mark: test/DPL_5_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/DPL_5_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 12:59:37+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/include/math/mod-int.hpp.html">ModInt (コンパイル時modと実行時mod両対応) <small>(include/math/mod-int.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/include/math/pow-doubling.hpp.html">pow() (繰り返し二乗法) <small>(include/math/pow-doubling.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/include/template-parts/println.hpp.html">println() (可変個の値を空白区切りで出力して改行する) <small>(include/template-parts/println.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/include/template-parts/type-alias.hpp.html">型エイリアス <small>(include/template-parts/type-alias.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/include/utility/compiletime-mod-holder.hpp.html">Compiletime Mod Holder (コンパイル時modを保持する型) <small>(include/utility/compiletime-mod-holder.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja"

#include <iostream>
#include <type_traits>

#include "../include/math/mod-int.hpp"
#include "../include/math/pow-doubling.hpp"
#include "../include/utility/compiletime-mod-holder.hpp"
#include "../include/template-parts/println.hpp"

int main() {
    using Mint = ModInt<CompiletimeModHolder<int(1e9) + 7>>;

    int n;
    std::cin >> n;

    Mint k;
    std::cin >> k;

    auto ans = pow(k, n);
    static_assert(std::is_same_v<decltype(ans), Mint>);

    println(pow(k, n));

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/DPL_5_A.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja"

#include <iostream>
#include <type_traits>

#line 2 "include/math/mod-int.hpp"
#include <cassert>
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
#line 5 "include/math/mod-int.hpp"

/**
 * @brief ModInt (コンパイル時modと実行時mod両対応)
 *
 * テンプレートパラメータの ModHolder は static フィールド `mod` を有する必要がある。
 * この `ModHolder::mod` が modulo 演算の法として用いられる。
 */
template <class ModHolder>
class ModInt {
private:
    i64 value;

public:
    constexpr ModInt()
        : value() {}
    constexpr ModInt(i64 v)
        : value(ModInt::normalized(v)) {}

    static constexpr i64 mod() { return ModHolder::mod; }

    template <class T>
    constexpr explicit operator T() const {
        return static_cast<T>(value);
    }
    constexpr ModInt& operator+=(const ModInt& rhs) {
        if ((value += rhs.value) >= mod()) value -= mod();
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& rhs) {
        if ((value -= rhs.value) < 0) value += mod();
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& rhs) {
        (value *= rhs.value) %= mod();
        return *this;
    }
    constexpr ModInt& operator/=(const ModInt& rhs) { return *this *= rhs.inv(); }

    constexpr const ModInt inv() const { return ModInt(ModInt::inverse(value, mod())); }

    constexpr const ModInt operator-() const { return ModInt(-value); }

    constexpr bool operator==(const ModInt& rhs) const { return value == rhs.value; }
    constexpr bool operator!=(const ModInt& rhs) const { return !(*this == rhs); }

    friend constexpr const ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
    friend constexpr const ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
    friend constexpr const ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
    friend constexpr const ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) { return os << x.value; }

    friend std::istream& operator>>(std::istream& is, ModInt& x) {
        is >> x.value;
        x.value = ModInt::normalized(x.value);
        return is;
    }

private:
    static constexpr i64 normalized(i64 n) {
        n = (-mod() <= n && n < mod() ? n : n % mod());
        if (n < 0) n += mod();
        return n;
    }

    static constexpr i64 inverse(i64 a, i64 m) {
        i64 u = 0, v = 1;
        while (a != 0) {
            const auto t = m / a;
            m -= t * a, std::swap(m, a);
            u -= t * v, std::swap(u, v);
        }
        assert(m == 1);
        return u;
    }
};
#line 2 "include/math/pow-doubling.hpp"
#include <cmath>
#line 4 "include/math/pow-doubling.hpp"

/**
 * @brief pow() (繰り返し二乗法)
 */
template <class Integer>
Integer pow(const Integer& n, const i64 exp) {
    Integer ret = 1, square = n;
    for (u64 p = std::abs(exp); p; p >>= 1) {
        if (p & 1) ret *= square;
        square *= square;
    }
    return (exp < 0) ? (1 / ret) : ret;
}
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
#line 3 "include/template-parts/println.hpp"
#include <utility>

/**
 * @brief println() (可変個の値を空白区切りで出力して改行する)
 */
inline void println() {
    std::cout << '\n';
}
template <class Head, class... Tail>
inline void println(Head&& head, Tail&&... tail) {
    std::cout << head << " " + (!sizeof...(tail));
    println(std::forward<Tail>(tail)...);
}
#line 10 "test/DPL_5_A.test.cpp"

int main() {
    using Mint = ModInt<CompiletimeModHolder<int(1e9) + 7>>;

    int n;
    std::cin >> n;

    Mint k;
    std::cin >> k;

    auto ans = pow(k, n);
    static_assert(std::is_same_v<decltype(ans), Mint>);

    println(pow(k, n));

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

