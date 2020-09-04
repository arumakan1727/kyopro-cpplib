#pragma once
#include <array>
#include <iostream>
#include <tuple>
#include <utility>

/**
 * @brief tupleの出力
 * @see https://qiita.com/_EnumHack/items/677363eec054d70b298d#index-tuple-idiom-the-indices-trick
 */
template <class Tuple, size_t... I>
std::array<int, sizeof...(I)> tuple_print_impl(std::ostream& os, Tuple&& t, std::index_sequence<I...>) {
    return {{(void(os << (I == 0 ? "" : ", ") << std::get<I>(t)), 0)...}};
}
template <class Tuple, class Value = typename std::tuple_element_t<0, Tuple>>
std::ostream& operator<<(std::ostream& os, Tuple&& t) {
    os << '{';
    tuple_print_impl(os, std::forward<Tuple>(t), std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
    return os << '}';
}
