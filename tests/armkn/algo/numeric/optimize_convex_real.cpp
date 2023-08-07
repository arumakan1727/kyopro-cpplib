#include <armkn/algo/numeric/optimize_convex_real.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("optimize_convex_real") {
  constexpr double ERR = 1e-6;
  using P = std::pair<double, double>;

  SECTION("f(x) = x^2") {
    const auto f = [](double x) { return x * x; };
    P got;

    got = optimize_convex_real<double>(-1e-3, 1e3, ERR, f);
    CHECK_THAT(got.first, Catch::Matchers::WithinAbs(0.0, ERR));
    CHECK_THAT(got.second, Catch::Matchers::WithinAbs(0.0, ERR));

    got = optimize_convex_real<double>(-1000, 1000, ERR, f);
    CHECK_THAT(got.first, Catch::Matchers::WithinAbs(0.0, ERR));
    CHECK_THAT(got.second, Catch::Matchers::WithinAbs(0.0, ERR));

    got = optimize_convex_real<double>(0, 3, ERR, f);
    CHECK_THAT(got.first, Catch::Matchers::WithinAbs(0.0, ERR));
    CHECK_THAT(got.second, Catch::Matchers::WithinAbs(0.0, ERR));

    got = optimize_convex_real<double>(-3, 0, ERR, f);
    CHECK_THAT(got.first, Catch::Matchers::WithinAbs(0.0, ERR));
    CHECK_THAT(got.second, Catch::Matchers::WithinAbs(0.0, ERR));

    got = optimize_convex_real<double>(3, 7, ERR, f);
    CHECK_THAT(got.first, Catch::Matchers::WithinAbs(3, ERR));
    CHECK_THAT(got.second, Catch::Matchers::WithinAbs(9, ERR));

    got = optimize_convex_real<double>(-9, -4, ERR, f);
    CHECK_THAT(got.first, Catch::Matchers::WithinAbs(-4, ERR));
    CHECK_THAT(got.second, Catch::Matchers::WithinAbs(16, ERR));
  }

  SECTION("f(x) = -(x+7)^2 + 11") {
    constexpr double A = -7;
    constexpr double B = 11;
    const auto f = [](double x) { return -(x - A) * (x - A) + B; };
    P got;

    got = optimize_convex_real<double>(-8, -6, ERR, f, std::greater<>{});
    CHECK_THAT(got.first, Catch::Matchers::WithinAbs(A, ERR));
    CHECK_THAT(got.second, Catch::Matchers::WithinAbs(B, ERR));

    got = optimize_convex_real<double>(-100, 100, ERR, f, std::greater<>{});
    CHECK_THAT(got.first, Catch::Matchers::WithinAbs(A, ERR));
    CHECK_THAT(got.second, Catch::Matchers::WithinAbs(B, ERR));
  }
}
