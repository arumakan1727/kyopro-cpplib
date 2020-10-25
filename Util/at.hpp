#pragma once
#include <tuple>
#include <functional>
#include <type_traits>

/**
 * @brief at() ()
 */
namespace arumakan {

//! at(a, i) returns a[i]
template <class Array, class Integer, std::enable_if_t<std::is_integral<Integer>::value, std::nullptr_t> = nullptr>
inline auto at(Array&& a, Integer i) -> decltype(a[0])& {
    return a[i];
}

//! at(a, Tuple{i}) returns a[i]
template <class Array, class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value == 1, std::nullptr_t> = nullptr>
inline auto at(Array&& a, Tuple index) -> decltype(a[0])& {
    return a[std::get<0>(index)];
}

//! at(mat, Tuple{y, x}) returns mat[y][x]
template <class Matrix, class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value == 2, std::nullptr_t> = nullptr>
inline auto at(Matrix&& mat, Tuple index) -> decltype(mat[0][0])& {
    return mat[std::get<0>(index)][std::get<1>(index)];
}

//! at(cube, Tuple{z, y, x}) returns cube[z][y][x]
template <class Cube, class Tuple, std::enable_if_t<std::tuple_size<Tuple>::value == 3, std::nullptr_t> = nullptr>
inline auto at(Cube&& cube, Tuple index) -> decltype(cube[0][0][0])& {
    return cube[std::get<0>(index)][std::get<1>(index)][std::get<2>(index)];
}

}  // namespace arumakan
