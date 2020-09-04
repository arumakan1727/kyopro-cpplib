#pragma once
#include <cstdint>
#include <utility>
#include <vector>

/**
 * @brief Union-Find (素集合データ構造)
 * @note path-compression + union-by-size
 */
class UnionFind {
private:
    mutable std::vector<int> p;

public:
    UnionFind() = default;

    explicit UnionFind(size_t n)
        : p(n, -1) {}

    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (p[y] < p[x]) std::swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }

    int root(int x) const {
        if (p[x] < 0) return x;
        return p[x] = root(p[x]);
    }

    bool same(int x, int y) const {
        return root(x) == root(y);
    }

    int size(int x) const {
        return -p[root(x)];
    }
};
