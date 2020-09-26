#pragma once

#include <cstdint>
#include <vector>
#include "./rolling-hash.hpp"

/**
 * @brief rabinKarp() (ラビンカープ法, RollingHashを用いた文字列検索 $O(|s|)$)
 * s の中で pattern が出現するインデックスを全て求めて vector として返す(インデックスは昇順)。
 */
template <uint_fast64_t Base>
std::vector<size_t> rabinKarp(const RollingHash<Base>& s, const RollingHash<Base>& pattern) {
    const auto sLen = s.size();
    const auto patLen = pattern.size();

    std::vector<size_t> foundIndexes;
    foundIndexes.reserve(sLen);

    for (size_t i = 0; i + patLen <= sLen; ++i) {
        if (s.substr(i, patLen) == pattern.hash()) foundIndexes.emplace_back(i);
    }

    foundIndexes.shrink_to_fit();
    return foundIndexes;
}
