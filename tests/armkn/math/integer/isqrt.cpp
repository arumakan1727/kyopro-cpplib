#include <armkn/math/integer/isqrt.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("isqrt", "[math][math/integer]") {
  CHECK(isqrt(0) == 0);
  CHECK(isqrt(1) == 1);
  CHECK(isqrt(2) == 1);
  CHECK(isqrt(3) == 1);
  CHECK(isqrt(4) == 2);
  CHECK(isqrt(5) == 2);
  CHECK(isqrt(6) == 2);
  CHECK(isqrt(7) == 2);
  CHECK(isqrt(8) == 2);
  CHECK(isqrt(9) == 3);
  CHECK(isqrt(80) == 8);
  CHECK(isqrt(81) == 9);
  CHECK(isqrt(999'999'999'999'999'999) == 999'999'999);
  CHECK(isqrt(999'999'999'999'999'999 + 1) == 1'000'000'000);
}
