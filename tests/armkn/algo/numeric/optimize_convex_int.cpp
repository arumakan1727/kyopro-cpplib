#include <armkn/algo/numeric/optimize_convex_int.hpp>
#include <armkn/fmt/ostream_op_pair.hpp>
#include <catch2/catch_test_macros.hpp>

#include <utility>
#include <vector>

TEST_CASE("optimize_convex_int") {
  using vec = std::vector<int>;
  using P = std::pair<size_t, vec::value_type>;

  const auto make_func = [](vec const& a) {
    return [&](auto i) {
      assert(0 <= i && i < a.size());
      return a[i];
    };
  };

  SECTION("len(range) = 1") {
    const auto a = vec{5};
    const auto f = make_func(a);
    CHECK(optimize_convex_int<size_t>(0, a.size(), f) == P{0, a[0]});
    CHECK(optimize_convex_int<size_t>(0, a.size(), f, std::less<>()) == P{0, a[0]});
    CHECK(optimize_convex_int<size_t>(0, a.size(), f, std::greater<>()) == P{0, a[0]});
  }

  SECTION("len(range) = 2") {
    const auto a = vec{3, 4};  // asc
    const auto b = vec{9, 1};  // desc
    const auto f_a = make_func(a);
    const auto f_b = make_func(b);
    CHECK(optimize_convex_int<size_t>(0, a.size(), f_a) == P{0, a[0]});
    CHECK(optimize_convex_int<size_t>(0, b.size(), f_b) == P{1, b[1]});
    CHECK(optimize_convex_int<size_t>(0, a.size(), f_a, std::greater<>{}) == P{1, a[1]});
    CHECK(optimize_convex_int<size_t>(0, b.size(), f_b, std::greater<>{}) == P{0, b[0]});
  }

  SECTION("len(range) = 3") {
    const auto a = vec{6, 4, 8};  // 下に凸
    const auto b = vec{7, 9, 5};  // 上に凸
    const auto f_a = make_func(a);
    const auto f_b = make_func(b);
    CHECK(optimize_convex_int<size_t>(0, a.size(), f_a) == P{1, a[1]});
    CHECK(optimize_convex_int<size_t>(0, b.size(), f_b, std::greater<>{}) == P{1, b[1]});
  }

  // 凸関数ではないのでテストする必要はないかも
  SECTION("constant func") {
    const auto f = [](int) { return 100; };
    CHECK(optimize_convex_int(0, 1, f) == std::pair{0, 100});
    CHECK(optimize_convex_int(0, 2, f) == std::pair{1, 100});
    CHECK(optimize_convex_int(0, 3, f) == std::pair{2, 100});
    CHECK(optimize_convex_int(0, 4, f) == std::pair{3, 100});
    CHECK(optimize_convex_int(0, 5, f) == std::pair{4, 100});
    CHECK(optimize_convex_int(1, 5, f) == std::pair{4, 100});
    CHECK(optimize_convex_int(2, 5, f) == std::pair{4, 100});

    CHECK(optimize_convex_int(0, 1, f, std::greater<>{}) == std::pair{0, 100});
    CHECK(optimize_convex_int(0, 2, f, std::greater<>{}) == std::pair{1, 100});
    CHECK(optimize_convex_int(0, 3, f, std::greater<>{}) == std::pair{2, 100});
    CHECK(optimize_convex_int(0, 4, f, std::greater<>{}) == std::pair{3, 100});
    CHECK(optimize_convex_int(0, 5, f, std::greater<>{}) == std::pair{4, 100});
    CHECK(optimize_convex_int(1, 5, f, std::greater<>{}) == std::pair{4, 100});
    CHECK(optimize_convex_int(2, 5, f, std::greater<>{}) == std::pair{4, 100});
  }

  SECTION("len(range) = 7") {
    const auto a = vec{9, 6, 5, 2, 4, 7, 8};  // 下に凸
    const auto b = vec{0, 6, 8, 9, 8, 6, 5};  // 上に凸
    const auto c = vec{0, 1, 2, 3, 4, 5, 6};  // 単調増加
    const auto d = vec{9, 8, 7, 6, 5, 4, 3};  // 単調減少
    const auto f_a = make_func(a);
    const auto f_b = make_func(b);
    const auto f_c = make_func(c);
    const auto f_d = make_func(d);
    CHECK(optimize_convex_int<size_t>(0, a.size(), f_a) == P{3, a[3]});
    CHECK(optimize_convex_int<size_t>(0, b.size(), f_b, std::greater<>{}) == P{3, b[3]});

    CHECK(optimize_convex_int<size_t>(0, c.size(), f_c) == P{0, c.front()});
    CHECK(optimize_convex_int<size_t>(0, d.size(), f_d) == P{6, d.back()});
    CHECK(optimize_convex_int<size_t>(0, c.size(), f_c, std::greater<>{}) == P{6, c.back()});
    CHECK(optimize_convex_int<size_t>(0, d.size(), f_d, std::greater<>{}) == P{0, d.front()});
  }

  SECTION("len(range) = 8") {
    const auto a = vec{0, -100, 1, 2, 3, 4, 5, 6};  // 下に凸
    const auto b = vec{1, 2, 3, 4, 5, 6, 100, 0};   // 上に凸
    const auto f_a = make_func(a);
    const auto f_b = make_func(b);
    CHECK(optimize_convex_int<size_t>(0, a.size(), f_a) == P{1, a[1]});
    CHECK(optimize_convex_int<size_t>(0, b.size(), f_b, std::greater<>{}) == P{6, b[6]});
  }
}
