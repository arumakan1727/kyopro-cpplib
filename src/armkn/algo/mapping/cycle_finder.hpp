#pragma once
#include <cstddef>
#include <type_traits>
#include <utility>
#include <vector>

/// Floyd's Tortoise and Hare Algorithm
template <class T>
class CycleFinder {
  uint32_t _until_cycle_start;
  uint32_t _cycle_len;
  std::vector<T> nf;  // nf[i] := `start` から `f` を `i` 回適用した結果

 public:
  CycleFinder() = default;

  template <class Fn, std::enable_if_t<std::is_invocable_r_v<T, Fn, T>, std::nullptr_t> = nullptr>
  CycleFinder(T start, Fn&& f, std::size_t capacity = 512) : _until_cycle_start(0), _cycle_len(0) {
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
  }

  /// mapping[x] を写像 f(x) とみなす
  template <
      class IndexAccessible,
      class = std::void_t<decltype(std::declval<IndexAccessible>()[0])>>
  CycleFinder(T start, IndexAccessible const& mapping)
      : CycleFinder(
            start,
            [&](T x) { return (T)mapping[x]; },
            mapping.size() + 1
        ) {}

  inline uint32_t until_cycle_start() const {
    return _until_cycle_start;
  }

  inline uint32_t cycle_len() const {
    return _cycle_len;
  }

  /// start に f を n 回適用した結果を O(1) で求める。
  inline const T apply_repeat(uint64_t n) const {
    if (n <= _until_cycle_start + _cycle_len) return nf[n];
    return nf[_until_cycle_start + (n - _until_cycle_start) % _cycle_len];
  }
};
