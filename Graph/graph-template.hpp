#pragma once
#include <cstdint>
#include <vector>
#include <iostream>

/**
 * @brief graph-template (Edge, Graph, MatrixGraph)
 */
// グラフの辺 (重み付き)
template <class T>
struct Edge {
    int from, to;
    T weight;
    int id;

    Edge() = default;

    constexpr explicit Edge(int to_, const T& weight_)
        : Edge(-1, to_, weight_, -1) {}

    constexpr Edge(int from_, int to_, const T& weight_, int id_ = -1)
        : from(from_)
        , to(to_)
        , weight(weight_)
        , id(id_) {}

    constexpr const Edge rev() const { return Edge(to, from, weight, id); }

    template <class Int, std::enable_if_t<std::is_integral<Int>::value, std::nullptr_t> = nullptr>
    constexpr operator Int() const {
        return static_cast<Int>(to);
    }

    friend std::istream& operator>>(std::istream& is, Edge& e) { return is >> e.from >> e.to >> e.weight; }
};

// グラフの辺 (重みナシ)
template <>
struct Edge<void> {
    int from, to;
    int id;

    Edge() = default;

    constexpr explicit Edge(int to_)
        : Edge(-1, to_, -1) {}

    constexpr Edge(int from_, int to_, int id_ = -1)
        : from(from_)
        , to(to_)
        , id(id_) {}

    constexpr const Edge rev() const { return Edge(to, from, id); }

    template <class Int, std::enable_if_t<std::is_integral<Int>::value, std::nullptr_t> = nullptr>
    constexpr operator Int() const {
        return static_cast<Int>(to);
    }

    friend std::istream& operator>>(std::istream& is, Edge& e) { return is >> e.from >> e.to; }
};

// グラフ (隣接リスト実装)
template <class T>
using Graph = std::vector<std::vector<Edge<T>>>;
