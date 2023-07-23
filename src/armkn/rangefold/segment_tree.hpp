#pragma once
#include <cassert>
#include <cstdint>
#include <vector>

template <typename Monoid, class Op>
class SegmentTree {
  uint32_t n;
  mutable uint32_t last_ref_i;
  Monoid ident;
  mutable Monoid proxy;
  Op op;
  mutable std::vector<Monoid> v;

 public:
  SegmentTree(Monoid identity, Op op_) noexcept
      : n(0), last_ref_i(0), ident(identity), proxy(identity), op(op_) {}

  template <class InputIter>
  void build(InputIter begin, InputIter end) noexcept {
    n = std::distance(begin, end);
    v.resize(n * 2, ident);
    for (uint32_t i = 0; i < n; i++) v[i + n] = *(begin++);
    for (uint32_t i = n - 1; i; i--) update(i);
  }

  void build(uint32_t n_) noexcept {
    n = n_;
    v.resize(n * 2, ident);
  }

  uint32_t size() const noexcept {
    return n;
  }

  const Monoid& operator[](uint32_t i) const noexcept {
    assert(i < n);
    apply_proxy_value();
    return proxy = v[last_ref_i = i + n];
  }

  Monoid& operator[](uint32_t i) noexcept {
    assert(i < n);
    apply_proxy_value();
    return proxy = v[last_ref_i = i + n];
  }

  const Monoid& fold_all() const noexcept {
    apply_proxy_value();
    return v[0];
  }

  /// [l, r)
  const Monoid fold(uint32_t l, uint32_t r) const noexcept {
    assert(r < n);
    assert(l <= r);
    apply_proxy_value();
    Monoid res_l = ident, res_r = ident;
    l += n, r += n;
    while (l < r) {
      if (l & 1) res_l = op(res_l, v[l++]);
      if (r & 1) res_r = op(v[--r], res_r);
      l >>= 1, r >>= 1;
    }
    return op(res_l, res_r);
  }

  /// Returns rightmost `right` s.t. `p(fold(left, right)) = true`
  /// `p(identity)` **MUST be ALWAYS TRUE**.
  template <class PredicateFn>
  int binary_search(uint32_t left, PredicateFn&& p) const noexcept {
    assert(p(ident));
    apply_proxy_value();
    Monoid folded = ident;
    auto l = left + n, r = n + n;
    std::vector<uint32_t> st;
    while (l < r) {
      if (l & 1) {
        auto tmp = op(folded, v[l]);
        if (p(tmp)) {
          folded = tmp;
          l++;
        } else {
          while (l < n) {
            tmp = op(folded, v[l <<= 1]);
            if (p(tmp)) folded = tmp, l++;
          }
          return l - n;
        }
      }
      if (r & 1) st.push_back(--r);
      l >>= 1;
      r >>= 1;
    }
    while (!st.empty()) {
      auto k = st.back();
      st.pop_back();
      auto tmp = op(folded, v[k]);
      if (!p(tmp)) {
        while (k < n) {
          tmp = op(folded, v[k <<= 1]);
          if (p(tmp)) folded = tmp, k++;
        }
        return k - n;
      }
    }
    return n;
  }

 private:
  inline void update(uint32_t i) const noexcept {
    v[i] = op(v[i << 1], v[i << 1 | 1]);
  }

  inline void apply_proxy_value() const noexcept {
    if (v[last_ref_i] == proxy) {
      last_ref_i = 0;
      return;
    }
    v[last_ref_i] = proxy;
    while (last_ref_i >>= 1) update(last_ref_i);
  }
};
