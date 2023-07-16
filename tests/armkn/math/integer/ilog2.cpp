#include <armkn/math/integer/ilog2.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("ilog2", "[math][math/integer]") {
  CHECK(ilog2(1) == 0);
  CHECK(ilog2(2) == 1);
  CHECK(ilog2(3) == 1);
  CHECK(ilog2(4) == 2);
  CHECK(ilog2(5) == 2);
  CHECK(ilog2(6) == 2);
  CHECK(ilog2(7) == 2);
  CHECK(ilog2(8) == 3);
  CHECK(ilog2((1u << 31) - 1) == 30);
  CHECK(ilog2((1u << 31) + 0) == 31);
  CHECK(ilog2((1u << 31) + 1) == 31);
}
