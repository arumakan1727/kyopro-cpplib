#include <armkn/rangefold/cumulative_sum.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("CumulativeSum", "[rangefold]") {
  using vec = std::vector<int>;

  vec a{3, 1, 0, 0, 4, 7};
  auto csum = CumulativeSum<int>(a);
  CHECK(csum.data == vec{0, 3, 4, 4, 4, 8, 15});

  CHECK(csum.sum(0) == 0);
  CHECK(csum.sum(1) == 3);
  CHECK(csum.sum(6) == 15);
  CHECK(csum.sum(0, 0) == 0);
  CHECK(csum.sum(6, 6) == 0);
  CHECK(csum.sum(1, 3) == 1);
  CHECK(csum.sum(1, 5) == 5);
  CHECK(csum.sum(2, 6) == 11);

  CHECK(csum.lower_bound(0, 0) == 0);
  CHECK(csum.lower_bound(1, 0) == 1);
  CHECK(csum.lower_bound(2, 0) == 1);
  CHECK(csum.lower_bound(3, 0) == 1);
  CHECK(csum.lower_bound(4, 0) == 2);
  CHECK(csum.lower_bound(5, 0) == 5);

  CHECK(csum.lower_bound(0, 2) == 2);
  CHECK(csum.lower_bound(1, 2) == 5);
  CHECK(csum.lower_bound(2, 2) == 5);
  CHECK(csum.lower_bound(3, 2) == 5);
  CHECK(csum.lower_bound(4, 2) == 5);
  CHECK(csum.lower_bound(5, 2) == 6);
  CHECK(csum.lower_bound(10, 2) == 6);
  CHECK(csum.lower_bound(11, 2) == 6);
  CHECK(csum.lower_bound(12, 2) == 7);
}
