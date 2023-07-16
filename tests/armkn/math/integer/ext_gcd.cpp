#include <armkn/math/integer/ext_gcd.hpp>
#include <catch2/catch_test_macros.hpp>
#include <numeric>

TEST_CASE("ext_gcd", "[math][math/integer]") {
  const auto check = [](int64_t a, int64_t b) {
    const auto g = std::gcd(a, b);
    auto [x, y] = ext_gcd(a, b);
    INFO("(a,b,gcd)=(" << a << ',' << b << ',' << g << "), (x,y)=(" << x << ',' << y << ')');
    CHECK(a * x + b * y == g);
  };

  check(2, 3);
  check(5, 2);
  check(8, 12);
  check(19, 57);
  check(13, 31);
  check(0, 998244353);
  check(123456, 998244353);
  check(998244352, 998244353);
}
