#pragma once

#include <cstdint>

#include "./cstring-hash.hpp"

/**
 * @brief constexprRandint() (コンパイル時乱数)
 * 何回呼び出しても同じ値なので う笑
 */
#define STRINGIZE_I(x) #x
#define STRINGIZE(x) STRINGIZE_I(x)
#define UNIQUE_STRING __DATE__ "_" __TIME__ "_" __FILE__ "_" STRINGIZE(__LINE__)

constexpr std::uint32_t constexprRandint(std::uint32_t min, std::uint32_t max) {
    const auto m = max - min + 1;
    return cstringHash(UNIQUE_STRING) % m + min;
}
