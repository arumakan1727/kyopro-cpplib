#include <armkn/math/integer/prime_numbers.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("prime_numbers", "[math][math/integer]") {
  using vec = std::vector<int>;
  CHECK(prime_numbers(0) == vec{});
  CHECK(prime_numbers(1) == vec{});
  CHECK(prime_numbers(2) == vec{2});
  CHECK(prime_numbers(3) == vec{2, 3});
  CHECK(prime_numbers(4) == vec{2, 3});
  CHECK(prime_numbers(5) == vec{2, 3, 5});
  CHECK(prime_numbers(6) == vec{2, 3, 5});
  CHECK(prime_numbers(7) == vec{2, 3, 5, 7});
  CHECK(prime_numbers(8) == vec{2, 3, 5, 7});
  CHECK(prime_numbers(9) == vec{2, 3, 5, 7});
  CHECK(prime_numbers(10) == vec{2, 3, 5, 7});
  CHECK(prime_numbers(11) == vec{2, 3, 5, 7, 11});
  CHECK(prime_numbers(12) == vec{2, 3, 5, 7, 11});
  CHECK(prime_numbers(13) == vec{2, 3, 5, 7, 11, 13});
  CHECK(prime_numbers(14) == vec{2, 3, 5, 7, 11, 13});
  CHECK(prime_numbers(15) == vec{2, 3, 5, 7, 11, 13});
  CHECK(prime_numbers(16) == vec{2, 3, 5, 7, 11, 13});
  CHECK(prime_numbers(17) == vec{2, 3, 5, 7, 11, 13, 17});
}
