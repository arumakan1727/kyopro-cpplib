#include <armkn/graph/model/weighted_graph.hpp>
#include <armkn/graph/tree/rooted_tree.hpp>
#include <catch2/catch_test_macros.hpp>

#include <vector>

TEST_CASE("RootedTree", "[tree]") {
  using std::vector;

  SECTION("unweighted graph") {
    vector<vector<u32>> g(9);
    g[0] = {3, 4, 6};
    g[1] = {3};
    g[2] = {3, 7};
    g[3] = {1, 2, 0};
    g[4] = {0};
    g[5] = {8};
    g[6] = {0};
    g[7] = {2};
    g[8] = {5};
    /*---------------------------
              0            8
          /   |   \        |
         3    4    6       5
       /   \
      1     2
             \
              7
    ---------------------------*/
    const auto rt = RootedTree(g);
    using vec = vector<u32>;
    CHECK(rt.parent[0] == RootedTree::NO_PARENT);
    CHECK(rt.parent[1] == 3);
    CHECK(rt.parent[2] == 3);
    CHECK(rt.parent[3] == 0);
    CHECK(rt.parent[4] == 0);
    CHECK(rt.parent[5] == RootedTree::NO_PARENT);
    CHECK(rt.parent[6] == 0);
    CHECK(rt.parent[7] == 2);
    CHECK(rt.parent[8] == 5);
    CHECK(rt.roots == vec{0, 5});
    CHECK(rt.size == vec{7, 1, 2, 4, 1, 2, 1, 1, 1});
    CHECK(rt.depth == vec{0, 2, 2, 1, 1, 0, 1, 3, 1});
  }

  SECTION("weighted graph") {
    WeightedGraph<int> g(9);
    using E = Edge<int>;
    g[0] = {E(3, -1), E(4, -1), E(6, -1)};
    g[1] = {E(3, -1)};
    g[2] = {E(3, -1), E(7, -1)};
    g[3] = {E(1, -1), E(2, -1), E(0, -1)};
    g[4] = {E(0, -1)};
    g[5] = {E(8, -1)};
    g[6] = {E(0, -1)};
    g[7] = {E(2, -1)};
    g[8] = {E(5, -1)};
    /*---------------------------
              0            8
          /   |   \        |
         3    4    6       5
       /   \
      1     2
             \
              7
    ---------------------------*/
    const auto rt = RootedTree(g);
    using vec = vector<u32>;
    CHECK(rt.parent[0] == RootedTree::NO_PARENT);
    CHECK(rt.parent[1] == 3);
    CHECK(rt.parent[2] == 3);
    CHECK(rt.parent[3] == 0);
    CHECK(rt.parent[4] == 0);
    CHECK(rt.parent[5] == RootedTree::NO_PARENT);
    CHECK(rt.parent[6] == 0);
    CHECK(rt.parent[7] == 2);
    CHECK(rt.parent[8] == 5);
    CHECK(rt.roots == vec{0, 5});
    CHECK(rt.size == vec{7, 1, 2, 4, 1, 2, 1, 1, 1});
    CHECK(rt.depth == vec{0, 2, 2, 1, 1, 0, 1, 3, 1});
  }
}
