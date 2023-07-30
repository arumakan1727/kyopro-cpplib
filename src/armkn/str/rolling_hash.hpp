#pragma once
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <vector>

template <uint64_t Base>
struct SeqHash {
  uint64_t hash;
  uint64_t len;

  inline bool operator==(const SeqHash& rhs) const noexcept {
    return hash == rhs.hash && len == rhs.len;
  }
  inline bool operator!=(const SeqHash& rhs) const noexcept {
    return !operator==(rhs);
  }
};

template <uint64_t Base>
struct std::hash<SeqHash<Base>> {
  inline size_t operator()(const SeqHash<Base>& h) const {
    return h.hash;
  }
};

/// ローリングハッシュ; mod値 $2^{61} - 1$ 固定
/// @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
template <uint_fast64_t Base>
class RollingHash {
 public:
  using u64 = uint_fast64_t;
  using u128 = __uint128_t;
  using Hash = SeqHash<Base>;
  static constexpr u64 MOD = (1uLL << 61) - 1;
  static constexpr u64 BASE = Base;

  RollingHash() = default;

  template <class InputIter>
  RollingHash(InputIter begin, InputIter end) : _hash(std::distance(begin, end) + 1, 0) {
    if (pow_array.empty()) {
      pow_array.reserve(1e6);
      pow_array.emplace_back(1);
    }
    grow_pow_array(_hash.size());
    for (unsigned i = 0; begin != end; ++begin, ++i) {
      _hash[i + 1] = add(mul(_hash[i], BASE), *begin);
    }
  }

  /// もとの文字列の長さ
  inline size_t size() const {
    return _hash.size() - 1;
  }

  /// 文字列全体のハッシュ値
  inline Hash hash() const {
    return {_hash.back(), _hash.size() - 1};
  }

  /// [l, r) のハッシュ値
  inline Hash slice(size_t l, size_t r) const {
    assert(l <= r && r < _hash.size());
    const auto value = add(_hash[r], MOD - mul(_hash[l], pow_array[r - l]));
    return {value, r - l};
  }

  /// [l, l+len) のハッシュ値
  inline Hash substr(int l, size_t len) const {
    return slice(l, l + (int)len);
  }

  /// 連結文字列 (left_str + right_str) のハッシュ値
  static Hash concat(Hash left, Hash right) {
    grow_pow_array(right.len);
    const auto value = add(mul(left.hash, pow_array[right.len]), right.hash);
    return {value, left.len + right.len};
  }

 private:
  std::vector<u64> _hash;
  static inline std::vector<u64> pow_array;

  static constexpr inline u64 add(u64 a, u64 b) noexcept {
    if ((a += b) >= MOD) a -= MOD;
    return a;
  }

  static constexpr inline u64 mul(u128 a, u128 b) noexcept {
    const auto c = a * b;
    return add(static_cast<u64>(c >> 61), static_cast<u64>(c & MOD));
  }

  static inline void grow_pow_array(size_t len) {
    ++len;
    while (pow_array.size() < len) {
      pow_array.emplace_back(mul(pow_array.back(), BASE));
    }
  }
};
