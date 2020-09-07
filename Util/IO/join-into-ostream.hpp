#pragma once
#include <iostream>

/**
 * @brief join() (要素を区切り文字で結合して出力)
 */
template <class InputItr>
void join(std::ostream& os, InputItr begin, InputItr end, const char* delim, const char* last = "\n") {
    const char* tmp[] = {delim, ""};
    for (auto it = begin; it != end; ++it) os << tmp[it == begin] << *it;
    os << last;
}
