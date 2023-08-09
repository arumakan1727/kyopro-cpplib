#include <armkn/util/macro/fn.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("FN1") {
  const auto f = FN1(_ * 100);
  CHECK(f(0) == 0);
  CHECK(f(5) == 500);
  CHECK(f(-1) == -100);
  CHECK(FN1(_ + _ * 100)(7) == 707);
}

TEST_CASE("FN2") {
  const auto f = FN2(_1 * 100 + _2);
  CHECK(f(3, 4) == 304);
  CHECK(f(-1, 4) == -96);
  CHECK(f(0, 0) == 0);
  CHECK(FN2((_1 + _2) * (_1 - _2))(3, 7) == -40);
}
