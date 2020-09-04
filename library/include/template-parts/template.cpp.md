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


# :warning: include/template-parts/template.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d5567e78d3674558c180d2f4feaa863b">include/template-parts</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/template-parts/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 19:19:20+09:00




## Depends on

* :warning: <a href="all-macro.hpp.html">all()マクロ <small>(include/template-parts/all-macro.hpp)</small></a>
* :warning: <a href="bye.hpp.html">bye() (出力してexit(0)) <small>(include/template-parts/bye.hpp)</small></a>
* :warning: <a href="chminmax.hpp.html">chmin(), chmax() <small>(include/template-parts/chminmax.hpp)</small></a>
* :warning: <a href="constant.hpp.html">よく使う定数 <small>(include/template-parts/constant.hpp)</small></a>
* :warning: <a href="container-io.hpp.html">コンテナの入出力 <small>(include/template-parts/container-io.hpp)</small></a>
* :heavy_check_mark: <a href="io-setup.hpp.html">ioSetup() (iostreamの高速化と実数出力の設定) <small>(include/template-parts/io-setup.hpp)</small></a>
* :warning: <a href="is-within-range.hpp.html">within() (半開区間内に含まれているかの判定) <small>(include/template-parts/is-within-range.hpp)</small></a>
* :warning: <a href="join-into-ostream.hpp.html">join() (要素を区切り文字で結合して出力) <small>(include/template-parts/join-into-ostream.hpp)</small></a>
* :warning: <a href="makeVec.hpp.html">makeVec() (多次元std::vectorの生成) <small>(include/template-parts/makeVec.hpp)</small></a>
* :warning: <a href="println.hpp.html">println() (可変個の値を空白区切りで出力して改行する) <small>(include/template-parts/println.hpp)</small></a>
* :warning: <a href="rep-macro.hpp.html">rep()マクロ <small>(include/template-parts/rep-macro.hpp)</small></a>
* :warning: <a href="tuple-print.hpp.html">tupleの出力 <small>(include/template-parts/tuple-print.hpp)</small></a>
* :warning: <a href="type-alias.hpp.html">型エイリアス <small>(include/template-parts/type-alias.hpp)</small></a>
* :warning: <a href="var-declaration-with-input.hpp.html">複数変数宣言をして同時に入力もするやつ <small>(include/template-parts/var-declaration-with-input.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

#pragma region  // {{{

#include "./all-macro.hpp"
#include "./rep-macro.hpp"

#include "./type-alias.hpp"

#include "./io-setup.hpp"

#include "./var-declaration-with-input.hpp"

#include "./println.hpp"

#include "./container-io.hpp"

#include "./join-into-ostream.hpp"

#include "./tuple-print.hpp"

#include "./makeVec.hpp"

#include "./bye.hpp"

#include "./chminmax.hpp"

#include "./is-within-range.hpp"

#include "./constant.hpp"

#pragma endregion  // }}}

signed main() {
    ioSetup();

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "include/template-parts/template.cpp"
#include <bits/stdc++.h>
using namespace std;

#pragma region  // {{{

#line 2 "include/template-parts/all-macro.hpp"

/**
 * @brief all()マクロ
 */
#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#line 2 "include/template-parts/rep-macro.hpp"

/**
 * @brief rep()マクロ
 */
#define rep2(i, n) for (size_t i = 0; i < (n); ++i)
#define rep3(i, s, e) for (int64_t i = int64_t(s); i < int64_t(e); ++i)
#define GET_4TH_ARG(dummy1, dummy2, dummy3, NAME, ...) NAME
#define rep(...) GET_4TH_ARG(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define repc(i, s, t) for (int64_t i = int64_t(s); i <= int64_t(t); ++i)
#define repr(i, s, t) for (int64_t i = int64_t(s); i >= int64_t(t); --i)
#line 8 "include/template-parts/template.cpp"

#line 6 "include/template-parts/type-alias.hpp"

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
#line 10 "include/template-parts/template.cpp"

#line 4 "include/template-parts/io-setup.hpp"

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
#line 12 "include/template-parts/template.cpp"

#line 3 "include/template-parts/var-declaration-with-input.hpp"

/**
 * @brief 複数変数宣言をして同時に入力もするやつ
 */
template <class T>
std::istream& operator,(std::istream& is, T& rhs) {
    return is >> rhs;
}

#define var(type, ...) \
    type __VA_ARGS__;  \
    std::cin >> __VA_ARGS__
#line 14 "include/template-parts/template.cpp"

#line 4 "include/template-parts/println.hpp"

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
#line 16 "include/template-parts/template.cpp"

#line 3 "include/template-parts/container-io.hpp"

/**
 * @brief コンテナの入出力
 */
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
    for (auto it = begin(v); it != end(v); ++it) os << " " + (it == begin(v)) << *it;
    return os;
}
#line 18 "include/template-parts/template.cpp"

#line 3 "include/template-parts/join-into-ostream.hpp"

/**
 * @brief join() (要素を区切り文字で結合して出力)
 */
template <class InputItr>
void join(std::ostream& os, InputItr begin, InputItr end, const char* delim = " ", const char* last = "\n") {
    const char* tmp[] = {delim, ""};
    for (auto it = begin; it != end; ++it) os << tmp[it == begin] << *it;
    os << last;
}
#line 20 "include/template-parts/template.cpp"

#line 6 "include/template-parts/tuple-print.hpp"

/**
 * @brief tupleの出力
 */
template <class Tuple, size_t... I>
std::array<int, sizeof...(I)> tuple_print_impl(std::ostream& os, Tuple&& t, std::index_sequence<I...>) {
    return {{(void(os << (I == 0 ? "" : ", ") << std::get<I>(t)), 0)...}};
}
template <class Tuple, class Value = typename std::tuple_element_t<0, Tuple>>
std::ostream& operator<<(std::ostream& os, Tuple&& t) {
    os << '{';
    tuple_print_impl(os, std::forward<Tuple>(t), std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
    return os << '}';
}
#line 22 "include/template-parts/template.cpp"

#line 3 "include/template-parts/makeVec.hpp"

/**
 * @brief makeVec() (多次元std::vectorの生成)
 */
template <class T>
inline std::vector<T> makeVec(const T& initValue, size_t sz) {
    return std::vector<T>(sz, initValue);
}
template <class T, class... Args>
inline auto makeVec(const T& initValue, size_t sz, Args... args) {
    return std::vector<decltype(makeVec<T>(initValue, args...))>(sz, makeVec<T>(initValue, args...));
}
#line 24 "include/template-parts/template.cpp"

#line 3 "include/template-parts/bye.hpp"

/**
 * @brief bye() (出力してexit(0))
 */
template <class T>
inline void bye(const T& x) {
    std::cout << x << '\n', exit(0);
}
#line 26 "include/template-parts/template.cpp"

#line 2 "include/template-parts/chminmax.hpp"

/**
 * @brief chmin(), chmax()
 */
template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return b < a && (a = b, true);
}

template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return b > a && (a = b, true);
}
#line 28 "include/template-parts/template.cpp"

#line 2 "include/template-parts/is-within-range.hpp"

/**
 * @brief within() (半開区間内に含まれているかの判定)
 */
template <class Value, class ValueBegin, class ValueEnd>
inline bool within(const Value& v, const ValueBegin& begin, const ValueEnd& end) {
    return begin <= v && v < end;
}
#line 30 "include/template-parts/template.cpp"

#line 3 "include/template-parts/constant.hpp"

/**
 * @brief よく使う定数
 */
constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;
// constexpr int32_t MOD = int32_t(1e9) + 7;
// constexpr int32_t MOD = 998244353;
#line 32 "include/template-parts/template.cpp"

#pragma endregion  // }}}

signed main() {
    ioSetup();

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

