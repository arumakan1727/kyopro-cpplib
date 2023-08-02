#pragma once
#include <cstddef>
#include <type_traits>
#include <utility>
#include <vector>
#include "../../util/alias/stdint.hpp"

/// Floyd's Tortoise and Hare Algorithm
/// 写像 f は (T → T) でなければならない
/// サイクルが存在しない場合は無限ループする
template <class T>
class CycleFinder {
  u32 _until_cycle_start;
  u32 _cycle_len;
  std::vector<T> nf;  // nf[i] := `start` に `f` を `i` 回適用した結果

 public:
  CycleFinder() = default;

  template <class Fn, std::enable_if_t<std::is_invocable_r_v<T, Fn, T>, std::nullptr_t> = nullptr>
  CycleFinder(T start, Fn&& f, size_t capacity = 512) : _until_cycle_start(0), _cycle_len(0) {
    T tortoise = start, hare = start;
    do {
      tortoise = f(tortoise);
      hare = f(f(hare));
    } while (tortoise != hare);

    nf.reserve(capacity);
    nf.push_back(start);
    tortoise = start;
    while (tortoise != hare) {
      hare = f(hare);
      tortoise = f(tortoise);
      nf.push_back(tortoise);
      ++_until_cycle_start;
    }

    do {
      tortoise = f(tortoise);
      nf.push_back(tortoise);
      ++_cycle_len;
    } while (tortoise != hare);
    nf.shrink_to_fit();
  }

  /// mapping[x] を写像の適用 f(x) とみなす
  template <
      class IndexAccessible,
      class = std::void_t<decltype(std::declval<IndexAccessible>()[0])>>
  CycleFinder(T start, IndexAccessible const& mapping)
      : CycleFinder(
            start,
            [&](T x) { return (T)mapping[x]; },
            mapping.size() + 1
        ) {}

  inline u32 until_cycle_start() const {
    return _until_cycle_start;
  }

  inline u32 cycle_len() const {
    return _cycle_len;
  }

  /// start に f を n 回適用した結果を O(1) で求める
  inline const T apply_repeat(u64 n) const {
    if (n <= _until_cycle_start + _cycle_len) return nf[n];
    return nf[_until_cycle_start + (n - _until_cycle_start) % _cycle_len];
  }
};
