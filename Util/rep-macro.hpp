#pragma once

/**
 * @brief rep()マクロ
 */
#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin), i##_end = (end); i < i##_end; ++i)
#define repc(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(last)>> i = (begin), i##_last = (last); i <= i##_last; ++i)
#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(begin)>> i = (begin), i##_last = (last); i >= i##_last; --i)
