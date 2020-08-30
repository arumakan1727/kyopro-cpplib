#pragma once
#include <cstdint>
#include <cstdlib>

/**
 * @brief 切り捨て除算
 */
// a / b 以下の最大の整数 (負の方向に丸める)
inline int64_t divfloor(int64_t a, int64_t b) { return (a > 0) == (b > 0) ? a / b : -((abs(a) + abs(b) - 1) / abs(b)); }
