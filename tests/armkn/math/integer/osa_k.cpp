#include <armkn/math/integer/osa_k.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>

TEST_CASE("OsaK", "[math][math/integer]") {
  SECTION("OsaK(1)") {
    auto t = OsaK(1);
    CHECK(t.is_prime(0) == false);
    CHECK(t.is_prime(1) == false);
    CHECK(t.min_factor(1) == 1);
  }

  SECTION("OsaK(7)") {
    auto t = OsaK(7);
    CHECK(t.is_prime(2));
    CHECK(t.is_prime(3));
    CHECK(t.is_prime(5));
    CHECK(t.is_prime(7));
    CHECK(t.is_prime(0) == false);
    CHECK(t.is_prime(1) == false);
    CHECK(t.is_prime(4) == false);
    CHECK(t.is_prime(6) == false);

    CHECK(t.min_factor(1) == 1);
    CHECK(t.min_factor(2) == 2);
    CHECK(t.min_factor(3) == 3);
    CHECK(t.min_factor(4) == 2);
    CHECK(t.min_factor(5) == 5);
    CHECK(t.min_factor(6) == 2);
    CHECK(t.min_factor(7) == 7);
  }

  SECTION("OsaK(16)") {
    using map = std::map<int, int>;
    auto t = OsaK(16);
    CHECK(t.min_factor(10) == 2);
    CHECK(t.min_factor(11) == 11);
    CHECK(t.min_factor(12) == 2);
    CHECK(t.min_factor(13) == 13);
    CHECK(t.min_factor(14) == 2);
    CHECK(t.min_factor(15) == 3);
    CHECK(t.min_factor(16) == 2);

    CHECK(t.prime_factorize(2) == map{{2, 1}});
    CHECK(t.prime_factorize(3) == map{{3, 1}});
    CHECK(t.prime_factorize(4) == map{{2, 2}});
    CHECK(t.prime_factorize(5) == map{{5, 1}});
    CHECK(t.prime_factorize(6) == map{{2, 1}, {3, 1}});
    CHECK(t.prime_factorize(7) == map{{7, 1}});
    CHECK(t.prime_factorize(8) == map{{2, 3}});
    CHECK(t.prime_factorize(9) == map{{3, 2}});
    CHECK(t.prime_factorize(10) == map{{2, 1}, {5, 1}});
    CHECK(t.prime_factorize(11) == map{{11, 1}});
    CHECK(t.prime_factorize(12) == map{{2, 2}, {3, 1}});
    CHECK(t.prime_factorize(13) == map{{13, 1}});
    CHECK(t.prime_factorize(14) == map{{2, 1}, {7, 1}});
    CHECK(t.prime_factorize(15) == map{{3, 1}, {5, 1}});
    CHECK(t.prime_factorize(16) == map{{2, 4}});
  }
}
