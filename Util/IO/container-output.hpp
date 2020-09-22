#pragma once
#include <iostream>

/**
 * @brief std::ostreamによるコンテナの出力
 */
template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& v) {
    for (auto it = std::begin(v); it != std::end(v); ++it) os << &" "[it == std::begin(v)] << *it;
    return os;
}
