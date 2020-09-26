#pragma once

#include <cstdint>

#include "./cstring-hash.hpp"

/**
 * @brief constexprRandint() (コンパイル時乱数)
 * 呼び出す度に値が変わるわけではないので う笑
 */
#define STRINGIZE_I(x) #x
#define STRINGIZE(x) STRINGIZE_I(x)
#define UNIQUE_STRING __DATE__ "_" __TIME__ "_" __FILE__ "_" STRINGIZE(__LINE__)

constexpr uint32_t constexprRandint(uint32_t min, uint32_t max) {
    const auto m = max - min + 1;
    return cstringHash(UNIQUE_STRING) % m + min;
}
