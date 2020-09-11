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


# :warning: Debug <small>(Util/Debug/debug.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9b72678fcee7fc825926f536e5c04d88">Util/Debug</a>
* <a href="{{ site.github.repository_url }}/blob/master/Util/Debug/debug.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 10:56:41+09:00




## Depends on

* :warning: <a href="../int-infinity.hpp.html">int-infinity (整数のデカイ値) <small>(Util/int-infinity.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <iostream>
#include <iomanip>

#include "../int-infinity.hpp"

/**
 * @brief Debug
 */

template <class A, class B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& t) {
    return os << '{' << std::get<0>(t) << ", " << std::get<1>(t) << '}';
}
template <class A, class B, class C>
std::ostream& operator<<(std::ostream& os, const std::tuple<A, B, C>& t) {
    return os << '{' << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << '}';
}

#ifdef LOCAL_DEBUG  // {{{

class Debug {
private:
    int w_ = 4;
    int valueOffset_ = 0;
    int indexOffset_ = 0;
    bool negativeValAsNull_ = true;
    static constexpr int32_t inf32_ = INF;
    static constexpr int64_t inf64_ = LINF;

public:
    std::ostream& os = std::cerr;

    Debug() = default;

    void line() const { os << "---------------------------------------------------\n"; }
    void flush() const { os << std::flush; }
    void w(int w) { w_ = w; }
    void valueOffset(int v) { valueOffset_ = v; }
    void indexOffset(int v) { indexOffset_ = v; }
    void negativeValAsNull(bool f) { negativeValAsNull_ = f; }

    template <class T>
    void show(const T& x) const {
        put(x), os << '\n';
    }

    template <class T, class U, class... Tail>
    void show(const T& x, const U& y, const Tail&... tail) const {
        put(x);
        os << ",  ";
        show(y, tail...);
    }

    template <class Arr>
    void showArray(const Arr& a) const {
        showArray(a, 0, a.size());
    }

    template <class Arr>
    void showArray(const Arr& a, size_t begin, size_t end) const {
        os << '\n';
        for (size_t i = begin; i < end; ++i) os << '[' << std::setw(w_) << (i + indexOffset_) << "] ";
        os << '\n';
        for (size_t i = begin; i < end; ++i) os << ' ' << std::setw(w_), put(a[i]), os << "  ";
        os << '\n';
    }

    template <class Table>
    void showTable(const Table& t) const {
        showTable(t, 0, t.size(), 0, t[0].size());
    }

    template <class Table>
    void showTable(const Table& t, size_t yBegin, size_t yEnd, size_t xBegin, size_t xEnd) const {
        os << '\n';
        os << std::string(1 + 2 + 1, ' ');
        for (size_t j = xBegin; j < xEnd; ++j) os << '[' << std::setw(w_) << (j + indexOffset_) << "] ";
        os << '\n';

        for (size_t i = yBegin; i < yEnd; ++i) {
            os << '[' << std::setw(2) << (i + indexOffset_) << "]";
            for (size_t j = xBegin; j < xEnd; ++j) os << ' ' << std::setw(w_), put(t[i][j]), os << "  ";
            os << '\n';
        }
    }

private:
    template <class T>
    void put(const T& x) const {
        if constexpr (std::is_same_v<T, char>) {
            os << '\'' << x << '\'';
        } else if constexpr (std::is_same_v<T, bool>) {
            os << std::setw(w_) << (x ? "true" : "false");
        } else if constexpr (std::is_integral_v<T>) {
            os << std::setw(w_) << convert(x);
        } else if constexpr (std::is_convertible_v<T, std::string_view>) {
            os << std::setw(w_) << std::quoted(x);
        } else {
            os << std::setw(w_) << x;
        }
    }

    template <class T>
    std::string convert(const T& x) const {
        if constexpr (std::is_signed_v<T>) {
            if (x <= -infinity<T>()) return "-INF";
            if (negativeValAsNull_ && x < 0) return "-";
        }
        if (x >= infinity<T>()) return "INF";
        return std::to_string(x + valueOffset_);
    }
};

#define dump(...)                                                                                    \
    debug.os << "line" << std::setw(3) << std::setfill('0') << __LINE__ << std::setfill(' ') << ": " \
             << "[" << #__VA_ARGS__ << "]: ",                                                        \
        debug.show(__VA_ARGS__)

#else

#define DEF_FUNC(funcName) \
    template <class... T>  \
    void funcName(T&&...) {}

struct Debug {
    DEF_FUNC(line)
    DEF_FUNC(flush)
    DEF_FUNC(w)
    DEF_FUNC(valueOffset)
    DEF_FUNC(indexOffset)
    DEF_FUNC(negativeValAsNull)
    DEF_FUNC(inf32)
    DEF_FUNC(inf64)
    DEF_FUNC(show)
    DEF_FUNC(showArray)
    DEF_FUNC(showTable)
};

#undef DEF_FUNC
#define dump(...) ((void)0)

#endif  // }}}

Debug debug;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Util/Debug/debug.hpp"
#include <cstdint>
#include <iostream>
#include <iomanip>

#line 3 "Util/int-infinity.hpp"
#include <limits>
#include <type_traits>

/**
 * @brief int-infinity (整数のデカイ値)
 * 2倍してもオーバーフローしない & memset()にも使える (需要ある？)
 */
constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 4, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return INF;
}

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 8, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return LINF;
}
#line 7 "Util/Debug/debug.hpp"

/**
 * @brief Debug
 */

template <class A, class B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& t) {
    return os << '{' << std::get<0>(t) << ", " << std::get<1>(t) << '}';
}
template <class A, class B, class C>
std::ostream& operator<<(std::ostream& os, const std::tuple<A, B, C>& t) {
    return os << '{' << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << '}';
}

#ifdef LOCAL_DEBUG  // {{{

class Debug {
private:
    int w_ = 4;
    int valueOffset_ = 0;
    int indexOffset_ = 0;
    bool negativeValAsNull_ = true;
    static constexpr int32_t inf32_ = INF;
    static constexpr int64_t inf64_ = LINF;

public:
    std::ostream& os = std::cerr;

    Debug() = default;

    void line() const { os << "---------------------------------------------------\n"; }
    void flush() const { os << std::flush; }
    void w(int w) { w_ = w; }
    void valueOffset(int v) { valueOffset_ = v; }
    void indexOffset(int v) { indexOffset_ = v; }
    void negativeValAsNull(bool f) { negativeValAsNull_ = f; }

    template <class T>
    void show(const T& x) const {
        put(x), os << '\n';
    }

    template <class T, class U, class... Tail>
    void show(const T& x, const U& y, const Tail&... tail) const {
        put(x);
        os << ",  ";
        show(y, tail...);
    }

    template <class Arr>
    void showArray(const Arr& a) const {
        showArray(a, 0, a.size());
    }

    template <class Arr>
    void showArray(const Arr& a, size_t begin, size_t end) const {
        os << '\n';
        for (size_t i = begin; i < end; ++i) os << '[' << std::setw(w_) << (i + indexOffset_) << "] ";
        os << '\n';
        for (size_t i = begin; i < end; ++i) os << ' ' << std::setw(w_), put(a[i]), os << "  ";
        os << '\n';
    }

    template <class Table>
    void showTable(const Table& t) const {
        showTable(t, 0, t.size(), 0, t[0].size());
    }

    template <class Table>
    void showTable(const Table& t, size_t yBegin, size_t yEnd, size_t xBegin, size_t xEnd) const {
        os << '\n';
        os << std::string(1 + 2 + 1, ' ');
        for (size_t j = xBegin; j < xEnd; ++j) os << '[' << std::setw(w_) << (j + indexOffset_) << "] ";
        os << '\n';

        for (size_t i = yBegin; i < yEnd; ++i) {
            os << '[' << std::setw(2) << (i + indexOffset_) << "]";
            for (size_t j = xBegin; j < xEnd; ++j) os << ' ' << std::setw(w_), put(t[i][j]), os << "  ";
            os << '\n';
        }
    }

private:
    template <class T>
    void put(const T& x) const {
        if constexpr (std::is_same_v<T, char>) {
            os << '\'' << x << '\'';
        } else if constexpr (std::is_same_v<T, bool>) {
            os << std::setw(w_) << (x ? "true" : "false");
        } else if constexpr (std::is_integral_v<T>) {
            os << std::setw(w_) << convert(x);
        } else if constexpr (std::is_convertible_v<T, std::string_view>) {
            os << std::setw(w_) << std::quoted(x);
        } else {
            os << std::setw(w_) << x;
        }
    }

    template <class T>
    std::string convert(const T& x) const {
        if constexpr (std::is_signed_v<T>) {
            if (x <= -infinity<T>()) return "-INF";
            if (negativeValAsNull_ && x < 0) return "-";
        }
        if (x >= infinity<T>()) return "INF";
        return std::to_string(x + valueOffset_);
    }
};

#define dump(...)                                                                                    \
    debug.os << "line" << std::setw(3) << std::setfill('0') << __LINE__ << std::setfill(' ') << ": " \
             << "[" << #__VA_ARGS__ << "]: ",                                                        \
        debug.show(__VA_ARGS__)

#else

#define DEF_FUNC(funcName) \
    template <class... T>  \
    void funcName(T&&...) {}

struct Debug {
    DEF_FUNC(line)
    DEF_FUNC(flush)
    DEF_FUNC(w)
    DEF_FUNC(valueOffset)
    DEF_FUNC(indexOffset)
    DEF_FUNC(negativeValAsNull)
    DEF_FUNC(inf32)
    DEF_FUNC(inf64)
    DEF_FUNC(show)
    DEF_FUNC(showArray)
    DEF_FUNC(showTable)
};

#undef DEF_FUNC
#define dump(...) ((void)0)

#endif  // }}}

Debug debug;

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

