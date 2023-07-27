#pragma once
#include <iterator>
#include <type_traits>
#include <utility>

namespace armkn {

template <typename T, typename = void>
struct is_iterable : std::false_type {};

template <typename T>
constexpr inline bool is_iterable_v = is_iterable<T>::value;

template <typename T>
struct is_iterable<
    T,
    std::void_t<decltype(std::begin(std::declval<T>()) == std::end(std::declval<T>()))>>
    : std::true_type {};

}  // namespace armkn
