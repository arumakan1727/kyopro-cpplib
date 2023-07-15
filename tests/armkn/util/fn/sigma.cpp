#include <armkn/util/fn/sigma.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("sigma(a, b)", "[util][util/sigma]") {
  CHECK(sigma(0, 0) == 0);
  CHECK(sigma(0, 1) == 0 + 1);
  CHECK(sigma(0, 2) == 0 + 1 + 2);
  CHECK(sigma(0, 3) == 0 + 1 + 2 + 3);

  CHECK(sigma(5, 5) == 5);
  CHECK(sigma(5, 6) == 5 + 6);
  CHECK(sigma(5, 7) == 5 + 6 + 7);
  CHECK(sigma(5, 8) == 5 + 6 + 7 + 8);

  CHECK(sigma(1, 1234567890) == 762078938126809995);
  CHECK(sigma(123'456'789'012'340, 123'456'789'012'345) == 740740734074055);
}
