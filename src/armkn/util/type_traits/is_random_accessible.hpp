#pragma once
#include <iterator>
#include <type_traits>
#include <utility>

namespace armkn {

template <typename T, typename = void>
struct is_random_accessible : std::false_type {};

template <typename T>
constexpr inline bool is_random_accessible_v = is_random_accessible<T>::value;

template <typename T>
struct is_random_accessible<
    T,
    std::void_t<
        typename std::iterator_traits<decltype(std::begin(std::declval<T>()))>::iterator_category> >
    : std::bool_constant<std::is_base_of_v<
          std::random_access_iterator_tag,
          typename std::iterator_traits<decltype(std::begin(std::declval<T>())
          )>::iterator_category> > {};

}  // namespace armkn
