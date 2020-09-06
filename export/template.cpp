#include <bits/stdc++.h>
using namespace std;

#if 1  // {{{

#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#define rep(i, begin, end) for (int64_t i{begin}, i##_end{end}; i < i##_end; ++i)
#define repc(i, begin, last) for (int64_t i{begin}, i##_last{last}; i <= i##_last; ++i)
#define repr(i, begin, last) for (int64_t i{begin}, i##_last{last}; i >= i##_last; --i)

#define let const auto
using i64 = int64_t;
using u64 = uint64_t;
using usize = size_t;
template <class T>
using MaxHeap = std::priority_queue<T, std::vector<T>>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;
// constexpr int32_t MOD = int32_t(1e9) + 7;
// constexpr int32_t MOD = 998244353;

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
inline std::vector<T> makeVec(const T& initValue, size_t sz) {
    return std::vector<T>(sz, initValue);
}
template <class T, class... Args>
inline auto makeVec(const T& initValue, size_t sz, Args... args) {
    return std::vector<decltype(makeVec<T>(initValue, args...))>(sz, makeVec<T>(initValue, args...));
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

signed main() {
    ioSetup();

    return 0;
}
