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


# :warning: export/template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b2507468f95156358fa490fd543ad2f0">export</a>
* <a href="{{ site.github.repository_url }}/blob/master/export/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 04:00:43+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

#if 1  // {{{

#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#define rep(i, begin, end) for (int64_t i{begin}, i##_end{end}; i < i##_end; ++i)
#define repc(i, begin, last) for (int64_t i{begin}, i##_last{last}; i <= i##_last; ++i)
#define repr(i, begin, last) for (int64_t i{begin}, i##_last{last}; i >= i##_last; --i)

#define let const auto
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;

constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

void ioSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(11);
    std::cerr << std::fixed << std::setprecision(11);
    std::clog << std::fixed << std::setprecision(11);
}

template <class T>
std::istream& operator,(std::istream& is, T& rhs) {
    return is >> rhs;
}

#define var(type, ...) \
    type __VA_ARGS__;  \
    std::cin >> __VA_ARGS__

inline void println() {
    std::cout << '\n';
}
template <class Head, class... Tail>
inline void println(Head&& head, Tail&&... tail) {
    std::cout << head << " " + (!sizeof...(tail));
    println(std::forward<Tail>(tail)...);
}

template <class Container,
          class Value = typename Container::value_type,
          std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::istream& operator>>(std::istream& is, Container& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <class Container,
          class Value = typename Container::value_type,
          std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& v) {
    for (auto it = std::begin(v); it != std::end(v); ++it) os << " " + (it == std::begin(v)) << *it;
    return os;
}

template <class InputItr>
void join(std::ostream& os, InputItr begin, InputItr end, const char* delim, const char* last = "\n") {
    const char* tmp[] = {delim, ""};
    for (auto it = begin; it != end; ++it) os << tmp[it == begin] << *it;
    os << last;
}

template <class T>
inline void bye(const T& x) {
    std::cout << x << '\n', exit(0);
}

template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return b < a && (a = b, true);
}

template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return b > a && (a = b, true);
}

inline int64_t divceil(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

#endif  // }}}

// constexpr int MOD = int(1e9) + 7;
// constexpr int MOD = 998244353;

signed main() {
    ioSetup();

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "export/template.cpp"
#include <bits/stdc++.h>
using namespace std;

#if 1  // {{{

#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#define rep(i, begin, end) for (int64_t i{begin}, i##_end{end}; i < i##_end; ++i)
#define repc(i, begin, last) for (int64_t i{begin}, i##_last{last}; i <= i##_last; ++i)
#define repr(i, begin, last) for (int64_t i{begin}, i##_last{last}; i >= i##_last; --i)

#define let const auto
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;

constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

void ioSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(11);
    std::cerr << std::fixed << std::setprecision(11);
    std::clog << std::fixed << std::setprecision(11);
}

template <class T>
std::istream& operator,(std::istream& is, T& rhs) {
    return is >> rhs;
}

#define var(type, ...) \
    type __VA_ARGS__;  \
    std::cin >> __VA_ARGS__

inline void println() {
    std::cout << '\n';
}
template <class Head, class... Tail>
inline void println(Head&& head, Tail&&... tail) {
    std::cout << head << " " + (!sizeof...(tail));
    println(std::forward<Tail>(tail)...);
}

template <class Container,
          class Value = typename Container::value_type,
          std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::istream& operator>>(std::istream& is, Container& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <class Container,
          class Value = typename Container::value_type,
          std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& v) {
    for (auto it = std::begin(v); it != std::end(v); ++it) os << " " + (it == std::begin(v)) << *it;
    return os;
}

template <class InputItr>
void join(std::ostream& os, InputItr begin, InputItr end, const char* delim, const char* last = "\n") {
    const char* tmp[] = {delim, ""};
    for (auto it = begin; it != end; ++it) os << tmp[it == begin] << *it;
    os << last;
}

template <class T>
inline void bye(const T& x) {
    std::cout << x << '\n', exit(0);
}

template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return b < a && (a = b, true);
}

template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return b > a && (a = b, true);
}

inline int64_t divceil(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}

#endif  // }}}

// constexpr int MOD = int(1e9) + 7;
// constexpr int MOD = 998244353;

signed main() {
    ioSetup();

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

