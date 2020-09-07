#pragma once

/**
 * @brief rep()マクロ
 */
#define rep(i, begin, end) for (int64_t i{begin}, i##_end{end}; i < i##_end; ++i)
#define repc(i, begin, last) for (int64_t i{begin}, i##_last{last}; i <= i##_last; ++i)
#define repr(i, begin, last) for (int64_t i{begin}, i##_last{last}; i >= i##_last; --i)
