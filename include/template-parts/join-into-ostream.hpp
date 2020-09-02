#pragma once
#include <iostream>

/**
 * @brief 要素を結合して出力
 */
template <class InputItr>
void join(std::ostream &os, InputItr begin, InputItr end, const char *delim = " ", const char *last = "\n") {
    const char *tmp[] = {delim, ""};
    for (auto it = begin; it != end; ++it) os << tmp[it == begin] << *it;
    os << last;
}
