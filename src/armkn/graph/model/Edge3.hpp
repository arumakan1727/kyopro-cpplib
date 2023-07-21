#pragma once
#include <cstdint>

template <class Weight>
struct Edge3 {
  using u32 = uint32_t;
  u32 from, to;
  Weight w;

  Edge3() : from(0), to(0), w(0){};
  explicit Edge3(u32 from_, u32 to_, Weight w_) : from(from_), to(to_), w(w_) {}

  inline bool operator<(const Edge3& rhs) const {
    return w < rhs.w;
  }
};
