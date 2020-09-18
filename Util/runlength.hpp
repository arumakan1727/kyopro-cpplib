#pragma once
#include <iterator>
#include <vector>
#include <utility>

/**
 * @brief runlength() (ランレングス圧縮)
 * (かたまりの始まり位置イテレータ, かたまりの要素数) のpairのvectorを返す。
 */
template <class Iterator>
auto runlength(Iterator const begin, Iterator const end) {
    std::vector<std::pair<Iterator, std::size_t>> ret;
    ret.reserve(std::distance(begin, end));

    for (auto itr = begin; itr != end;) {
        std::size_t cnt = 1;
        const auto head = itr++;
        while (itr != end && *itr == *head) ++itr, ++cnt;
        ret.emplace_back(head, cnt);
    }

    ret.shrink_to_fit();
    return ret;
}
