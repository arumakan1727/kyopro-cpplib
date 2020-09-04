#pragma once
#include <cstdint>

/**
 * @brief divceil() (切り上げ除算)
 */
inline uint64_t divceil(uint64_t a, uint64_t b) {
    return (a + b - 1) / b;
}
