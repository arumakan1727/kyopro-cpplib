#include <armkn/math/modular/static_modint.hpp>
#include <armkn/util/alias/i128.hpp>
#include <armkn/util/fn/sigma.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>

TEST_CASE("sigma", "[util/fn]") {
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

  constexpr auto n = 1000000000000000000;

  using Mint = ModInt998244353;
  CHECK(sigma(Mint(5), Mint(7)) == Mint(18));
  CHECK(sigma(Mint(1), Mint(n)) == Mint(75433847));

  i128 want = i128(n) * i128(n + 1) >> 1;
  CHECK(sigma(i128(1), i128(n)) == want);
  CHECK(std::is_integral_v<i128>);
}
