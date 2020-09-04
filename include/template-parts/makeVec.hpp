#pragma once
#include <vector>

/**
 * @brief makeVec() (多次元std::vectorの生成)
 */
template <class T>
inline std::vector<T> makeVec(const T& initValue, size_t sz) {
    return std::vector<T>(sz, initValue);
}
template <class T, class... Args>
inline auto makeVec(const T& initValue, size_t sz, Args... args) {
    return std::vector<decltype(makeVec<T>(initValue, args...))>(sz, makeVec<T>(initValue, args...));
}
