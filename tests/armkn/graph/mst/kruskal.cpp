#include <armkn/graph/model/Edge3.hpp>
#include <armkn/graph/mst/kruskal.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("kruskal", "[graph][graph/mst]") {
  SECTION("basic") {
    const unsigned num_nodes = 7;
    std::vector<Edge3<int32_t>> edges = {
        Edge3(0, 1, 64),
        Edge3(0, 3, 512),
        Edge3(0, 6, 32),
        Edge3(1, 2, 8),
        Edge3(1, 5, 4),
        Edge3(2, 3, 2048),
        Edge3(2, 5, 2),
        Edge3(2, 6, 1),
        Edge3(3, 4, 128),
        Edge3(3, 5, 1024),
        Edge3(3, 6, 256),
        Edge3(4, 5, 0),
        Edge3(4, 6, 16),
    };
    const auto cost_sum = kruskal<int>(num_nodes, edges);
    CHECK(cost_sum == 0 + 1 + 2 + 4 + 32 + 128);
  }

  SECTION("edge weight: i32, kruskal computation: u64") {
    const unsigned num_nodes = 4;
    std::vector<Edge3<int32_t>> edges = {
        Edge3(0, 1, 1'000'000'001),
        Edge3(3, 2, 1'000'000'010),
        Edge3(2, 1, 1'000'000'100),
    };
    const auto cost_sum = kruskal<uint64_t>(num_nodes, edges);
    CHECK(cost_sum == 3'000'000'111);
  }
}
