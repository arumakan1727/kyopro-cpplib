#include <armkn/graph/adapter/edge_destination.hpp>
#include <armkn/graph/model/weighted_graph.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("EdgeDestinationAdapter", "[graph/adapter]") {
  const auto get_dest = EdgeDestinationAdapter{};

  SECTION("operator()(int)") {
    CHECK(get_dest(0) == 0);
    CHECK(get_dest(1) == 1);
    CHECK(get_dest(17273747) == 17273747);
  }

  SECTION("operator()(Edge)") {
    CHECK(get_dest(Edge(0, 5)) == 0);
    CHECK(get_dest(Edge(0, -1)) == 0);
    CHECK(get_dest(Edge(1727, "weight")) == 1727);
  }
}
