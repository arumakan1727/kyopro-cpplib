#pragma once
#include <iostream>

/**
 * @brief std::istreamによるコンテナの入力
 */
template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::istream& operator>>(std::istream& is, Container& v) {
    for (auto& e : v) is >> e;
    return is;
}
