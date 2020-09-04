#include <bits/stdc++.h>
using namespace std;

#pragma region  // {{{

#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#define rep2(i, n) for (size_t i = 0; i < (n); ++i)
#define rep3(i, s, e) for (int64_t i = int64_t(s); i < int64_t(e); ++i)
#define GET_4TH_ARG(dummy1, dummy2, dummy3, NAME, ...) NAME
#define rep(...) GET_4TH_ARG(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define repc(i, s, t) for (int64_t i = int64_t(s); i <= int64_t(t); ++i)
#define repr(i, s, t) for (int64_t i = int64_t(s); i >= int64_t(t); --i)

#define let const auto
using i64 = int64_t;
using u64 = uint64_t;
using usize = size_t;
template <class T>
using MaxHeap = std::priority_queue<T, std::vector<T>>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

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
    for (auto it = begin(v); it != end(v); ++it) os << " " + (it == begin(v)) << *it;
    return os;
}

template <class InputItr>
void join(std::ostream& os, InputItr begin, InputItr end, const char* delim = " ", const char* last = "\n") {
    const char* tmp[] = {delim, ""};
    for (auto it = begin; it != end; ++it) os << tmp[it == begin] << *it;
    os << last;
}

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

template <class Value, class ValueBegin, class ValueEnd>
inline bool within(const Value& v, const ValueBegin& begin, const ValueEnd& end) {
    return begin <= v && v < end;
}

constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;
// constexpr int32_t MOD = int32_t(1e9) + 7;
// constexpr int32_t MOD = 998244353;

#pragma endregion  // }}}

signed main() {
    ioSetup();

    return 0;
}
