#include <armkn/rangequery/cumulative_sum.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("CumulativeSum", "[rangequery]") {
  using vec = std::vector<int>;

  vec a{3, 1, 4, -7};
  auto csum = CumulativeSum<int>(a);
  CHECK(csum.data == vec{0, 3, 4, 8, 1});
  CHECK(csum.sum(0) == 0);
  CHECK(csum.sum(1) == 3);
  CHECK(csum.sum(4) == 1);
  CHECK(csum.sum(0, 0) == 0);
  CHECK(csum.sum(4, 4) == 0);
  CHECK(csum.sum(1, 3) == 5);
  CHECK(csum.sum(2, 4) == -3);
}
