#pragma once
#include <cstdint>
#include <algorithm>
#include <vector>
#include <tuple>

/**
 * @brief project() (タプルのコンテナの第 I 要素を抽出したvectorを返す)
 */
template <std::size_t I, class Container, class Value = typename std::tuple_element_t<I, typename Container::value_type>>
std::vector<Value> project(const Container& v) {
    std::vector<Value> ret(v.size());
    std::transform(v.begin(), v.end(), ret.begin(), [](auto&& t) { return std::get<I>(t); });
    return ret;
}
