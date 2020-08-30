#pragma once
#include <iostream>
#include <utility>

/**
 * @brief 可変個の値を空白区切りで出力して改行する
 */
inline void println() { std::cout << '\n'; }

template <class Head, class... Tail>
inline void println(Head &&head, Tail &&... tail) {
    std::cout << head << " " + (!sizeof...(tail));
    println(std::forward<Tail>(tail)...);
}
