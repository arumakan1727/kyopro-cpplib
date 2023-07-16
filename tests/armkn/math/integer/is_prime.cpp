#include <armkn/math/integer/is_prime.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("is_prime", "[math][math/integer]") {
  SECTION("prime numbers") {
    CHECK(is_prime(2));
    CHECK(is_prime(3));
    CHECK(is_prime(5));
    CHECK(is_prime(7));
    CHECK(is_prime(11));
    CHECK(is_prime(13));
    CHECK(is_prime(998244353));

    // 57 is abusolutely prime number,
    // but it's very very strong and dangerous,
    // so we need to weaken it by subtracting 10 .
    CHECK(is_prime(57 - 10));
  }

  SECTION("non prime numbers") {
    CHECK(is_prime(0) == false);
    CHECK(is_prime(1) == false);
    CHECK(is_prime(4) == false);
    CHECK(is_prime(9) == false);
    CHECK(is_prime(100'000'000'001) == false);
  }
}
