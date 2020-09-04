#pragma once

/**
 * @brief rep()マクロ
 */
#define rep2(i, n) for (size_t i = 0; i < (n); ++i)
#define rep3(i, s, e) for (int64_t i = int64_t(s); i < int64_t(e); ++i)
#define GET_4TH_ARG(dummy1, dummy2, dummy3, NAME, ...) NAME
#define rep(...) GET_4TH_ARG(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define repc(i, s, t) for (int64_t i = int64_t(s); i <= int64_t(t); ++i)
#define repr(i, s, t) for (int64_t i = int64_t(s); i >= int64_t(t); --i)
