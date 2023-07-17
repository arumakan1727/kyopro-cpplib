#include <armkn/util/fn/floor_pow2.hpp>
#include <catch2/catch_test_macros.hpp>
#include <limits>

TEST_CASE("floor_pow2", "[util]") {
  CHECK(floor_pow2(0) == 0);
  CHECK(floor_pow2(1) == 1);
  CHECK(floor_pow2(2) == 2);
  CHECK(floor_pow2(3) == 2);
  CHECK(floor_pow2(4) == 4);
  CHECK(floor_pow2(5) == 4);
  CHECK(floor_pow2(6) == 4);
  CHECK(floor_pow2(7) == 4);
  CHECK(floor_pow2(8) == 8);
  CHECK(floor_pow2(9) == 8);
  CHECK(floor_pow2(15) == 8);
  CHECK(floor_pow2(16) == 16);
  CHECK(floor_pow2(17) == 16);
  CHECK(floor_pow2(32767) == 16384);
  CHECK(floor_pow2(32768) == 32768);
  CHECK(floor_pow2(32769) == 32768);

  CHECK(floor_pow2(std::numeric_limits<int8_t>::max()) == 1 << 6);
  CHECK(floor_pow2(std::numeric_limits<uint8_t>::max()) == 1 << 7);
  CHECK(floor_pow2(std::numeric_limits<int32_t>::max()) == 1 << 30);
  CHECK(floor_pow2(std::numeric_limits<uint32_t>::max()) == 1u << 31);
  CHECK(floor_pow2(std::numeric_limits<int64_t>::max()) == 1ll << 62);
  CHECK(floor_pow2(std::numeric_limits<uint64_t>::max()) == 1ull << 63);
}
