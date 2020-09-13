#pragma once
#include <cassert>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <vector>

/**
 * @brief Union-Find (素集合データ構造)
 * @note path-compression + union-by-size
 */
class UnionFind {
private:
    int n;
    mutable std::vector<int> p;

public:
    UnionFind() = default;

    explicit UnionFind(int n_)
        : n(n_)
        , p(n_, -1) {}

    int unite(int x, int y) {
        assert(0 <= x && x < n), assert(0 <= y && y < n);
        x = leader(x), y = leader(y);
        if (x == y) return x;
        if (p[y] < p[x]) std::swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return x;
    }

    int leader(int x) const {
        assert(0 <= x && x < n);
        if (p[x] < 0) return x;
        return p[x] = leader(p[x]);
    }

    bool same(int x, int y) const {
        assert(0 <= x && x < n), assert(0 <= y && y < n);
        return leader(x) == leader(y);
    }

    int size(int x) const {
        assert(0 <= x && x < n);
        return -p[leader(x)];
    }

    std::vector<std::vector<int>> groups() const {
        std::vector<int> leaderBuf(n), groupSize(n);
        for (int i = 0; i < n; i++) ++groupSize[leaderBuf[i] = leader(i)];

        std::vector<std::vector<int>> result(n);
        for (int i = 0; i < n; i++) result[i].reserve(groupSize[i]);
        for (int i = 0; i < n; i++) result[leaderBuf[i]].push_back(i);
        result.erase(std::remove_if(result.begin(), result.end(), [](const std::vector<int>& v) { return v.empty(); }), result.end());
        return result;
    }
};
