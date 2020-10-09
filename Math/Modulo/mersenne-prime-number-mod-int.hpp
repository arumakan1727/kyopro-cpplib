#pragma once
#include <cassert>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <type_traits>

/**
 * @brief MersennePrimeNumberModInt (法がメルセンヌ素数のModInt特殊化)
 */
namespace internal {

template <class ModHolder>
class ModInt;

constexpr int exponentOfMersennePrimeNumber(uint_fast64_t x) {
    if (x == (1ull << 61) - 1) return 61;
    if (x == (1ull << 31) - 1) return 31;
    if (x == (1ull << 19) - 1) return 19;
    if (x == (1ull << 17) - 1) return 17;
    if (x == (1ull << 13) - 1) return 13;
    if (x == (1ull << 7) - 1) return 7;
    if (x == (1ull << 5) - 1) return 5;
    if (x == (1ull << 3) - 1) return 3;
    if (x == (1ull << 2) - 1) return 2;
    return -1;
}

template <uint_fast64_t Mod>
struct MersennePrimeNumberModHolder {
    static constexpr uint_fast64_t mod = Mod;
    static constexpr uint32_t exp = exponentOfMersennePrimeNumber(Mod);
    static_assert(exponentOfMersennePrimeNumber(Mod) != -1, "Mod value is not a mersenne prime number.");
};

template <uint_fast64_t Mod>
class ModInt<MersennePrimeNumberModHolder<Mod>> {
private:
    using u64 = uint_fast64_t;
    using i64 = int_fast64_t;
    using largeUint = std::conditional < Mod<(1ull << 31), u64, __uint128_t>;
    using ModHolder = MersennePrimeNumberModHolder<Mod>;
    u64 value;

public:
    constexpr inline ModInt() noexcept
        : value(0) {}

    constexpr inline ModInt(i64 v) noexcept
        : value(ModInt::normalized(v)) {}

    static constexpr inline const ModInt raw(u64 v) noexcept {
        ModInt ret;
        ret.value = v;
        return ret;
    }

    static constexpr ModInt nullopt() noexcept { return ModInt::raw(Mod); }

    constexpr bool isNull() const noexcept { return *this == ModInt::nullopt(); }

    static constexpr inline u64 mod() noexcept { return ModHolder::mod; }

    template <class T>
    constexpr explicit operator T() const noexcept {
        return static_cast<T>(value);
    }

    constexpr u64 val() const noexcept { return value; }

    constexpr ModInt& operator+=(const ModInt& rhs) noexcept {
        if ((value += rhs.value) >= mod()) value -= mod();
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& rhs) noexcept {
        if (value < rhs.value) value += mod();
        value -= rhs.value;
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& rhs) noexcept {
        value = mul(value, rhs.value);
        return *this;
    }
    constexpr ModInt& operator/=(const ModInt& rhs) noexcept { return *this *= rhs.inv(); }
    constexpr const ModInt inv() const noexcept { return ModInt(ModInt::inverse(value, mod())); }
    constexpr const ModInt operator+() const noexcept { return *this; }
    constexpr const ModInt operator-() const noexcept { return ModInt(-static_cast<i64>(value)); }

    constexpr const ModInt pow(i64 expv) const noexcept {
        u64 ret = 1, square = value;
        for (u64 p = std::abs(expv); p; p >>= 1) {
            if (p & 1) ret = mul(ret, square);
            square = mul(square, square);
        }
        return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);
    }

    friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.value == rhs.value; }
    friend constexpr bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.value != rhs.value; }
    friend constexpr const ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) += rhs; }
    friend constexpr const ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) -= rhs; }
    friend constexpr const ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }
    friend constexpr const ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) /= rhs; }

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
    static constexpr inline u64 applyMod_u64(u64 x) noexcept {
        x = (x >> ModHolder::exp) + (x & mod());
        if (x >= mod()) x -= mod();
        return x;
    }

    static constexpr inline u64 applyMod_largeUint(largeUint x) noexcept {
        u64 y = static_cast<u64>(x >> ModHolder::exp) + static_cast<u64>(x & mod());
        if (y >= mod()) y -= mod();
        return y;
    }

    static constexpr inline u64 mul(u64 a, u64 b) noexcept { return applyMod_largeUint(static_cast<largeUint>(a) * static_cast<largeUint>(b)); }

    static constexpr u64 normalized(i64 n) noexcept {
        if (n >= 0) return applyMod_u64(n);
        if (n < -mod()) n %= mod();
        return n += mod();
    }

    static constexpr i64 inverse(i64 a, i64 m) noexcept {
        i64 u = 0, v = 1;
        while (a != 0) {
            const auto t = m / a;
            static_cast<void>(m -= t * a), std::swap(m, a);
            static_cast<void>(u -= t * v), std::swap(u, v);
        }
        assert(m == 1);
        return u;
    }
};

}  // namespace internal

template <uint_fast64_t Mod>
using MersennePrimeNumberModInt = internal::ModInt<internal::MersennePrimeNumberModHolder<Mod>>;

using ModInt_2pow61_1 = MersennePrimeNumberModInt<(1ull << 61) - 1>;
