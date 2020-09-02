#pragma once
#include <iostream>

/**
 * @brief 出力して exit(0)
 */
template <class T>
inline void bye(const T &x) { std::cout << x << '\n', exit(0); }
