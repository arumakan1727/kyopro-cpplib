#include <armkn/rangefold/cumulative_sum_2d.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("CumulativeSum2D", "[rangefold]") {
  using std::vector;
  const vector<vector<int8_t>> a{
      {100, 120, -30, 100},
      {100, 105, 101, 100},
      {-50, 0, -30, 100},
  };

  const auto c = CumulativeSum2D<int>(a);
  CHECK(c.sum(0, 0, 3, 4) == 716);

  CHECK(c.sum(0, 0, 1, 4) == 100 + 120 + -30 + 100);
  CHECK(c.sum(0, 0, 3, 1) == 100 + 100 + -50);

  CHECK(c.sum(1, 2, 3, 4) == 101 + 100 + -30 + 100);
  CHECK(c.sum(1, 2, 2, 3) == 101);
  CHECK(c.sum(2, 3, 3, 4) == 100);

  CHECK(c.sum(0, 0, 0, 0) == 0);
  CHECK(c.sum(3, 4, 3, 4) == 0);
}
