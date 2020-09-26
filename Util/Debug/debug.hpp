#pragma once
#include <cstdint>
#include <iostream>
#include <iomanip>

#include "../int-infinity.hpp"

/**
 * @brief Debug
 */
#ifdef LOCAL_DEBUG

namespace dbg {

int w_ = 4;
bool negativeValAsNull_ = true;
std::ostream* os = &std::cerr;

template <class T, std::enable_if_t<!std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
void put(const T& x) {
    *os << std::setw(w_) << x;
}
template <class T, std::enable_if_t<std::is_signed<T>::value, std::nullptr_t> = nullptr>
void put(const T& x) {
    if (x <= -INF)
        *os << std::setw(w_) << "-INF";
    else if (negativeValAsNull_ && x < 0)
        *os << std::setw(w_) << " - ";
    else if (x >= INF)
        *os << std::setw(w_) << "INF";
    else
        *os << std::setw(w_) << x;
}
template <class T, std::enable_if_t<std::is_unsigned<T>::value, std::nullptr_t> = nullptr>
void put(const T& x) {
    if (static_cast<int64_t>(x) >= static_cast<int64_t>(INF))
        *os << std::setw(w_) << "INF";
    else
        *os << std::setw(w_) << x;
}
template <class A, class B>
void put(const std::pair<A, B>& t) {
    *os << '(' << std::setw(w_) << std::get<0>(t) << ",  " << std::setw(w_) << std::get<1>(t) << ')';
}
template <class A, class B, class C>
void put(const std::tuple<A, B, C>& t) {
    *os << '(' << std::setw(w_) << std::get<0>(t) << ",  " << std::setw(w_) << std::get<1>(t) << ",  " << std::setw(w_) << std::get<2>(t) << ')';
}

template <class Arr>
void showArrayH__(const Arr& a, size_t begin, size_t end) {
    for (size_t i = begin; i < end; ++i) *os << '[' << std::setw(dbg::w_) << i << "] ";
    *os << '\n';
    for (size_t i = begin; i < end; ++i) *os << ' ', dbg::put(a[i]), *os << "  ";
    *os << '\n';
}
template <class Arr>
void showArrayV__(const Arr& a, size_t begin, size_t end) {
    for (size_t i = begin; i < end; ++i)
        *os << '[' << std::setw(2) << i << ']', dbg::put(a[i]), *os << "\n";
    *os << std::flush;
}
template <class Table>
void showTable__(const Table& t, size_t yBegin, size_t yEnd, size_t xBegin, size_t xEnd) {
    *os << std::string(1 + 2 + 1, ' ');
    for (size_t j = xBegin; j < xEnd; ++j) *os << '[' << std::setw(dbg::w_) << j << "] ";
    *os << '\n';

    for (size_t i = yBegin; i < yEnd; ++i) {
        *os << '[' << std::setw(2) << i << "]";
        for (size_t j = xBegin; j < xEnd; ++j) *os << ' ', dbg::put(t[i][j]), *os << "  ";
        *os << '\n';
    }
}

}  // namespace dbg

void debug_setw(int w) {
    dbg::w_ = w;
}
void debug_negativeValAsNull(bool f) {
    dbg::negativeValAsNull_ = f;
}
void debug_setOstream(std::ostream& os) {
    dbg::os = &os;
}
void debug_hr() {
    *dbg::os << "----------------------------------------------------------------------\n";
}
void debug_println() {
    *dbg::os << std::endl;
}
template <class Head, class... Tail>
void debug_println(const Head& head, const Tail&... tail) {
    dbg::put(head);
    debug_println(tail...);
}

#define putDbgPrefix() *dbg::os << __func__ << '(' << std::setfill('0') << std::setw(3) << __LINE__ << std::setfill(' ') << "): "
#define showArrayH(a, beginIdx, endIdx) (void)(putDbgPrefix() << #a << ":\n"), dbg::showArrayH__(a, beginIdx, endIdx)
#define showArrayV(a, beginIdx, endIdx) (void)(putDbgPrefix() << #a << ":\n"), dbg::showArrayV__(a, beginIdx, endIdx)
#define showTable(t, yBegin, yEnd, xBegin, xEnd) (void)(putDbgPrefix() << #t << ":\n"), dbg::showTable__(t, yBegin, yEnd, xBegin, xEnd)
#define dbgMsg_(x) "  |  " #x " = ", x
#define dump1(a) (void)(putDbgPrefix()), debug_println(#a " = ", a)
#define dump2(a, b) (void)(putDbgPrefix()), debug_println(#a " = ", a, dbgMsg_(b))
#define dump3(a, b, c) (void)(putDbgPrefix()), debug_println(#a " = ", a, dbgMsg_(b), dbgMsg_(c))
#define dump4(a, b, c, d) (void)(putDbgPrefix()), debug_println(#a " = ", a, dbgMsg_(b), dbgMsg_(c), dbgMsg_(d))
#define dump5(a, b, c, d, e) (void)(putDbgPrefix()), debug_println(#a " = ", a, dbgMsg_(b), dbgMsg_(c), dbgMsg_(d), dbgMsg_(e))
#define dump6(a, b, c, d, e, f) (void)(putDbgPrefix()), debug_println(#a " = ", a, dbgMsg_(b), dbgMsg_(c), dbgMsg_(d), dbgMsg_(e), dbgMsg_(f))
#define dump7(a, b, c, d, e, f, g) (void)(putDbgPrefix()), debug_println(#a " = ", a, dbgMsg_(b), dbgMsg_(c), dbgMsg_(d), dbgMsg_(e), dbgMsg_(f), dbgMsg_(g))
#define GET_8TH_ARG(dummy1, dummy2, dummy3, dummy4, dummy5, dummy6, dumy7, NAME, ...) NAME
#define dump(...) GET_8TH_ARG(__VA_ARGS__, dump7, dump6, dump5, dump4, dump3, dump2, dump1)(__VA_ARGS__)

#else

#define debug_setw(...) ((void)0)
#define debug_negativeValAsNull(...) ((void)0)
#define debug_setOstream(...) ((void)0)
#define debug_hr(...) ((void)0)
#define debug_println(...) ((void)0)
#define showArrayH(...) ((void)0)
#define showArrayV(...) ((void)0)
#define showTable(...) ((void)0)
#define dump(...) ((void)0)

#endif
