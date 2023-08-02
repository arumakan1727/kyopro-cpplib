#pragma once
#include <cassert>
#include <cstddef>

// ClosedRange (閉区間)
template <class P>
struct CRange {
  P min, max;

  CRange() = default;
  CRange(P const& min_, P const& max_) : min(min_), max(max_) {
#ifdef ARMKN_DEBUG
    assert(min_ <= max_);
#endif
  }

  inline bool operator==(CRange const& rhs) const noexcept {
    return min == rhs.min && max == rhs.max;
  }

  inline bool operator!=(CRange const& rhs) const noexcept {
    return !operator==(rhs);
  }

  inline bool operator<(CRange const& rhs) const noexcept {
    return min == rhs.min ? max < rhs.max : min < rhs.max;
  }

  /// 要素数 (区間の長さ)
  inline size_t size() const noexcept {
    return (size_t)max - min + 1;
  }

  inline bool contains(P const& p) const noexcept {
    return min <= p && p <= max;
  }

  /// 端点で触れている場合も true
  inline bool touches(CRange const& s) const noexcept {
    return !(max < s.min || s.max < min);
  }

  /// 端点で触れている場合は false
  inline bool overlaps(CRange const& s) const noexcept {
    return !(max <= s.min || s.max <= min);
  }

  /// s の全要素を包含しているなら true (つまり端点が一致している場合も true)
  inline bool covers(CRange const& s) const noexcept {
    return min <= s.min && s.max <= max;
  }
};
