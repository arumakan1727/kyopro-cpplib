#include <armkn/set/closed_range_set.hpp>
#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <type_traits>
#include <vector>

TEST_CASE("ClosedRangeSet") {
  using std::vector;
  auto s = ClosedRangeSet<i32>();
  REQUIRE(s.size() == 0);
  REQUIRE(s.empty());
  REQUIRE(s.begin() == s.end());
  REQUIRE(std::is_same_v<decltype(s)::iterator, decltype(s.begin())>);
  REQUIRE(std::is_same_v<decltype(s)::value_type, CRange<i32>>);

  SECTION("single big range") {
    constexpr i32 MIN = -2'000'000'000;
    constexpr i32 MAX = 2'000'000'000;
    CHECK(s.insert(MIN, MAX) == 4'000'000'001uL);
    CHECK(s.size() == 1);
    CHECK(std::equal(s.begin(), s.end(), vector{CRange(MIN, MAX)}.begin()));

    CHECK(s.contains(MIN));
    CHECK(s.contains(0));
    CHECK(s.contains(MAX));
    CHECK_FALSE(s.contains(MIN - 1));
    CHECK_FALSE(s.contains(MAX + 1));

    CHECK(s.covers(MIN, MAX));
    CHECK(s.covers(MIN, MIN));
    CHECK(s.covers(MAX, MAX));
    CHECK(s.covers(0, 0));
    CHECK(s.covers(-3, 7));
    CHECK(s.covers(CRange(-3, 7)));
    CHECK_FALSE(s.covers(MIN - 1, MAX));
    CHECK_FALSE(s.covers(MIN, MAX + 1));
    CHECK_FALSE(s.covers(CRange(MIN - 1, MAX)));
    CHECK_FALSE(s.covers(CRange(MIN, MAX + 1)));
    CHECK_FALSE(s.covers(MAX + 1, MAX + 1));
    CHECK_FALSE(s.covers(MIN - 1, MIN - 1));

    CHECK(s.intersects(MIN, MAX));
    CHECK(s.intersects(MIN, MIN));
    CHECK(s.intersects(MAX, MAX));
    CHECK(s.intersects(0, 0));
    CHECK(s.intersects(-3, 7));
    CHECK(s.intersects(MIN - 1, MAX));
    CHECK(s.intersects(MIN, MAX + 1));
    CHECK(s.intersects(CRange(MIN - 1, MAX)));
    CHECK(s.intersects(CRange(MIN, MAX + 1)));
    CHECK_FALSE(s.intersects(MAX + 1, MAX + 1));
    CHECK_FALSE(s.intersects(MIN - 1, MIN - 1));
    CHECK_FALSE(s.intersects(CRange(MAX + 1, MAX + 1)));
    CHECK_FALSE(s.intersects(CRange(MIN - 1, MIN - 1)));

    CHECK(s.mex(-1) == MAX + 1);
    CHECK(s.mex(0) == MAX + 1);
    CHECK(s.mex(MAX) == MAX + 1);
    CHECK(s.mex(MAX + 1) == MAX + 1);
    CHECK(s.mex(MAX + 2) == MAX + 2);
    CHECK(s.mex(MIN) == MAX + 1);
    CHECK(s.mex(MIN - 1) == MIN - 1);

    CHECK(s.insert(MIN, MAX) == 0);
    CHECK(s.insert(CRange(MIN, MAX)) == 0);
    CHECK(s.size() == 1);
    CHECK(s.contains(MIN));
    CHECK(s.contains(0));
    CHECK(s.contains(MAX));
    CHECK(s.covers(MIN, MAX));
    CHECK_FALSE(s.contains(MIN - 1));
    CHECK_FALSE(s.contains(MAX + 1));

    constexpr i32 L = -3, R = 1;
    CHECK(s.erase(L, R) == 5);
    CHECK(s.size() == 2);
    CHECK(std::equal(s.begin(), s.end(), vector{CRange(MIN, L - 1), CRange(R + 1, MAX)}.begin()));
    CHECK(s.contains(MIN));
    CHECK(s.contains(MAX));
    CHECK(s.contains(L - 1));
    CHECK(s.contains(R + 1));
    CHECK_FALSE(s.contains(L));
    CHECK_FALSE(s.contains(-2));
    CHECK_FALSE(s.contains(-1));
    CHECK_FALSE(s.contains(0));
    CHECK_FALSE(s.contains(R));
    CHECK_FALSE(s.contains(MIN - 1));
    CHECK_FALSE(s.contains(MAX + 1));
    CHECK(s.covers(MIN, L - 1));
    CHECK(s.covers(R + 1, MAX));
    CHECK_FALSE(s.covers(MIN, L));
    CHECK_FALSE(s.covers(R, MAX));
    CHECK_FALSE(s.covers(L, R));
    CHECK_FALSE(s.covers(MIN, MAX));

    CHECK(s.mex(L - 2) == L);
    CHECK(s.mex(L - 1) == L);
    CHECK(s.mex(L + 0) == L);
    CHECK(s.mex(L + 1) == L + 1);
    CHECK(s.mex(L + 2) == L + 2);
    CHECK(s.mex(L + 3) == L + 3);
    CHECK(L + 4 == R);
    CHECK(s.mex(R) == R);
    CHECK(s.mex(R + 1) == MAX + 1);
    CHECK(s.mex(MAX) == MAX + 1);
    CHECK(s.mex(MAX + 1) == MAX + 1);
    CHECK(s.mex(MAX + 2) == MAX + 2);
    CHECK(s.mex(MIN) == L);
    CHECK(s.mex(MIN - 1) == MIN - 1);
  }

  SECTION("5 isolated ranges") {
    const CRange<int> a(-100, -90), b(-4, 0), c(5, 5), d(10, 20), e(22, 23);
    CHECK(a.size() == 11);
    CHECK(b.size() == 5);
    CHECK(c.size() == 1);
    CHECK(d.size() == 11);
    CHECK(e.size() == 2);
    CHECK(s.insert(a) == a.size());
    CHECK(s.insert(e) == e.size());
    CHECK(s.insert(d) == d.size());
    CHECK(s.insert(c) == c.size());
    CHECK(s.insert(b) == b.size());
    CHECK(s.size() == 5);
    CHECK(std::equal(s.begin(), s.end(), vector{a, b, c, d, e}.begin()));

    for (const auto& z : {a, b, c, d, e}) {
      CHECK(s.contains(z.min));
      CHECK(s.contains(z.max));
      CHECK_FALSE(s.contains(z.min - 1));
      CHECK_FALSE(s.contains(z.max + 1));

      CHECK(s.covers(z));
      CHECK(s.covers(z.min, z.min));
      CHECK(s.covers(z.max, z.max));
      if (z.size() > 1) {
        CHECK(s.covers(z.min + 1, z.max));
        CHECK(s.covers(z.min, z.max - 1));
        if (z.size() > 2) CHECK(s.covers(z.min + 1, z.max - 1));
        CHECK_FALSE(s.covers(z.min - 1, z.max + 1));
        CHECK_FALSE(s.covers(z.min, z.max + 1));
        CHECK_FALSE(s.covers(z.min - 1, z.max));
      }

      CHECK(s.intersects(z));
      CHECK(s.intersects(z.min, z.min));
      CHECK(s.intersects(z.max, z.max));
      if (z.size() > 1) {
        CHECK(s.intersects(z.min - 1, z.max));
        CHECK(s.intersects(z.min + 1, z.max));
        CHECK(s.intersects(z.min, z.max - 1));
        CHECK(s.intersects(z.min, z.max + 1));
      }
      CHECK(s.intersects(z.min - 1, z.max + 1));
    }
  }

  SECTION("insert() check1: 2つの区間の端点が隣り合っている場合はマージされて1つの区間になる") {
    CRange<int> a(0, 5), b(3, 7), c(-5, -5), d(-6, -6), e(-4, -4), f(-3, -1);
    using vec = std::vector<CRange<int>>;
    CHECK(s.insert(a) == 6);
    CHECK(std::equal(s.begin(), s.end(), vec{a}.begin()));
    CHECK(s.insert(b) == 2);
    CHECK(std::equal(s.begin(), s.end(), vec{{a.min, b.max}}.begin()));
    CHECK(s.insert(c) == 1);
    CHECK(std::equal(s.begin(), s.end(), vec{c, {a.min, b.max}}.begin()));
    CHECK(s.insert(d) == 1);
    CHECK(std::equal(s.begin(), s.end(), vec{{d.min, c.max}, {a.min, b.max}}.begin()));
    CHECK(s.insert(e) == 1);
    CHECK(std::equal(s.begin(), s.end(), vec{{d.min, e.max}, {a.min, b.max}}.begin()));
    CHECK(s.insert(f) == 3);
    CHECK(std::equal(s.begin(), s.end(), vec{{d.min, b.max}}.begin()));
  }

  SECTION("insert() check2: 重なっている区間はマージされる") {
    CRange<int> a(30, 40), b(25, 35), c(20, 40), d(27, 57), e(20, 63);
    CRange<int> f(20, 20), g(63, 63), h(20, 63), i(10, 99);
    using vec = std::vector<CRange<int>>;

    CHECK(s.insert(30, 40) == 11);
    CHECK(std::equal(s.begin(), s.end(), vec{{30, 40}}.begin()));
    CHECK(s.insert(29, 35) == 1);
    CHECK(std::equal(s.begin(), s.end(), vec{{29, 40}}.begin()));
    CHECK(s.insert(20, 40) == 9);
    CHECK(std::equal(s.begin(), s.end(), vec{{20, 40}}.begin()));
    CHECK(s.insert(27, 57) == 17);
    CHECK(std::equal(s.begin(), s.end(), vec{{20, 57}}.begin()));
    CHECK(s.insert(20, 65) == 8);
    CHECK(std::equal(s.begin(), s.end(), vec{{20, 65}}.begin()));
    CHECK(s.insert(20, 20) == 0);
    CHECK(std::equal(s.begin(), s.end(), vec{{20, 65}}.begin()));
    CHECK(s.insert(65, 65) == 0);
    CHECK(std::equal(s.begin(), s.end(), vec{{20, 65}}.begin()));
    CHECK(s.insert(20, 65) == 0);
    CHECK(std::equal(s.begin(), s.end(), vec{{20, 65}}.begin()));
    CHECK(s.insert(10, 80) == 25);
    CHECK(std::equal(s.begin(), s.end(), vec{{10, 80}}.begin()));
  }
}
