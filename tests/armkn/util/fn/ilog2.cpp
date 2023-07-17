#include <armkn/util/fn/ilog2.hpp>
#include <catch2/catch_test_macros.hpp>
#include <limits>

TEST_CASE("ilog2", "[util]") {
  CHECK(ilog2(1) == 0);
  CHECK(ilog2(2) == 1);
  CHECK(ilog2(3) == 1);
  CHECK(ilog2(4) == 2);
  CHECK(ilog2(5) == 2);
  CHECK(ilog2(6) == 2);
  CHECK(ilog2(7) == 2);
  CHECK(ilog2(8) == 3);
  CHECK(ilog2(9) == 3);
  CHECK(ilog2((1u << 31) - 1) == 30);
  CHECK(ilog2((1u << 31) + 0) == 31);
  CHECK(ilog2((1u << 31) + 1) == 31);

  CHECK(ilog2(std::numeric_limits<int8_t>::max()) == 6);
  CHECK(ilog2(std::numeric_limits<uint8_t>::max()) == 7);
  CHECK(ilog2(std::numeric_limits<int32_t>::max()) == 30);
  CHECK(ilog2(std::numeric_limits<uint32_t>::max()) == 31);
  CHECK(ilog2(std::numeric_limits<int64_t>::max()) == 62);
  CHECK(ilog2(std::numeric_limits<uint64_t>::max()) == 63);
}
