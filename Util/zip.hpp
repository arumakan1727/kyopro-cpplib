#pragma once

#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>

/**
 * @brief zip() (n個のvectorからn要素のタプルのvectorを生成する)
 */
template <class T1, class T2>
std::vector<std::pair<T1, T2>> zip(const std::vector<T1>& v1, const std::vector<T2>& v2) {
    const auto sz = std::min(v1.size(), v2.size());
    std::vector<std::pair<T1, T2>> ret(sz);
    for (std::size_t i = 0; i < sz; ++i) ret[i] = std::make_pair(v1[i], v2[i]);
    return ret;
}

template <class T1, class T2, class T3>
std::vector<std::tuple<T1, T2, T3>> zip(const std::vector<T1>& v1, const std::vector<T2>& v2, const std::vector<T3>& v3) {
    const auto sz = std::min({v1.size(), v2.size(), v3.size()});
    std::vector<std::tuple<T1, T2, T3>> ret(sz);
    for (std::size_t i = 0; i < sz; ++i) ret[i] = std::make_tuple(v1[i], v2[i], v3[i]);
    return ret;
}
