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


# :heavy_check_mark: test/AOJ/0264-Finite-Field-Calculator.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dada0dcc232b029913f2cd4354c73c4b">test/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/AOJ/0264-Finite-Field-Calculator.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:55:20+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Math/Modulo/mod-int.hpp.html">Mod-Int (コンパイル時mod型と実行時mod型) <small>(Math/Modulo/mod-int.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/Util/int-alias.hpp.html">int-alias (整数型のエイリアス) <small>(Util/int-alias.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#"
#include <cassert>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "../../Math/Modulo/mod-int.hpp"

using namespace std;
using Mint = DynamicModInt<0>;
using Itr = string::const_iterator;

Mint expr(Itr&);
Mint term(Itr&);
Mint factor(Itr&);
Mint number(Itr&);

Mint expr(Itr& p) {
    Mint res = term(p);
    while (*p == '+' || *p == '-') {
        if (*p == '+') {
            res += term(++p);
        } else {
            res -= term(++p);
        }
    }
    return res;
}

Mint term(Itr& p) {
    Mint res = factor(p);
    while (*p == '*' || *p == '/') {
        if (*p == '*') {
            res *= factor(++p);
        } else {
            const auto v = factor(++p);
            if (v == 0) throw std::runtime_error("Divide by zero");
            res /= v;
        }
    }
    return res;
}

Mint factor(Itr& p) {
    if (*p == '(') {
        const auto res = expr(++p);
        assert(*p == ')');
        ++p;
        return res;
    }
    assert(isdigit(*p));
    return number(p);
}

Mint number(Itr& p) {
    int res = 0;
    while (isdigit(*p)) {
        res = res * 10 + (*p - '0');
        ++p;
    }
    return Mint::raw(res);
}

string removeSpace(const char* s) {
    string res;
    res.reserve(100010);

    istringstream iss(s);
    string part;
    while (iss >> part) res += move(part);

    return res;
}

int main() {
    static char line[100100];

    int p;
    while (scanf(" %d :", &p), p) {
        Mint::setMod(p);

        fgets(line, sizeof(line), stdin);
        const string s = removeSpace(line);

        try {
            Itr itr = s.cbegin();
            auto ans = expr(itr);
            printf("%s = %d (mod %ld)\n", s.c_str(), int(ans), Mint::mod());
        } catch (const std::runtime_error& e) {
            puts("NG");
        }
    }

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/AOJ/0264-Finite-Field-Calculator.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0264&lang=ja#"
#include <cassert>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#line 3 "Math/Modulo/mod-int.hpp"
#include <iostream>
#include <limits>
#line 2 "Util/int-alias.hpp"
#include <cstdint>

/**
 * @brief int-alias (整数型のエイリアス)
 */
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;
#line 6 "Math/Modulo/mod-int.hpp"

/**
 * @brief Mod-Int (コンパイル時mod型と実行時mod型)
 */
namespace impl {

template <class ModHolder>
class ModInt {
private:
    i64 value;

public:
    constexpr ModInt()
        : value(0) {}
    constexpr ModInt(i64 v)
        : value(ModInt::normalized(v)) {}

    static constexpr ModInt raw(i64 v) {
        ModInt ret;
        ret.value = v;
        return ret;
    }

    static constexpr ModInt nullopt = ModInt::raw(std::numeric_limits<i64>::min());

    constexpr bool isNull() const { return *this == ModInt::nullopt; }

    static constexpr i64 mod() { return ModHolder::mod; }

    static i64 setMod(i64 m) { return ModHolder::mod = m; }

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

template <i64 Mod>
struct StaticModHolder {
    static constexpr i64 mod = Mod;
};

template <auto ID>
struct DynamicModHolder {
    static i64 mod;
};
template <auto ID>
i64 DynamicModHolder<ID>::mod;

}  // namespace impl

template <i64 Mod>
using StaticModInt = impl::ModInt<impl::StaticModHolder<Mod>>;

template <auto ID>
using DynamicModInt = impl::ModInt<impl::DynamicModHolder<ID>>;
#line 11 "test/AOJ/0264-Finite-Field-Calculator.test.cpp"

using namespace std;
using Mint = DynamicModInt<0>;
using Itr = string::const_iterator;

Mint expr(Itr&);
Mint term(Itr&);
Mint factor(Itr&);
Mint number(Itr&);

Mint expr(Itr& p) {
    Mint res = term(p);
    while (*p == '+' || *p == '-') {
        if (*p == '+') {
            res += term(++p);
        } else {
            res -= term(++p);
        }
    }
    return res;
}

Mint term(Itr& p) {
    Mint res = factor(p);
    while (*p == '*' || *p == '/') {
        if (*p == '*') {
            res *= factor(++p);
        } else {
            const auto v = factor(++p);
            if (v == 0) throw std::runtime_error("Divide by zero");
            res /= v;
        }
    }
    return res;
}

Mint factor(Itr& p) {
    if (*p == '(') {
        const auto res = expr(++p);
        assert(*p == ')');
        ++p;
        return res;
    }
    assert(isdigit(*p));
    return number(p);
}

Mint number(Itr& p) {
    int res = 0;
    while (isdigit(*p)) {
        res = res * 10 + (*p - '0');
        ++p;
    }
    return Mint::raw(res);
}

string removeSpace(const char* s) {
    string res;
    res.reserve(100010);

    istringstream iss(s);
    string part;
    while (iss >> part) res += move(part);

    return res;
}

int main() {
    static char line[100100];

    int p;
    while (scanf(" %d :", &p), p) {
        Mint::setMod(p);

        fgets(line, sizeof(line), stdin);
        const string s = removeSpace(line);

        try {
            Itr itr = s.cbegin();
            auto ans = expr(itr);
            printf("%s = %d (mod %ld)\n", s.c_str(), int(ans), Mint::mod());
        } catch (const std::runtime_error& e) {
            puts("NG");
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

