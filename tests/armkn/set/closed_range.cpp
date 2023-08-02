#include <armkn/set/closed_range.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("CRange") {
  const CRange<int> r33(3, 3);
  const CRange<int> r24(2, 4);
  const CRange<int> r03(0, 3);
  const CRange<int> r37(3, 7);

  CHECK(r33.size() == 1);
  CHECK(r24.size() == 3);
  CHECK(r03.size() == 4);
  CHECK(r37.size() == 5);
  CHECK(CRange(-4, -3).size() == 2);
  CHECK(CRange<int32_t>(-2'000'000'000, 2'000'000'000).size() == 4'000'000'001uL);

  CHECK(r33.contains(3));
  CHECK(r24.contains(2));
  CHECK(r24.contains(3));
  CHECK(r24.contains(4));
  CHECK_FALSE(r33.contains(2));
  CHECK_FALSE(r33.contains(4));
  CHECK_FALSE(r24.contains(1));
  CHECK_FALSE(r24.contains(5));
  CHECK_FALSE(r24.contains(-1000));
  CHECK_FALSE(r24.contains(99999));

  CHECK(r33.covers(r33));
  CHECK(r24.covers(r24));
  CHECK(r24.covers(r33));
  CHECK(r03.covers(r33));
  CHECK(r37.covers(r33));
  CHECK_FALSE(r33.covers(r24));
  CHECK_FALSE(r33.covers(r03));
  CHECK_FALSE(r33.covers(r37));
  CHECK_FALSE(r03.covers(r37));
  CHECK_FALSE(r24.covers(r03));
  CHECK_FALSE(r24.covers(r37));
  CHECK_FALSE(r37.covers(r24));
  CHECK_FALSE(r37.covers(r03));

  CHECK(r33.touches(r33));
  CHECK(r33.touches(r24));
  CHECK(r33.touches(r03));
  CHECK(r33.touches(r37));
  CHECK(r24.touches(r03));
  CHECK(r24.touches(r37));
  CHECK(r03.touches(r37));
  CHECK(r37.touches(r03));
  CHECK_FALSE(r24.touches(CRange(1, 1)));
  CHECK_FALSE(r24.touches(CRange(-100, 1)));
  CHECK_FALSE(r24.touches(CRange(5, 5)));
  CHECK_FALSE(r24.touches(CRange(5, 999999)));

  CHECK(r33.overlaps(r24));
  CHECK(r24.overlaps(r33));
  CHECK(r24.overlaps(r03));
  CHECK(r24.overlaps(r37));
  CHECK_FALSE(r33.overlaps(r33));
  CHECK_FALSE(r33.overlaps(r03));
  CHECK_FALSE(r33.overlaps(r37));
  CHECK_FALSE(r03.overlaps(r37));
  CHECK_FALSE(r37.overlaps(r03));
}
