#pragma once

/**
 * @brief repマクロ
 */
#define rep(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i < (t); ++i)
#define repc(i, s, t) for (common_type_t<decltype(s), decltype(t)> i = (s); i <= (t); ++i)
#define repr(i, t, s) for (i64 i = i64(t); i >= i64(s); --i)
