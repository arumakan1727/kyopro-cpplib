#pragma once
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <set>
#include <type_traits>
#include "../util/alias/stdint.hpp"
#include "./closed_range.hpp"

/// 整数点のみからなる閉区間の集合
template <class P, std::enable_if_t<std::is_integral_v<P>, std::nullptr_t> = nullptr>
class ClosedRangeSet {
 public:
  using Range = CRange<P>;
  using value_type = Range;
  using iterator = typename std::set<value_type>::iterator;

 private:
  std::set<Range> s;

 public:
  inline ClosedRangeSet() {
    using lim = std::numeric_limits<P>;
    s.emplace(lim::min(), lim::min());
    s.emplace(lim::max(), lim::max());
  }

  // 区間の総数
  inline size_t size() const {
    return s.size() - 2;
  }

  inline bool empty() const {
    return s.size() <= 2;
  }

  inline auto begin() const {
    return std::next(s.begin());
  }

  inline auto end() const {
    return std::prev(s.end());
  }

  // 点 p を含む区間が存在するならtrue
  inline bool contains(P p) const {
    return std::prev(s.lower_bound({p + 1, p + 1}))->contains(p);
  }

  // [l, r] を被覆する区間が存在するならtrue;
  // `a <= l && r <= b` を満たす [a, b] の存在を調べる
  inline bool covers(P l, P r) const {
    assert(l <= r);
    return std::prev(s.lower_bound({l + 1, l + 1}))->covers(Range(l, r));
  }

  inline bool covers(Range const& a) const {
    return covers(a.min, a.max);
  }

  // [l, r] との積集合が空でないならば true;
  inline bool intersects(P l, P r) const {
    assert(l <= r);
    auto it = s.lower_bound({l, l});
    if (it->min <= r) return true;
    --it;
    return l <= it->max;
  }

  inline bool intersects(Range const& a) const {
    return intersects(a.min, a.max);
  }

  // [l, r] を追加して要素の増加量を返す;
  // 点 l-1 に区間がある場合はその区間とマージ;
  // 点 r+1 に区間がある場合はその区間とマージ;
  size_t insert(P l, P r) {
    assert(l <= r);
    auto it = std::prev(s.lower_bound({l + 1, l + 1}));
    if (it->covers(Range(l, r))) return 0;

    size_t cnt_erased = 0;
    if (it->min <= l && l <= it->max + 1) {
      l = it->min;
      cnt_erased += it->size();
      it = s.erase(it);
    } else {
      it = std::next(it);
    }
    while (r > it->max) {
      cnt_erased += it->size();
      it = s.erase(it);
    }
    if (it->min - 1 <= r) {
      cnt_erased += it->size();
      r = it->max;
      s.erase(it);
    }
    s.emplace(l, r);
    return (size_t)r - l + 1 - cnt_erased;
  }

  inline size_t insert(Range const& a) {
    return insert(a.min, a.max);
  }

  // [l, r] を削除して要素の減少量を返す
  size_t erase(P l, P r) {
    assert(l <= r);
    auto it = std::prev(s.lower_bound({l + 1, l + 1}));
    if (it->covers(Range(l, r))) {
      if (it->min < l) s.emplace(it->min, l - 1);
      if (r < it->max) s.emplace(r + 1, it->max);
      s.erase(it);
      return r - l + 1;
    }

    size_t res = 0;
    if (it->contains(l)) {
      res += it->max - l + 1;
      if (it->min < l) s.emplace(it->min, l - 1);
      it = s.erase(it);
    } else {
      it = std::next(it);
    }
    while (it->max <= r) {
      res += it->max - it->min + 1;
      it = s.erase(it);
    }
    if (it->min <= r) {
      res += r - it->min + 1;
      s.emplace(r + 1, it->max);
      s.erase(it);
    }
    return res;
  }

  inline size_t erase(Range const& a) {
    return erase(a.min, a.max);
  }

  // 自身に含まれない && x 以上の最小の点
  inline P mex(P x) const {
    auto it = std::prev(s.lower_bound({x + 1, x + 1}));
    if (it->contains(x)) {
      return it->max + 1;
    } else {
      return x;
    }
  }
};
