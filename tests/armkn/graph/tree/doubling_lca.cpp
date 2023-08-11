#include <armkn/graph/model/weighted_graph.hpp>
#include <armkn/graph/tree/doubling_lca.hpp>
#include <catch2/catch_test_macros.hpp>

#include <string>
#include <tuple>
#include <vector>

TEST_CASE("DoublingLCA") {
  using std::vector;

  SECTION("forest-1") {
    /*-------------------------------------
          2-4-11-9-8     10
         /             /
    0-1-5             3
         \             \
          6             7
    -------------------------------------*/
    const vector<vector<int>> g{
        {1},        // [0]
        {0, 5},     // [1]
        {5, 4},     // [2]
        {7, 10},    // [3]
        {2, 11},    // [4]
        {1, 6, 2},  // [5]
        {5},        // [6]
        {3},        // [7]
        {9},        // [8]
        {11, 8},    // [9]
        {3},        // [10]
        {4, 9},     // [11]
    };
    const auto h = DoublingLCA(g);

    REQUIRE(h.size() == g.size());
    REQUIRE(h.parent(0) == 0);
    REQUIRE(h.parent(1) == 0);
    REQUIRE(h.parent(2) == 5);
    REQUIRE(h.parent(3) == 3);
    REQUIRE(h.parent(4) == 2);
    REQUIRE(h.parent(5) == 1);
    REQUIRE(h.parent(6) == 5);
    REQUIRE(h.parent(7) == 3);
    REQUIRE(h.parent(8) == 9);
    REQUIRE(h.parent(9) == 11);
    REQUIRE(h.parent(10) == 3);
    REQUIRE(h.parent(11) == 4);

    CHECK(h.size(0) == 9);
    CHECK(h.size(1) == 8);
    CHECK(h.size(2) == 5);
    CHECK(h.size(3) == 3);
    CHECK(h.size(4) == 4);
    CHECK(h.size(5) == 7);
    CHECK(h.size(6) == 1);
    CHECK(h.size(7) == 1);
    CHECK(h.size(8) == 1);
    CHECK(h.size(9) == 2);
    CHECK(h.size(10) == 1);
    CHECK(h.size(11) == 3);

    CHECK(h.depth(0) == 0);
    CHECK(h.depth(1) == 1);
    CHECK(h.depth(2) == 3);
    CHECK(h.depth(3) == 0);
    CHECK(h.depth(4) == 4);
    CHECK(h.depth(5) == 2);
    CHECK(h.depth(6) == 3);
    CHECK(h.depth(7) == 1);
    CHECK(h.depth(8) == 7);
    CHECK(h.depth(9) == 6);
    CHECK(h.depth(10) == 1);
    CHECK(h.depth(11) == 5);
    INFO("depth(u) done");

    CHECK(h.climb(0, 0) == 0);
    CHECK(h.climb(0, 1) == 0);
    CHECK(h.climb(0, 1000000000) == 0);
    INFO("climb(0, x) done");
    CHECK(h.climb(1, 0) == 1);
    CHECK(h.climb(1, 1) == 0);
    CHECK(h.climb(1, 2) == 0);
    CHECK(h.climb(1, 3) == 0);
    CHECK(h.climb(1, 1000000000) == 0);
    INFO("climb(1, x) done");
    CHECK(h.climb(2, 0) == 2);
    CHECK(h.climb(2, 1) == 5);
    CHECK(h.climb(2, 2) == 1);
    CHECK(h.climb(2, 3) == 0);
    CHECK(h.climb(2, 4) == 0);
    CHECK(h.climb(2, 5) == 0);
    CHECK(h.climb(2, 1000000000) == 0);
    INFO("climb(2, x) done");
    CHECK(h.climb(3, 0) == 3);
    CHECK(h.climb(3, 1) == 3);
    CHECK(h.climb(3, 2) == 3);
    CHECK(h.climb(3, 3) == 3);
    CHECK(h.climb(3, 4) == 3);
    CHECK(h.climb(3, 5) == 3);
    CHECK(h.climb(3, 1000000000) == 3);
    INFO("climb(3, x) done");
    CHECK(h.climb(4, 0) == 4);
    CHECK(h.climb(4, 1) == 2);
    CHECK(h.climb(4, 2) == 5);
    CHECK(h.climb(4, 3) == 1);
    CHECK(h.climb(4, 4) == 0);
    CHECK(h.climb(4, 5) == 0);
    CHECK(h.climb(4, 1000000000) == 0);
    INFO("climb(4, x) done");
    CHECK(h.climb(5, 0) == 5);
    CHECK(h.climb(5, 1) == 1);
    CHECK(h.climb(5, 2) == 0);
    CHECK(h.climb(5, 3) == 0);
    CHECK(h.climb(5, 4) == 0);
    CHECK(h.climb(5, 5) == 0);
    CHECK(h.climb(5, 1000000000) == 0);
    INFO("climb(5, x) done");
    CHECK(h.climb(6, 0) == 6);
    CHECK(h.climb(6, 1) == 5);
    CHECK(h.climb(6, 2) == 1);
    CHECK(h.climb(6, 3) == 0);
    CHECK(h.climb(6, 4) == 0);
    CHECK(h.climb(6, 5) == 0);
    CHECK(h.climb(6, 1000000000) == 0);
    INFO("climb(6, x) done");
    CHECK(h.climb(7, 0) == 7);
    CHECK(h.climb(7, 1) == 3);
    CHECK(h.climb(7, 2) == 3);
    CHECK(h.climb(7, 3) == 3);
    CHECK(h.climb(7, 4) == 3);
    CHECK(h.climb(7, 5) == 3);
    CHECK(h.climb(7, 1000000000) == 3);
    INFO("climb(7, x) done");
    CHECK(h.climb(8, 0) == 8);
    CHECK(h.climb(8, 1) == 9);
    CHECK(h.climb(8, 2) == 11);
    CHECK(h.climb(8, 3) == 4);
    CHECK(h.climb(8, 4) == 2);
    CHECK(h.climb(8, 5) == 5);
    CHECK(h.climb(8, 6) == 1);
    CHECK(h.climb(8, 7) == 0);
    CHECK(h.climb(8, 8) == 0);
    CHECK(h.climb(8, 9) == 0);
    CHECK(h.climb(8, 1000000000) == 0);
    INFO("climb(8, x) done");
    CHECK(h.climb(9, 0) == 9);
    CHECK(h.climb(9, 1) == 11);
    CHECK(h.climb(9, 2) == 4);
    CHECK(h.climb(9, 3) == 2);
    CHECK(h.climb(9, 4) == 5);
    CHECK(h.climb(9, 5) == 1);
    CHECK(h.climb(9, 6) == 0);
    CHECK(h.climb(9, 7) == 0);
    CHECK(h.climb(9, 8) == 0);
    CHECK(h.climb(9, 1000000000) == 0);
    INFO("climb(9, x) done");
    CHECK(h.climb(10, 0) == 10);
    CHECK(h.climb(10, 1) == 3);
    CHECK(h.climb(10, 2) == 3);
    CHECK(h.climb(10, 3) == 3);
    CHECK(h.climb(10, 4) == 3);
    CHECK(h.climb(10, 5) == 3);
    CHECK(h.climb(10, 1000000000) == 3);
    INFO("climb(10, x) done");
    CHECK(h.climb(11, 0) == 11);
    CHECK(h.climb(11, 1) == 4);
    CHECK(h.climb(11, 2) == 2);
    CHECK(h.climb(11, 3) == 5);
    CHECK(h.climb(11, 4) == 1);
    CHECK(h.climb(11, 5) == 0);
    CHECK(h.climb(11, 6) == 0);
    CHECK(h.climb(11, 7) == 0);
    CHECK(h.climb(11, 1000000000) == 0);
    INFO("climb(11, x) done");

    CHECK(h.lca(0, 0) == 0);
    CHECK(h.lca(1, 1) == 1);
    CHECK(h.lca(3, 3) == 3);
    CHECK(h.lca(11, 11) == 11);

    CHECK(h.lca(5, 0) == 0);
    CHECK(h.lca(5, 1) == 1);
    CHECK(h.lca(5, 2) == 5);
    // CHECK(h.lca(5, 3) == 0);  // not same root
    CHECK(h.lca(5, 4) == 5);
    CHECK(h.lca(5, 5) == 5);
    CHECK(h.lca(5, 6) == 5);
    // CHECK(h.lca(5, 7) == 0);  // not same root
    CHECK(h.lca(5, 8) == 5);
    CHECK(h.lca(5, 9) == 5);
    // CHECK(h.lca(5, 10) == 0);  // not same root
    CHECK(h.lca(5, 11) == 5);

    CHECK(h.lca(6, 2) == 5);
    CHECK(h.lca(6, 4) == 5);
    CHECK(h.lca(6, 11) == 5);
    CHECK(h.lca(6, 9) == 5);
    CHECK(h.lca(6, 8) == 5);

    CHECK(h.lca(2, 6) == 5);
    CHECK(h.lca(4, 6) == 5);
    CHECK(h.lca(11, 6) == 5);
    CHECK(h.lca(9, 6) == 5);
    CHECK(h.lca(8, 6) == 5);

    CHECK(h.lca(3, 7));
    CHECK(h.lca(3, 10));
    CHECK(h.lca(7, 10));
    CHECK(h.lca(10, 7));

    CHECK(h.lca(2, 8) == 2);
    CHECK(h.lca(8, 2) == 2);
    CHECK(h.lca(2, 9) == 2);
    CHECK(h.lca(9, 2) == 2);
  }

  SECTION("constructor with hook_pre_visit_child(u, edge, depth(u))") {
    /*-------------------------------------
         1
        /
    0--2--5   4--6
       \
        3--7
    -------------------------------------*/
    using E = Edge<int>;
    WeightedGraph<int> g{
        {E{2, 1001}},                                      // [0]
        {E{2, 1002}},                                      // [1]
        {E{0, 1003}, E{1, 1004}, E{3, 1005}, E{5, 1006}},  // [2]
        {E{2, 1007}, E{7, 1008}},                          // [3]
        {E{6, 1009}},                                      // [4]
        {E{2, 1010}},                                      // [5]
        {E{4, 1011}},                                      // [6]
        {E{3, 1012}},                                      // [7]
    };

    using T = std::tuple<u32, E, u32>;
    vector<T> history;
    const auto h = DoublingLCA(g, [&](u32 u, Edge<int> const& e, u32 depth) {
      history.emplace_back(u, e, depth);
    });

    REQUIRE(h.size() == 8);

    const vector<T> want{
        T{0, E(2, 1001), 0},
        T{2, E(1, 1004), 1},
        T{2, E(3, 1005), 1},
        T{3, E(7, 1008), 2},
        T{2, E(5, 1006), 1},
        T{4, E(6, 1009), 0},
    };
    CHECK(history == want);
  }

  SECTION("perfect binary tree") {
    /*-------------------------------------
            31
          15
            30
        7
            29
          14
            28
      3- - - - - -
            27
          13
            26
        6
            25
          12
            24
    1- - - - - - -              0
            23
          11
            22
        5
            21
          10
            20
      2- - - - - -
            19
          9
            18
        4
            17
          8
            16
    -------------------------------------*/
    constexpr u32 K = 5;
    vector<vector<u32>> g((1 << K));
    for (u32 i = 1; i < (1 << (K - 1)); ++i) {
      g[i].push_back((i << 1));
      g[i].push_back((i << 1) | 1);
      g[i << 1].push_back(i);
      g[i << 1 | 1].push_back(i);
    }
    const auto h = DoublingLCA(g);
    REQUIRE(h.size() == 32);
    REQUIRE(h.size(0) == 1);
    REQUIRE(h.size(1) == 31);
    CHECK(h.depth(0) == 0);
    CHECK(h.depth(1) == 0);
    CHECK(h.depth(2) == 1);
    CHECK(h.depth(3) == 1);
    CHECK(h.depth(4) == 2);
    CHECK(h.depth(7) == 2);
    CHECK(h.depth(8) == 3);
    CHECK(h.depth(15) == 3);
    CHECK(h.depth(16) == 4);
    CHECK(h.depth(31) == 4);

    CHECK(h.parent(0) == 0);
    CHECK(h.parent(1) == 1);
    CHECK(h.parent(16) == 8);
    CHECK(h.parent(17) == 8);
    CHECK(h.parent(31) == 15);

    CHECK(h.climb(31, 0) == 31);
    CHECK(h.climb(31, 1) == 15);
    CHECK(h.climb(31, 2) == 7);
    CHECK(h.climb(31, 3) == 3);
    CHECK(h.climb(31, 4) == 1);
    CHECK(h.climb(31, 5) == 1);
    CHECK(h.climb(31, 6) == 1);
    CHECK(h.climb(31, 7) == 1);
    CHECK(h.climb(31, 8) == 1);
    CHECK(h.climb(31, 1000000000) == 1);

    CHECK(h.climb(10, 0) == 10);
    CHECK(h.climb(10, 1) == 5);
    CHECK(h.climb(10, 2) == 2);
    CHECK(h.climb(10, 3) == 1);
    CHECK(h.climb(10, 4) == 1);

    CHECK(h.climb(12, 0) == 12);
    CHECK(h.climb(12, 1) == 6);
    CHECK(h.climb(12, 2) == 3);
    CHECK(h.climb(12, 3) == 1);
    CHECK(h.climb(12, 4) == 1);

    CHECK(h.lca(1, 1) == 1);
    CHECK(h.lca(16, 31) == 1);
    CHECK(h.lca(16, 9) == 4);
    CHECK(h.lca(23, 16) == 2);
    CHECK(h.lca(5, 16) == 2);
    CHECK(h.lca(10, 1) == 1);
    CHECK(h.lca(5, 10) == 5);
    CHECK(h.lca(10, 9) == 2);

    CHECK(h.lca(10, 8) == 2);
    CHECK(h.lca(10, 9) == 2);
    CHECK(h.lca(10, 10) == 10);
    CHECK(h.lca(10, 11) == 5);
    CHECK(h.lca(10, 12) == 1);
    CHECK(h.lca(10, 13) == 1);
    CHECK(h.lca(10, 14) == 1);
    CHECK(h.lca(10, 15) == 1);

    CHECK(h.lca(25, 8) == 1);
    CHECK(h.lca(25, 9) == 1);
    CHECK(h.lca(25, 10) == 1);
    CHECK(h.lca(25, 11) == 1);
    CHECK(h.lca(25, 12) == 12);
    CHECK(h.lca(25, 13) == 6);
    CHECK(h.lca(25, 14) == 3);
    CHECK(h.lca(25, 15) == 3);

    CHECK(h.lca(25, 16) == 1);
    CHECK(h.lca(25, 17) == 1);
    CHECK(h.lca(25, 18) == 1);
    CHECK(h.lca(25, 19) == 1);
    CHECK(h.lca(25, 20) == 1);
    CHECK(h.lca(25, 21) == 1);
    CHECK(h.lca(25, 22) == 1);
    CHECK(h.lca(25, 23) == 1);
    CHECK(h.lca(25, 24) == 12);
    CHECK(h.lca(25, 25) == 25);
    CHECK(h.lca(25, 26) == 6);
    CHECK(h.lca(25, 27) == 6);
    CHECK(h.lca(25, 28) == 3);
    CHECK(h.lca(25, 29) == 3);
    CHECK(h.lca(25, 30) == 3);
    CHECK(h.lca(25, 31) == 3);
  }
}
