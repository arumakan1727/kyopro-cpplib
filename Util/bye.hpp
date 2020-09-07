#pragma once
#include <iostream>

/**
 * @brief bye() (出力してexit(0))
 */
template <class T>
inline void bye(const T& x) {
    std::cout << x << '\n', exit(0);
}
