#pragma once
#include <vector>

/**
 * @brief makeVec() (多次元std::vectorの生成)
 */
template <class T>
inline std::vector<T> makeVec(size_t sz, const T& initValue) {
    return std::vector<T>(sz, initValue);
}
template <class T, class... Args>
inline auto makeVec(size_t sz, Args... args) {
    return std::vector<decltype(makeVec<T>(args...))>(sz, makeVec<T>(args...));
}
