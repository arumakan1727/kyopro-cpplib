#include <armkn/math/comb/binom_fn.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("binom", "[math][math/comb]") {
  CHECK(binom(3, -1) == 0);
  CHECK(binom(3, 0) == 1);
  CHECK(binom(3, 1) == 3);
  CHECK(binom(3, 2) == 3);
  CHECK(binom(3, 3) == 1);
  CHECK(binom(3, 4) == 0);

  CHECK(binom(4, -1) == 0);
  CHECK(binom(4, 0) == 1);
  CHECK(binom(4, 1) == 4);
  CHECK(binom(4, 2) == 6);
  CHECK(binom(4, 3) == 4);
  CHECK(binom(4, 4) == 1);
  CHECK(binom(4, 5) == 0);

  const int64_t n = 1'000'000'000;
  const int64_t want = n * (n - 1) / 2;
  CHECK(binom(n, 2) == want);
  CHECK(binom(n, n - 2) == want);
}
