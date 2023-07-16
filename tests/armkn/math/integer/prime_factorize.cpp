#include <armkn/math/integer/prime_factorize.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>

TEST_CASE("prime_factorize", "[math][math/integer]") {
  using map = std::map<int, int>;
  CHECK(prime_factorize(1) == map{});
  CHECK(prime_factorize(2) == map{{2, 1}});
  CHECK(prime_factorize(3) == map{{3, 1}});
  CHECK(prime_factorize(4) == map{{2, 2}});
  CHECK(prime_factorize(5) == map{{5, 1}});
  CHECK(prime_factorize(6) == map{{2, 1}, {3, 1}});
  CHECK(prime_factorize(7) == map{{7, 1}});
  CHECK(prime_factorize(8) == map{{2, 3}});
  CHECK(prime_factorize(9) == map{{3, 2}});
  CHECK(prime_factorize(10) == map{{2, 1}, {5, 1}});
  CHECK(prime_factorize(11) == map{{11, 1}});
  CHECK(prime_factorize(12) == map{{2, 2}, {3, 1}});
  CHECK(prime_factorize(13) == map{{13, 1}});
  CHECK(prime_factorize(14) == map{{2, 1}, {7, 1}});
  CHECK(prime_factorize(15) == map{{3, 1}, {5, 1}});
  CHECK(prime_factorize(16) == map{{2, 4}});
}
