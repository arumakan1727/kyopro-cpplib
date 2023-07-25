#pragma once
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <type_traits>

template <uint32_t M>
class StaticModInt {
  static_assert(M < std::numeric_limits<uint32_t>::max() / 2);
  uint32_t value;

 public:
  using value_type = uint32_t;

  constexpr StaticModInt() : value(0) {}

  template <typename T, std::enable_if_t<std::is_signed_v<T>>* = nullptr>
  constexpr StaticModInt(T n)
      : value(static_cast<value_type>((n %= static_cast<int64_t>(M)) < 0 ? n + M : n)) {}

  template <typename T, std::enable_if_t<std::is_unsigned_v<T>>* = nullptr>
  constexpr StaticModInt(T n) : value(static_cast<value_type>(n % M)) {}

  template <typename T>
  constexpr static StaticModInt<M> raw(T n) {
    StaticModInt<M> ret;
    ret.value = (value_type)n;
    return ret;
  }

  inline static constexpr auto MOD = M;

  static const StaticModInt<M> NIL;

  inline constexpr bool is_nil() {
    return this->value == NIL.value;
  }

  template <typename T>
  inline constexpr explicit operator T() const {
    return T(value);
  }

  inline StaticModInt& operator+=(const StaticModInt rhs) {
    if ((value += rhs.value) >= M) value -= M;
    return *this;
  }
  inline StaticModInt& operator-=(const StaticModInt rhs) {
    if (value < rhs.value) value += M;
    value -= rhs.value;
    return *this;
  }
  inline StaticModInt& operator*=(const StaticModInt rhs) {
    value = uint32_t(uint64_t(value) * rhs.value % M);
    return *this;
  }
  inline StaticModInt& operator/=(const StaticModInt rhs) {
    return *this *= rhs.inv();
  }

  inline constexpr const StaticModInt inv() const {
    value_type a = value, b = M;
    int u = 1, v = 0;
    while (b > 0) {
      const auto t = a / b;
      std::swap(a -= b * t, b);
      std::swap(u -= v * (int)t, v);
    }
    return StaticModInt(u);
  }

  constexpr const StaticModInt pow(int64_t p) const {
    StaticModInt ret = 1u, doubled = *this;
    if (p < 0) {
      p = -p;
      doubled = doubled.inv();
    }
    while (p) {
      if (p & 1) ret *= doubled;
      doubled *= doubled;
      p >>= 1;
    }
    return ret;
  }
  const StaticModInt operator+() const {
    return *this;
  }
  const StaticModInt operator-() const {
    return StaticModInt::raw(M - value);
  }

  friend bool operator==(const StaticModInt lhs, const StaticModInt rhs) {
    return lhs.value == rhs.value;
  }
  friend bool operator!=(const StaticModInt lhs, const StaticModInt rhs) {
    return !(lhs == rhs);
  }
  friend std::ostream& operator<<(std::ostream& os, const StaticModInt n) {
    return os << n.value;
  }
  friend std::istream& operator>>(std::istream& is, StaticModInt& n) {
    int64_t tmp;
    is >> tmp;
    n = StaticModInt(tmp);
    return is;
  }

#define EMIT_OP_METHOD(op, impl_op)                                                 \
  friend const StaticModInt operator op(StaticModInt lhs, const StaticModInt rhs) { \
    return lhs impl_op rhs;                                                         \
  }
  EMIT_OP_METHOD(+, +=);
  EMIT_OP_METHOD(-, -=);
  EMIT_OP_METHOD(*, *=);
  EMIT_OP_METHOD(/, /=);
#undef EMIT_OP_METHOD
};

template <uint32_t M>
constexpr StaticModInt<M> StaticModInt<M>::NIL =
    StaticModInt<M>::raw(std::numeric_limits<StaticModInt<M>::value_type>::max());

using ModInt998244353 = StaticModInt<998244353>;
using ModInt1000000007 = StaticModInt<1000'000'007>;
