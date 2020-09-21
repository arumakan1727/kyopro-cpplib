#pragma once

#include <vector>

/**
 * @brief divisorCountTable (約数の個数のテーブル, $O(N \log N)$)
 * cnt[i] = i の約数の個数; 範囲は閉区間 [0, N]
 */
std::vector<int> divisorCountTable(int N) {
    std::vector<int> cnt(N + 1);
    for (int d = 1; d <= N; ++d) {
        for (int i = d; i <= N; i += d) ++cnt[i];
    }
    return cnt;
}
