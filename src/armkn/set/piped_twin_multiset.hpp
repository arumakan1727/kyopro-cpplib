#pragma once
#include <cstddef>
#include <functional>
#include <set>

/// 内部で2つの std::multiset<T> `left`, `right` をもつ;
/// - (`left` 内の最大値) < (`right` 内の最小値) を常に保つ
template <class T>
class PipedTwinMultiset {
 public:
  using value_type = T;
  using iterator = typename std::multiset<T>::iterator;
  using callback = std::function<void(value_type const&)>;

 private:
  static inline constexpr void _do_nothing(value_type) {}

  std::multiset<T> _l, _r;
  callback _on_insert_l = _do_nothing;
  callback _on_insert_r = _do_nothing;
  callback _on_erase_l = _do_nothing;
  callback _on_erase_r = _do_nothing;

 public:
  PipedTwinMultiset() = default;

  inline void set_on_insert_l(callback&& f) {
    _on_insert_l = f;
  }
  inline void set_on_insert_r(callback&& f) {
    _on_insert_r = f;
  }
  inline void set_on_erase_l(callback&& f) {
    _on_erase_l = f;
  }
  inline void set_on_erase_r(callback&& f) {
    _on_erase_r = f;
  }

  /// left または right のいずれかの SortedSet に適切に挿入する;
  inline void insert(value_type const& val) {
    if (_r.empty() || val < *_r.begin()) {
      insert_l(val);
    } else {
      insert_r(val);
    }
  }

  /// left または right のいずれかの SortedSet に `val` が見つかったとき、
  /// 見つかった方から 1 要素だけ削除する。
  inline bool erase(value_type const& val) {
    return erase_l(val) || erase_r(val);
  }

  inline void insert_l(value_type const& val) {
    _l.insert(val);
    _on_insert_l(val);
  }
  inline void insert_r(value_type const& val) {
    _r.insert(val);
    _on_insert_r(val);
  }

  inline bool erase_l(value_type const& val) {
    if (auto it = _l.find(val); it != _l.end()) {
      _l.erase(it);
      _on_erase_l(val);
      return true;
    }
    return false;
  }
  inline bool erase_r(value_type const& val) {
    if (auto it = _r.find(val); it != _r.end()) {
      _r.erase(it);
      _on_erase_r(val);
      return true;
    }
    return false;
  }

  inline value_type const& front() const {
    return lfront();
  }
  inline value_type const& back() const {
    return rback();
  }

  inline value_type const& lfront() const {
    return *_l.begin();
  }
  inline value_type const& lback() const {
    return *std::prev(_l.end());
  }
  inline value_type const& rfront() const {
    return *_r.begin();
  }
  inline value_type const& rback() const {
    return *std::prev(_r.end());
  }

  inline value_type&& pop_front() const {
    return pop_lfront();
  }
  inline value_type&& pop_back() const {
    return pop_rback();
  }

  inline value_type pop_lfront() {
    const auto v = std::move(_l.extract(_l.begin()).value());
    _on_erase_l(v);
    return v;
  }
  inline value_type pop_lback() {
    const auto v = std::move(_l.extract(std::prev(_l.end())).value());
    _on_erase_l(v);
    return v;
  }
  inline value_type pop_rfront() {
    const auto v = std::move(_r.extract(_r.begin()).value());
    _on_erase_r(v);
    return v;
  }
  inline value_type pop_rback() {
    const auto v = std::move(_r.extract(std::prev(_r.end())).value());
    _on_erase_r(v);
    return v;
  }

  inline void lshift() {
    auto v = pop_rfront();
    _l.insert(_l.end(), v);
    _on_insert_l(v);
  }

  inline void rshift() {
    auto v = pop_lback();
    _r.insert(_r.begin(), v);
    _on_insert_r(v);
  }

  void balance_lsize(size_t desired_lsize) {
    while (_l.size() > desired_lsize) rshift();
    while (_l.size() < desired_lsize && _r.size()) lshift();
  }

  void balance_rsize(size_t desired_rsize) {
    while (_r.size() > desired_rsize) lshift();
    while (_r.size() < desired_rsize && _l.size()) rshift();
  }

  inline size_t size() const {
    return _l.size() + _r.size();
  }

  inline size_t lsize() const {
    return _l.size();
  }

  inline size_t rsize() const {
    return _r.size();
  }

  inline auto const& lset() const {
    return _l;
  }

  inline auto const& rset() const {
    return _r;
  }
};
