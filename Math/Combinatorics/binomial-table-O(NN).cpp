#pragma once
#include <vector>

/**
 * @brief binomialTable() (二項係数テーブル $O(N^2)$)
 * パスカルの三角形により N 以下の二項係数を求める。
 */
template <class T>
auto binomialTable(int N) {
    using std::vector;
    vector<vector<T>> binomial(N + 1);
    for (int i = 0; i <= N; ++i) {
        binomial[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i)
                binomial[i][j] = 1;
            else
                binomial[i][j] = binomial[i - 1][j - 1] + binomial[i - 1][j];
        }
    }
    return binomial;
}
