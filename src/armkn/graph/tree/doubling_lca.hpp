#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include "../../util/alias/stdint.hpp"
#include "../../util/fn/ilog2.hpp"

/// ダブリングにより最近共通祖先を求める
/// - 与えられるグラフを森とみなして連結成分ごとにDFSして根付き木とする
class DoublingLCA {
  std::vector<u32> dep;
  std::vector<u32> sz;
  std::vector<std::vector<u32>> p;

  // ノード u から子ノードへ潜る直前に `hook_pre_visit_child(u, edge, dep[u])` を呼び出す
  template <class Edge, class HookFn>
  void dfs(
      std::vector<std::vector<Edge>> const& g,
      u32 u,
      u32 par,
      u32 d,
      HookFn const& hook_pre_visit_child
  ) {
    p[0][u] = par;
    dep[u] = d;
    sz[u] = 1;
    for (const auto& e : g[u]) {
      const auto to = u32(e);
      if (to != par) {
        hook_pre_visit_child(u, e, d);
        dfs(g, to, u, d + 1, hook_pre_visit_child);
        sz[u] += sz[to];
      }
    }
  }

 public:
  DoublingLCA() = default;

  template <class Edge>
  explicit DoublingLCA(std::vector<std::vector<Edge>> const& g)
      : DoublingLCA(g, [](u32 /*node*/, Edge const& /*e*/, u32 /*depth*/) {}) {}

  // DFS の際、現在ノード `u` から子ノードへ潜る直前に
  // `hook_pre_visit_child(u, edge, depth(u))` を呼び出す;
  // (用途例) 根からの辺重み累積和を計算したいとき
  template <class Edge, class DFSHookFn>
  explicit DoublingLCA(std::vector<std::vector<Edge>> const& g, DFSHookFn&& hook_pre_visit_child)
      : dep(g.size()), sz(g.size()), p(1, std::vector<u32>(g.size())) {
    const auto n = g.size();
    u32 max_dep = 0;
    for (u32 u = 0; u < n; ++u) {
      if (dep[u] == 0) {
        dfs(g, u, u, 0, hook_pre_visit_child);  // root の parent は root とする
      } else {
        max_dep = std::max(max_dep, dep[u]);
      }
    }
    const u32 z = ilog2(max_dep) + 2;
    p.resize(z, std::vector<u32>(n));
    for (u32 k = 0; k + 1 < z; ++k) {
      for (u32 u = 0; u < n; ++u) p[k + 1][u] = p[k][p[k][u]];
    }
  }

  inline u32 parent(u32 u) const noexcept {
    return p[0][u];
  }

  inline u32 depth(u32 u) const noexcept {
    return dep[u];
  }

  /// ノード総数
  inline std::size_t size() const noexcept {
    return dep.size();
  }

  /// uを根とした部分木のノード数
  inline u32 size(u32 u) const noexcept {
    return sz[u];
  }

  u32 lca(u32 a, u32 b) const noexcept {
    if (dep[a] > dep[b]) std::swap(a, b);
    b = climb(b, dep[b] - dep[a]);
    if (a == b) return a;
    for (u32 k = ilog2(dep[a]) + 1; k--;) {
      if (p[k][a] != p[k][b]) {
        a = p[k][a];
        b = p[k][b];
      }
    }
    return p[0][a];
  }

  /// u から根へ k 回登った先のノード; `k > depth(u)` の場合は root を返す
  inline u32 climb(u32 u, u32 k) const noexcept {
    k = std::min(k, dep[u]);
    for (u32 i = 0; k > 0; ++i, k >>= 1) {
      if (k & 1) u = p[i][u];
    }
    return u;
  }

  /// a から b までの辺の数
  inline u32 dist(u32 a, u32 b) const noexcept {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
  }
};
