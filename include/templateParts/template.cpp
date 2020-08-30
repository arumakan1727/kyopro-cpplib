#include <bits/stdc++.h>
using namespace std;

#pragma region  // {{{

#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#define rep(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i < (t); ++i)
#define repc(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i <= (t); ++i)
#define repr(i, t, s) for (i64 i = i64(t); i >= i64(s); --i)

void ioSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(11);
    clog << fixed << setprecision(11);
}

#define var(type, ...) \
    type __VA_ARGS__;  \
    cin >> __VA_ARGS__

template <class T>
istream &operator,(istream &is, T &rhs) { return is >> rhs; }

inline void println() { cout << '\n'; }

template <class Head, class... Tail>
inline void println(Head &&head, Tail &&... tail) {
    cout << head << " "[!sizeof...(tail)];
    println(forward<Tail>(tail)...);
}

template <class Container, class Value = typename Container::value_type,
          enable_if_t<!is_same<Container, string>::value, nullptr_t> = nullptr>
istream &operator>>(istream &is, Container &v) {
    for (auto &e : v) is >> e;
    return is;
}

template <class Container, class Value = typename Container::value_type,
          enable_if_t<!is_same<Container, string>::value, nullptr_t> = nullptr>
ostream &operator<<(ostream &os, const Container &v) {
    for (auto it = begin(v); it != end(v); ++it) os << " " + (it == begin(v)) << *it;
    return os;
}

template <class InputItr>
void join(ostream &os, InputItr begin, InputItr end, const char *delim = " ", const char *last = "\n") {
    const char *tmp[] = {delim, ""};
    for (auto it = begin; it != end; ++it) os << tmp[it == begin] << *it;
    os << last;
}

template <class Tuple, size_t... I>
array<int, sizeof...(I)> tuple_print_impl(ostream &os, Tuple &&t, std::index_sequence<I...>) {
    return {{(void(os << (I == 0 ? "" : ", ") << std::get<I>(t)), 0)...}};
}

template <class Tuple, class Value = typename std::tuple_element_t<0, Tuple>>
ostream &operator<<(ostream &os, Tuple &&t) {
    os << '{';
    tuple_print_impl(os, std::forward<Tuple>(t), std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
    return os << '}';
}

using i64 = int64_t;
using u64 = uint64_t;
using usize = size_t;
using ld = long double;

template <class T>
using limits = std::numeric_limits<T>;
template <class T>
using MaxHeap = std::priority_queue<T, vector<T>>;
template <class T>
using MinHeap = std::priority_queue<T, vector<T>, greater<T>>;

void yesno(bool cond) { cout << (cond ? "yes" : "no") << '\n'; };
void YesNo(bool cond) { cout << (cond ? "Yes" : "No") << '\n'; };
void YESNO(bool cond) { cout << (cond ? "YES" : "NO") << '\n'; };
void Yay(bool cond) { cout << (cond ? "Yay!" : ":(") << '\n'; };
void possible(bool cond) { cout << (cond ? "possible" : "impossible") << '\n'; };
void Possible(bool cond) { cout << (cond ? "Possible" : "Impossible") << '\n'; };
void POSSIBLE(bool cond) { cout << (cond ? "POSSIBLE" : "IMPOSSIBLE") << '\n'; };

template <class T>
inline void bye(const T &x) { cout << x << '\n', exit(0); }
template <class T, class U>
inline bool chmin(T &a, const U &b) { return b < a && (a = b, true); }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return b > a && (a = b, true); }
template <class Value, class BeginValue, class EndValue>
inline bool within(const Value &v, const BeginValue &begin, const EndValue &end) { return begin <= v && v < end; }

// 正の方向に丸める
inline int64_t divceil(int64_t a, int64_t b) { return (a > 0) == (b > 0) ? (abs(a) + abs(b) - 1) / abs(b) : -(abs(a) / abs(b)); }
// 負の方向に丸める
inline int64_t divfloor(int64_t a, int64_t b) { return (a > 0) == (b > 0) ? a / b : -((abs(a) + abs(b) - 1) / abs(b)); }

constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;
// constexpr int32_t MOD = int32_t(1e9) + 7;
// constexpr int32_t MOD = 998244353;

#pragma endregion  // }}}

signed main() {
    ioSetup();

    return 0;
}
