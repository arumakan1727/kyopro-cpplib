#pragma once
#include <cassert>
#include <cstdint>
#include <vector>
#include "../../util/alias/stdint.hpp"
#include "../adapter/edge_destination.hpp"

/// DFS により各ノードについて 親ノード、部分木のノード数、深さを求める。
/// - 重みつき・なし両方OK (`vector<vector<int>>` も可)。
/// - g は森でもOK。その場合は各連結成分ごとに根を決定してDFSする。
/// - 各連結成分内で番号が最小のノードをその木の根とする。
class RootedTree {
 public:
  static constexpr inline u32 NO_PARENT = static_cast<u32>(-1);
  /// 親頂点。根ノードの場合は `NO_PARENT` 。
  std::vector<u32> parent;
  /// 自分のノードを含む部分木のノード数。葉ノードの場合は1。
  std::vector<u32> size;
  /// 根からの深さ。根ノードの場合は0。
  std::vector<u32> depth;
  /// 根のリスト。昇順。全ノードが連結の場合は `roots.size() == 1` となる。
  std::vector<u32> roots;

  RootedTree() = default;

  template <class Edge>
  explicit RootedTree(std::vector<std::vector<Edge>> const& g)
      : parent(g.size()), size(g.size()), depth(g.size()) {
    roots.reserve(2);
    for (u32 v = 0; v < g.size(); ++v) {
      if (size[v] == 0) {
        roots.push_back(v);
        dfs(g, v, NO_PARENT, 0);
      }
    }
  }

  inline u32 is_root(u32 v) const {
    return depth[v] == 0;
  }

 private:
  template <class Edge>
  void dfs(std::vector<std::vector<Edge>> const& g, u32 v, u32 par, u32 dep) {
    const auto dest = EdgeDestinationAdapter{};
    size[v] = 1;
    parent[v] = par;
    depth[v] = dep;
    for (const auto& e : g[v]) {
      const auto to = dest(e);
      if (to != par) {
        dfs(g, to, v, dep + 1);
        size[v] += size[to];
      }
    }
  }
};
