#pragma once

#include <iostream>

/**
 * @brief errln() (println()のstderr版, デバッグ時のみ有効)
 */
inline void eprintln() {
    std::clog << std::endl;
}
template <class Head, class... Tail>
inline void eprintln(Head&& head, Tail&&... tail) {
    std::clog << head << &" "[!sizeof...(tail)];
    eprintln(std::forward<Tail>(tail)...);
}

#ifdef LOCAL_DEBUG
#define errln(...) std::clog << __FILE__ << "(" << __LINE__ << ")[" << __func__ << "()]: ", eprintln(__VA_ARGS__)
#else
#define errln(...) ((void)0)
#endif
