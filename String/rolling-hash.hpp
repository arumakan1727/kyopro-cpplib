#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <functional>

/**
 * @brief Rolling-Hash (ローリングハッシュ, mod値 $2^{61} - 1$ 固定)
 * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
 */
template <std::uint_fast64_t Base>
class RollingHash {
public:
    using u64 = std::uint_fast64_t;
    using u128 = __uint128_t;
    static constexpr u64 MOD = (1uL << 61) - 1;
    static constexpr u64 BASE = Base;

private:
    std::vector<u64> m_hash;

public:
    RollingHash() = default;

    template <class InputIter>
    RollingHash(InputIter begin, InputIter end)
        : m_hash(std::distance(begin, end) + 1, 0) {
        if (powArray().empty()) {
            powArray().reserve(1e6);
            powArray().emplace_back(1);
        }
        growPowArray(m_hash.size());

        std::size_t i;
        InputIter itr;
        for (itr = begin, i = 0; itr != end; ++itr, ++i) {
            m_hash[i + 1] = add(mul(m_hash[i], BASE), *itr);
        }
    }

    // 文字列全体のハッシュ値
    u64 hash() const { return m_hash.back(); }

    // 半開区間 [l, r) のハッシュ値
    u64 rangeHash(std::size_t l, std::size_t r) const {
        assert(l < r && r < m_hash.size());
        return add(m_hash[r], MOD - mul(m_hash[l], powArray()[r - l]));
    }

    // rangeHash(begin, begin + length) と等価
    u64 substr(std::size_t begin, std::size_t length) const { return rangeHash(begin, begin + length); }

    // もとの文字列の長さ
    std::size_t size() const { return m_hash.size() - 1; }

    // 連結した文字列 (leftStr + rightStr) のハッシュ値
    static u64 concat(u64 leftHash, u64 rightHash, std::size_t rightLength) {
        growPowArray(rightLength);
        return add(mul(leftHash, powArray()[rightLength]), rightHash);
    }

private:
    static inline std::vector<u64>& powArray() {
        static std::vector<u64> p;
        return p;
    }

    static constexpr inline u64 add(u64 a, u64 b) noexcept {
        if ((a += b) >= MOD) a -= MOD;
        return a;
    }

    static constexpr inline u64 mul(u128 a, u128 b) noexcept {
        const auto c = a * b;
        return add(static_cast<u64>(c >> 61), static_cast<u64>(c & MOD));
    }

    static inline void growPowArray(std::size_t len) {
        ++len;
        while (powArray().size() < len) {
            powArray().emplace_back(mul(powArray().back(), BASE));
        }
    }
};
