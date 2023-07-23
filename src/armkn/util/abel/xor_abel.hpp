#pragma once
#include <type_traits>

template <class T>
struct XorAbel {
  static_assert(std::is_integral_v<T>, "T must integer type!");
  T value;

  XorAbel() : value(0) {}

  XorAbel(T x) : value(x) {}

  inline XorAbel& operator+=(XorAbel rhs) noexcept {
    value ^= rhs.value;
    return *this;
  }

  inline XorAbel& operator-=(XorAbel rhs) noexcept {
    value ^= rhs.value;
    return *this;
  }

  inline const XorAbel operator+(XorAbel rhs) const noexcept {
    return XorAbel{value} += rhs;
  }

  inline const XorAbel operator-(XorAbel rhs) const noexcept {
    return XorAbel{value} -= rhs;
  }
};
