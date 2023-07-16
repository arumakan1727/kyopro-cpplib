#include <armkn/math/comb/binom_table_const_n.hpp>
#include <armkn/math/modular/static_modint.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("binom_table_const_n", "[math][math/comb]") {
  CHECK(binom_table_const_n<int>(6, 6) == std::vector{1, 6, 15, 20, 15, 6, 1});

  using Mint = ModInt998244353;
  const auto n = 1'000'000'000'000ull;
  const auto m = Mint(n);
  CHECK(
      binom_table_const_n<Mint>(n, 4) ==
      std::vector{
          Mint(1),
          m,
          m * (m - 1) / 2,
          m * (m - 1) * (m - 2) / (3 * 2),
          m * (m - 1) * (m - 2) * (m - 3) / (4 * 3 * 2)}
  );
}
