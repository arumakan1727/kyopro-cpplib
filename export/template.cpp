#include <bits/stdc++.h>
// header {{{
#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin), i##_end = (end); i < i##_end; ++i)
#define repc(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(last)>> i = (begin), i##_last = (last); i <= i##_last; ++i)
#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(begin)>> i = (begin), i##_last = (last); i >= i##_last; --i)
#define let const auto
using i64 = int64_t;
using u64 = uint64_t;
constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T = int, template <class, class...> class Container = std::vector>
Container<T> read(size_t n) {
    Container<T> ret(n);
    for (auto& e : ret) std::cin >> e;
    return ret;
}

template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& v) {
    for (auto it = std::begin(v); it != std::end(v); ++it) os << &" "[it == std::begin(v)] << *it;
    return os;
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
    std::cout << head << &" "[!sizeof...(tail)];
    println(std::forward<Tail>(tail)...);
}

template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return b < a && (a = b, true);
}

template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return b > a && (a = b, true);
}
// }}}

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(12);

    return 0;
}
