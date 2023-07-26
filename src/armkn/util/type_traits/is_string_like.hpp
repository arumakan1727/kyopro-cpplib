#pragma once
#include <string>
#include <string_view>
#include <type_traits>

namespace armkn {

template <class T>
struct is_string_like : std::false_type {};

template <class T>
constexpr inline bool is_string_like_v = is_string_like<T>::value;

template <class CharT>
struct is_string_like<std::basic_string<CharT> > : std::true_type {};

template <class CharT>
struct is_string_like<std::basic_string_view<CharT> > : std::true_type {};

}  // namespace armkn
