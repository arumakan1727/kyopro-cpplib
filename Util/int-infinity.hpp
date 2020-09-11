#pragma once
#include <cstdint>
#include <limits>
#include <type_traits>

/**
 * @brief int-infinity (整数のデカイ値)
 * 2倍してもオーバーフローしない & memset()にも使える (需要ある？)
 */
constexpr int32_t INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 4, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return INF;
}

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 8, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return LINF;
}
