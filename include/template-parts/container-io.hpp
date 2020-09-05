#pragma once
#include <iostream>

/**
 * @brief コンテナの入出力
 */
template <class Container,
          class Value = typename Container::value_type,
          std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::istream& operator>>(std::istream& is, Container& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <class Container,
          class Value = typename Container::value_type,
          std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& v) {
    for (auto it = std::begin(v); it != std::end(v); ++it) os << " " + (it == std::begin(v)) << *it;
    return os;
}
