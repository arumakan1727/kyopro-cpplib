#pragma once

#define REP(i, s, t) for (auto i = (s); (i) < (t); ++(i))
#define REPC(i, s, t) for (auto i = (s); (i) <= (t); ++(i))
#define REPR(i, s, t) for (auto i = std::make_signed_t<decltype(s)>(s); (i) >= (t); --(i))
