#include <armkn/math/integer/divisor_count_table.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("divisor_count_table", "[math][math/integer]") {
  auto table = divisor_count_table(16);
  auto want = std::vector<int>{
      0,  // [0]  : 0
      1,  // [1]  : 1
      2,  // [2]  : 1, 2
      2,  // [3]  : 1, 3
      3,  // [4]  : 1, 2, 4
      2,  // [5]  : 1, 5
      4,  // [6]  : 1, 2, 3, 6
      2,  // [7]  : 1, 7
      4,  // [8]  : 1, 2, 4, 8
      3,  // [9]  : 1, 3, 9
      4,  // [10] : 1, 2, 5, 10
      2,  // [11] : 1, 11
      6,  // [12] : 1, 2, 3, 4, 6, 12
      2,  // [13] : 1, 13
      4,  // [14] : 1, 2, 7, 14
      4,  // [15] : 1, 3, 5, 15
      5,  // [16] : 1, 2, 4, 8, 16
  };
  REQUIRE(table.size() == want.size());

  for (uint32_t i = 0; i < want.size(); ++i) {
    INFO("i = " << i);
    REQUIRE(table[i] == want[i]);
  }
}
