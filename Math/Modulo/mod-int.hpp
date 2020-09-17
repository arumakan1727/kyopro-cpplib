#pragma once
#include <cstdint>
#include <cassert>
#include <iostream>
#include <limits>

/**
 * @brief Mod-Int (コンパイル時mod型と実行時mod型)
 */
namespace impl {

template <class ModHolder>
class ModInt {
private:
    int64_t value;

public:
    constexpr ModInt()
        : value(0) {}
    constexpr ModInt(int64_t v)
        : value(ModInt::normalized(v)) {}

    static constexpr ModInt raw(int64_t v) {
        ModInt ret;
        ret.value = v;
        return ret;
    }

    static constexpr ModInt nullopt() { return ModInt::raw(std::numeric_limits<int64_t>::min()); }

    constexpr bool isNull() const { return *this == ModInt::nullopt(); }

    static constexpr int64_t mod() { return ModHolder::mod; }

    static int64_t setMod(int64_t m) {
        assert(m >= 1);
        return ModHolder::mod = m;
    }

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

    constexpr const ModInt pow(int64_t expv) const {
        int64_t ret = 1, square = value;
        for (uint64_t p = std::abs(expv); p; p >>= 1) {
            if (p & 1) (ret *= square) %= mod();
            (square *= square) %= mod();
        }
        return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);
    }

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
    static constexpr int64_t normalized(int64_t n) {
        n = (-mod() <= n && n < mod() ? n : n % mod());
        if (n < 0) n += mod();
        return n;
    }

    static constexpr int64_t inverse(int64_t a, int64_t m) {
        int64_t u = 0, v = 1;
        while (a != 0) {
            const auto t = m / a;
            static_cast<void>(m -= t * a), std::swap(m, a);
            static_cast<void>(u -= t * v), std::swap(u, v);
        }
        assert(m == 1);
        return u;
    }
};

template <int64_t Mod>
struct StaticModHolder {
    static constexpr int64_t mod = Mod;
};

template <auto ID>
struct DynamicModHolder {
    static int64_t mod;
};
template <auto ID>
int64_t DynamicModHolder<ID>::mod;

}  // namespace impl

template <int64_t Mod>
using StaticModInt = impl::ModInt<impl::StaticModHolder<Mod>>;

using ModInt1000000007 = StaticModInt<int(1e9) + 7>;
using ModInt998244353 = StaticModInt<998244353>;

template <auto ID>
using DynamicModInt = impl::ModInt<impl::DynamicModHolder<ID>>;
