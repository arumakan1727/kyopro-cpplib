#pragma once
#include <cassert>
#include <functional>
#include <queue>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../Util/at.hpp"
#include "../../Util/chminmax.hpp"
#include "../../Util/int-infinity.hpp"

/**
 * @brief dijkstra() (ダイクストラ, $O((V + E)\log V)$)
 *
 * @param dist:
 *      start からの距離を格納する配列。
 *      要素数は頂点数以上でなければならない。INFなどのでかい値でfillされている必要がある。
 *      多次元配列でもOK。
 *
 * @param start:
 *      頂点を表すdistの添字。
 *      distが一次元配列なら整数型,
 *      distが二次元配列ならstd::pair<integer, integer> または std::tuple<integer, integer> または std::array<integer, 2>,
 *      distが三次元配列ならstd::tuple<integer, integer, integer> または std::array<integer, 3>。
 *      start = {i, j, k} のとき dist[i][j][k] でアクセスする。
 *
 * @param enumerateNextVertex:
 *      fn(from: Vertex, fn(to: Vertex, w: EdgeWeight) => void) => void
 *      第一引数にVertex, 第二引数に関数をとる関数。
 *      この関数が第一引数の頂点fromから次の頂点の遷移先を列挙し、第二引数に渡すことで dijkstra() に遷移処理を委譲する。
 */
template <class DistArray, class Vertex, class NextVertexEnumerator>
DistArray dijkstra(DistArray&& dist, Vertex start, NextVertexEnumerator enumerateNextVertex) {
    using arumakan::at;
    assert(!dist.empty());
    assert(at(dist, start) >= INF);
    using WeightType = typename std::remove_reference_t<decltype(at(dist, start))>;
    using P = std::pair<WeightType, Vertex>;

    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    que.emplace(at(dist, start) = WeightType(), start);

    while (!que.empty()) {
        const auto curDist = que.top().first;
        const auto curVertex = que.top().second;
        que.pop();
        if (at(dist, curVertex) < curDist) continue;
        enumerateNextVertex(curVertex, [&](auto nxtVertex, auto edgeWeight) {
            if (chmin(at(dist, nxtVertex), curDist + edgeWeight)) {
                que.emplace(curDist + edgeWeight, nxtVertex);
            }
        });
    }
    return dist;
}

