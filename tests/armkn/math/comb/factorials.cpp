#include <armkn/math/comb/factorials.hpp>
#include <armkn/math/modular/static_modint.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Factorials", "[math][math/comb]") {
  using Mint = ModInt998244353;

  auto f = Factorials<Mint>(5);
  REQUIRE(f.size() == 6);
  REQUIRE(f.capacity() > 2'000'000);

  // -------------- fac(n) ---------------
  CHECK(f.fac(0) == 1);
  CHECK(f.fac(1) == 1);
  CHECK(f.fac(2) == 2);
  CHECK(f.fac(3) == 6);
  CHECK(f.fac(4) == 24);
  CHECK(f.size() == 6);

  // ここで 7 > 5 となり precalc(7) が実行されるはず
  CHECK(f.fac(7) == 5040);
  CHECK(f.size() == 8);
  CHECK(f.fac(6) == 720);
  CHECK(f.fac(5) == 120);

  // ここで 8 > 7 となり precalc(8) が実行されるはず
  /* CHECK(f.fac(8) == 40320); */
  /* CHECK(f.size() == 9); */

  // -------------- finv(n) ---------------
  CHECK(f.finv(0) == 1);
  CHECK(f.finv(1) == 1);
  CHECK(f.finv(2) == 499122177);
  CHECK(f.finv(3) == 166374059);
  CHECK(f.finv(4) == 291154603);

  CHECK(f.finv(7) == 376916469);
  CHECK(f.finv(6) == 641926577);
  CHECK(f.finv(5) == 856826403);

  /* CHECK(f.finv(8) == 421456191); */

  // -------------- C(n, k) ---------------
  CHECK(f.C(3, -1) == 0);
  CHECK(f.C(3, 0) == 1);
  CHECK(f.C(3, 1) == 3);
  CHECK(f.C(3, 2) == 3);
  CHECK(f.C(3, 3) == 1);
  CHECK(f.C(3, 4) == 0);

  CHECK(f.C(6, -1) == 0);
  CHECK(f.C(6, 0) == 1);
  CHECK(f.C(6, 1) == 6);
  CHECK(f.C(6, 2) == 15);
  CHECK(f.C(6, 3) == 20);
  CHECK(f.C(6, 4) == 15);
  CHECK(f.C(6, 5) == 6);
  CHECK(f.C(6, 6) == 1);
  CHECK(f.C(6, 7) == 0);

  // -------------- P(n, k) ---------------
  CHECK(f.P(3, -1) == 0);
  CHECK(f.P(3, 0) == 1);
  CHECK(f.P(3, 1) == 3);
  CHECK(f.P(3, 2) == 6);
  CHECK(f.P(3, 3) == 6);
  CHECK(f.P(3, 4) == 0);

  CHECK(f.P(6, -1) == 0);
  CHECK(f.P(6, 0) == 1);
  CHECK(f.P(6, 1) == 6);    // 6
  CHECK(f.P(6, 2) == 30);   // 6*5
  CHECK(f.P(6, 3) == 120);  // 6*5*4
  CHECK(f.P(6, 4) == 360);  // 6*5*4*3
  CHECK(f.P(6, 5) == 720);  // 6*5*4*3*2
  CHECK(f.P(6, 6) == 720);
  CHECK(f.P(6, 7) == 0);

  // -------------- H(n, k) ---------------
  CHECK(f.H(3, -1) == 0);
  CHECK(f.H(3, 0) == 1);   // C(2, 0)
  CHECK(f.H(3, 1) == 3);   // C(3, 1)
  CHECK(f.H(3, 2) == 6);   // C(4, 2)
  CHECK(f.H(3, 3) == 10);  // C(5, 3)
  CHECK(f.H(3, 4) == 15);  // C(6, 4)

  CHECK(f.H(4, -1) == 0);
  CHECK(f.H(4, 0) == 1);   // C(3, 0)
  CHECK(f.H(4, 1) == 4);   // C(4, 1)
  CHECK(f.H(4, 2) == 10);  // C(5, 2)
  CHECK(f.H(4, 3) == 20);  // C(6, 3) 6 5 4 / 3 2 1
  CHECK(f.H(4, 4) == 35);  // C(7, 4) 7 6 5 / 3 2 1
  CHECK(f.H(4, 5) == 56);  // C(8, 5) 8 7 6 / 3 2 1
}
