#pragma once
#include <cassert>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

#include "../../Util/at.hpp"
#include "../../Util/int-infinity.hpp"

/**
 * @brief bfs() (幅優先探索による単一始点最短経路, 次元拡張に対応)
 *
 * @param dist:
 *      start からの距離を格納する配列。
 *      要素数は頂点数以上でなければならない。-1やINFなど、距離として正当でない値でfillされている必要がある。
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
 *      fn(from: Vertex, fn(to: Vertex) => void) => void
 *      第一引数にVertex, 第二引数に関数をとる関数。
 *      この関数が第一引数の頂点fromから次の頂点の遷移先を列挙し、第二引数に渡すことで bfs() に遷移処理を委譲する。
 */
template <class DistArray, class Vertex, class NextVertexEnumerator>
DistArray bfs(DistArray&& dist, Vertex start, NextVertexEnumerator enumerateNextVertex) {
    using arumakan::at;
    assert(!dist.empty());
    assert(at(dist, start) == -1 || at(dist, start) >= INF);

    std::queue<Vertex> que({start});
    const auto yetReachedMarker = at(dist, start);
    at(dist, start) = 0;
    while (!que.empty()) {
        const Vertex v = std::move(que.front());
        que.pop();
        const auto curDist = at(dist, v);
        enumerateNextVertex(v, [&](Vertex nxt) {
            if (at(dist, nxt) == yetReachedMarker) {
                at(dist, nxt) = curDist + 1;
                que.push(nxt);
            }
        });
    }
    return dist;
}
