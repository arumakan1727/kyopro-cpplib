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
    - Last commit date: 2020-09-08 04:00:43+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Algorithm/pow-doubling.hpp.html">pow() (繰り返し二乗法) <small>(Algorithm/pow-doubling.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/Math/Modulo/compile-time-mod-holder.hpp.html">Compile-Time-Mod-Holder (コンパイル時modを保持する型) <small>(Math/Modulo/compile-time-mod-holder.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/Math/Modulo/mod-int.hpp.html">ModInt (コンパイル時modと実行時mod両対応) <small>(Math/Modulo/mod-int.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/Util/IO/println.hpp.html">println() (可変個の値を空白区切りで出力して改行する) <small>(Util/IO/println.hpp)</small></a>
* :heavy_check_mark: <a href="../../library/Util/int-alias.hpp.html">int-alias (整数型のエイリアス) <small>(Util/int-alias.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=ja"

#include <iostream>
#include <type_traits>

#include "../Math/Modulo/mod-int.hpp"
#include "../Math/Modulo/compile-time-mod-holder.hpp"
#include "../Algorithm/pow-doubling.hpp"
#include "../Util/IO/println.hpp"

int main() {
    using Mint = ModInt<CompileTimeModHolder<int(1e9) + 7>>;

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

#line 2 "Math/Modulo/mod-int.hpp"
#include <cassert>
#line 2 "Util/int-alias.hpp"
#include <cstdint>

/**
 * @brief int-alias (整数型のエイリアス)
 */
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;
#line 5 "Math/Modulo/mod-int.hpp"

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
        : value(0) {}
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
#line 2 "Algorithm/pow-doubling.hpp"
#include <cmath>
#line 4 "Algorithm/pow-doubling.hpp"

/**
 * @brief pow() (繰り返し二乗法)
 */
template <class Integer>
Integer pow(const Integer& n, const i64 expv) {
    Integer ret = 1, square = n;
    for (u64 p = std::abs(expv); p; p >>= 1) {
        if (p & 1) ret *= square;
        square *= square;
    }
    return (expv < 0) ? (1 / ret) : ret;
}
#line 3 "Util/IO/println.hpp"
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
    using Mint = ModInt<CompileTimeModHolder<int(1e9) + 7>>;

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

