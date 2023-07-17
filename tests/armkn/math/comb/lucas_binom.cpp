#include <armkn/math/comb/lucas_binom.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("LucasBinomial", "[math][math/comb]") {
  SECTION("MOD=127") {
    constexpr uint32_t MOD = 127;
    const auto f = LucasBinomial(MOD);
    CHECK(f.MOD == 127);

    CHECK(f.C(3, -1) == 0);
    CHECK(f.C(3, 0) == 1);
    CHECK(f.C(3, 1) == 3);
    CHECK(f.C(3, 2) == 3);
    CHECK(f.C(3, 3) == 1);
    CHECK(f.C(3, 4) == 0);

    CHECK(f.C(4, -1) == 0);
    CHECK(f.C(4, 0) == 1);
    CHECK(f.C(4, 1) == 4);
    CHECK(f.C(4, 2) == 6);
    CHECK(f.C(4, 3) == 4);
    CHECK(f.C(4, 4) == 1);
    CHECK(f.C(4, 5) == 0);

    const uint64_t n = 100000;
    CHECK(f.C(n, 0) == 1);
    CHECK(f.C(n, 1) == n % MOD);
    CHECK(f.C(n, 2) == n * (n - 1) / 2 % MOD);
    CHECK(f.C(n, 3) == n * (n - 1) * (n - 2) / (3 * 2) % MOD);
    CHECK(f.C(n, n - 1) == n % MOD);
    CHECK(f.C(n, n) == 1);
  }
  SECTION("MOD=5") {
    constexpr uint32_t MOD = 5;
    const auto f = LucasBinomial(MOD);
    CHECK(f.MOD == 5);

    CHECK(f.C(0, -1) == 0);
    CHECK(f.C(0, 0) == 1);
    CHECK(f.C(0, 1) == 0);

    CHECK(f.C(1, -1) == 0);
    CHECK(f.C(1, 0) == 1);
    CHECK(f.C(1, 1) == 1);
    CHECK(f.C(1, 2) == 0);

    CHECK(f.C(2, 0) == 1);
    CHECK(f.C(2, 1) == 2);
    CHECK(f.C(2, 2) == 1);

    CHECK(f.C(3, 0) == 1);
    CHECK(f.C(3, 1) == 3);
    CHECK(f.C(3, 2) == 3);
    CHECK(f.C(3, 3) == 1);

    CHECK(f.C(4, 0) == 1);
    CHECK(f.C(4, 1) == 4);
    CHECK(f.C(4, 2) == 6 % MOD);
    CHECK(f.C(4, 3) == 4);
    CHECK(f.C(4, 4) == 1);

    CHECK(f.C(5, 0) == 1);
    CHECK(f.C(5, 1) == 0);
    CHECK(f.C(5, 2) == 0);
    CHECK(f.C(5, 3) == 0);
    CHECK(f.C(5, 4) == 0);
    CHECK(f.C(5, 5) == 1);

    CHECK(f.C(26, 0) == 1);
    CHECK(f.C(26, 1) == 26 % MOD);
    CHECK(f.C(26, 2) == 0);  // 26 * 25 / 2 % MOD
    CHECK(f.C(26, 3) == 0);
    CHECK(f.C(26, 4) == 0);

    CHECK(f.C(27, 0) == 1);
    CHECK(f.C(27, 1) == 27 % MOD);
    CHECK(f.C(27, 2) == 27 * 26 / 2 % MOD);
    CHECK(f.C(27, 3) == 0);
    CHECK(f.C(27, 4) == 0);
  }
}
