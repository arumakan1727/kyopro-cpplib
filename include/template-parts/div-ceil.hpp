#pragma once
#include <cstdint>

/**
 * @brief divceil() (切り上げ除算)
 */
inline int64_t divceil(int64_t a, int64_t b) {
    return (a + b - 1) / b;
}
