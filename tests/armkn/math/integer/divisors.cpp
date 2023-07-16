#include <armkn/math/integer/divisors.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("divisors", "[math][math/integer]") {
  using vec = std::vector<int>;
  CHECK(divisors(0) == vec{});
  CHECK(divisors(1) == vec{1});
  CHECK(divisors(2) == vec{1, 2});
  CHECK(divisors(6) == vec{1, 2, 3, 6});
  CHECK(divisors(9) == vec{1, 3, 9});
  CHECK(divisors(10) == vec{1, 2, 5, 10});
  CHECK(divisors(16) == vec{1, 2, 4, 8, 16});
  CHECK(divisors(10'000'000'019) == std::vector{1, 10'000'000'019});
}
