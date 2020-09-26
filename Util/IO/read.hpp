#pragma once
#include <iostream>
#include <vector>

/**
 * @brief read() (n個入力してContainerに格納して返す)
 */
template <class T = int, template <class, class...> class Container = std::vector>
Container<T> read(size_t n) {
    Container<T> ret(n);
    for (auto& e : ret) std::cin >> e;
    return ret;
}
