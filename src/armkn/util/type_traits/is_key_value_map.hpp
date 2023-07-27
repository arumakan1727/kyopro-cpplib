#pragma once
#include <iterator>
#include <tuple>
#include <type_traits>
#include <utility>

namespace armkn {

template <typename T, typename = void>
struct is_key_value_map : std::false_type {};

template <typename T>
constexpr inline bool is_key_value_map_v = is_key_value_map<T>::value;

template <typename T>
struct is_key_value_map<
    T,
    std::void_t<
        typename T::key_type,
        typename T::mapped_type,
        decltype(std::get<0>(*std::begin(std::declval<T>()))),
        decltype(std::get<1>(*std::begin(std::declval<T>()))),
        std::enable_if_t<std::tuple_size_v<typename T::value_type> == 2>>> : std::true_type {};

}  // namespace armkn
