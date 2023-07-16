#include <armkn/math/comb/binom_table.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("binom_table", "[math][math/comb]") {
  using vec = std::vector<std::vector<int64_t>>;
  CHECK(binom_table(1) == vec{{1}, {1, 1}});
  CHECK(binom_table(4) == vec{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}});
}
