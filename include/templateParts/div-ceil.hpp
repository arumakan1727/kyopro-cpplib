#pragma once
#include <cstdint>
#include <cstdlib>

/**
 * @brief 切り上げ除算
 */
// a / b 以上の最小の整数 (正の方向に丸める)
inline int64_t divceil(int64_t a, int64_t b) { return (a > 0) == (b > 0) ? (abs(a) + abs(b) - 1) / abs(b) : -(abs(a) / abs(b)); }
