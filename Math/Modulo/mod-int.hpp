#pragma once
#include <cassert>
#include <iostream>
#include <limits>
#include "../../Util/int-alias.hpp"

/**
 * @brief Mod-Int (コンパイル時mod型と実行時mod型)
 */
namespace impl {

template <class ModHolder>
class ModInt {
private:
    i64 value;

public:
    constexpr ModInt()
        : value(0) {}
    constexpr ModInt(i64 v)
        : value(ModInt::normalized(v)) {}

    static constexpr ModInt raw(i64 v) {
        ModInt ret;
        ret.value = v;
        return ret;
    }

    static constexpr ModInt nullopt = ModInt::raw(std::numeric_limits<i64>::min());

    constexpr bool isNull() const { return *this == ModInt::nullopt; }

    static constexpr i64 mod() { return ModHolder::mod; }

    static i64 setMod(i64 m) { return ModHolder::mod = m; }

    template <class T>
    constexpr explicit operator T() const {
        return static_cast<T>(value);
    }
    constexpr ModInt& operator+=(const ModInt& rhs) {
        if ((value += rhs.value) >= mod()) value -= mod();
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& rhs) {
        if ((value -= rhs.value) < 0) value += mod();
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& rhs) {
        (value *= rhs.value) %= mod();
        return *this;
    }
    constexpr ModInt& operator/=(const ModInt& rhs) { return *this *= rhs.inv(); }

    constexpr const ModInt inv() const { return ModInt(ModInt::inverse(value, mod())); }

    constexpr const ModInt operator+() const { return *this; }
    constexpr const ModInt operator-() const { return ModInt(-value); }

    friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) { return lhs.value == rhs.value; }
    friend constexpr bool operator!=(const ModInt& lhs, const ModInt& rhs) { return lhs.value != rhs.value; }
    friend constexpr const ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
    friend constexpr const ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
    friend constexpr const ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
    friend constexpr const ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) {
#ifdef LOCAL_DEBUG
        if (x.isNull()) return os << "{nullopt}";
#endif
        return os << x.value;
    }

    friend std::istream& operator>>(std::istream& is, ModInt& x) {
        is >> x.value;
        x.value = ModInt::normalized(x.value);
        return is;
    }

private:
    static constexpr i64 normalized(i64 n) {
        n = (-mod() <= n && n < mod() ? n : n % mod());
        if (n < 0) n += mod();
        return n;
    }

    static constexpr i64 inverse(i64 a, i64 m) {
        i64 u = 0, v = 1;
        while (a != 0) {
            const auto t = m / a;
            m -= t * a, std::swap(m, a);
            u -= t * v, std::swap(u, v);
        }
        assert(m == 1);
        return u;
    }
};

template <i64 Mod>
struct StaticModHolder {
    static constexpr i64 mod = Mod;
};

template <auto ID>
struct DynamicModHolder {
    static i64 mod;
};
template <auto ID>
i64 DynamicModHolder<ID>::mod;

}  // namespace impl

template <i64 Mod>
using StaticModInt = impl::ModInt<impl::StaticModHolder<Mod>>;

template <auto ID>
using DynamicModInt = impl::ModInt<impl::DynamicModHolder<ID>>;