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


# :heavy_check_mark: test/AOJ/NTL_1_B-Power.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dada0dcc232b029913f2cd4354c73c4b">test/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/AOJ/NTL_1_B-Power.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 19:39:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Algorithm/pow-doubling.hpp.html">pow() (繰り返し二乗法) <small>(Algorithm/pow-doubling.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/Math/Modulo/mod-int.hpp.html">Mod-Int (コンパイル時mod型と実行時mod型) <small>(Math/Modulo/mod-int.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/Util/int-alias.hpp.html">int-alias (整数型のエイリアス) <small>(Util/int-alias.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <iostream>

#include "../../Math/Modulo/mod-int.hpp"
#include "../../Algorithm/pow-doubling.hpp"

int main() {
    using Mint = StaticModInt<int(1e9) + 7>;

    Mint m;
    int n;
    std::cin >> m >> n;
    std::cout << pow(m, n) << std::endl;

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/AOJ/NTL_1_B-Power.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <iostream>

#line 2 "Math/Modulo/mod-int.hpp"
#include <cstdint>
#include <cassert>
#line 5 "Math/Modulo/mod-int.hpp"
#include <limits>

/**
 * @brief Mod-Int (コンパイル時mod型と実行時mod型)
 */
namespace impl {

template <class ModHolder>
class ModInt {
private:
    int64_t value;

public:
    constexpr ModInt()
        : value(0) {}
    constexpr ModInt(int64_t v)
        : value(ModInt::normalized(v)) {}

    static constexpr ModInt raw(int64_t v) {
        ModInt ret;
        ret.value = v;
        return ret;
    }

    static constexpr ModInt nullopt = ModInt::raw(std::numeric_limits<int64_t>::min());

    constexpr bool isNull() const { return *this == ModInt::nullopt; }

    static constexpr int64_t mod() { return ModHolder::mod; }

    static int64_t setMod(int64_t m) {
        assert(m >= 1);
        return ModHolder::mod = m;
    }

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

    constexpr const ModInt operator+() const { return *this; }
    constexpr const ModInt operator-() const { return ModInt(-value); }

    friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) { return lhs.value == rhs.value; }
    friend constexpr bool operator!=(const ModInt& lhs, const ModInt& rhs) { return lhs.value != rhs.value; }
    friend constexpr const ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
    friend constexpr const ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
    friend constexpr const ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
    friend constexpr const ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) {
#ifdef LOCAL_DEBUG
        if (x.isNull()) return os << "{nullopt}";
#endif
        return os << x.value;
    }

    friend std::istream& operator>>(std::istream& is, ModInt& x) {
        is >> x.value;
        x.value = ModInt::normalized(x.value);
        return is;
    }

private:
    static constexpr int64_t normalized(int64_t n) {
        n = (-mod() <= n && n < mod() ? n : n % mod());
        if (n < 0) n += mod();
        return n;
    }

    static constexpr int64_t inverse(int64_t a, int64_t m) {
        int64_t u = 0, v = 1;
        while (a != 0) {
            const auto t = m / a;
            m -= t * a, std::swap(m, a);
            u -= t * v, std::swap(u, v);
        }
        assert(m == 1);
        return u;
    }
};

template <int64_t Mod>
struct StaticModHolder {
    static constexpr int64_t mod = Mod;
};

template <auto ID>
struct DynamicModHolder {
    static int64_t mod;
};
template <auto ID>
int64_t DynamicModHolder<ID>::mod;

}  // namespace impl

template <int64_t Mod>
using StaticModInt = impl::ModInt<impl::StaticModHolder<Mod>>;

template <auto ID>
using DynamicModInt = impl::ModInt<impl::DynamicModHolder<ID>>;
#line 2 "Algorithm/pow-doubling.hpp"
#include <cmath>
#line 3 "Util/int-alias.hpp"

/**
 * @brief int-alias (整数型のエイリアス)
 */
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;
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
#line 7 "test/AOJ/NTL_1_B-Power.test.cpp"

int main() {
    using Mint = StaticModInt<int(1e9) + 7>;

    Mint m;
    int n;
    std::cin >> m >> n;
    std::cout << pow(m, n) << std::endl;

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

