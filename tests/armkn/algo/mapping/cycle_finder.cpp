#include <armkn/algo/mapping/cycle_finder.hpp>
#include <catch2/catch_test_macros.hpp>

#include <vector>

TEST_CASE("CycleFinder") {
  std::vector<int> f(7);
  f[0] = 1;
  f[1] = 2;
  f[2] = 3;
  f[3] = 4;
  f[4] = 5;
  f[5] = 3;
  f[6] = 6;

  SECTION("start=1") {
    auto cf = CycleFinder(1, f);
    CHECK(cf.until_cycle_start() == 2);
    CHECK(cf.cycle_len() == 3);
    CHECK(cf.apply_repeat(0) == 1);
    CHECK(cf.apply_repeat(1) == 2);
    CHECK(cf.apply_repeat(2) == 3);
    CHECK(cf.apply_repeat(3) == 4);
    CHECK(cf.apply_repeat(4) == 5);
    CHECK(cf.apply_repeat(5) == 3);
    CHECK(cf.apply_repeat(6) == 4);
    CHECK(cf.apply_repeat(7) == 5);
    CHECK(cf.apply_repeat(8) == 3);
    CHECK(cf.apply_repeat(9) == 4);
    CHECK(cf.apply_repeat(10) == 5);
    CHECK(cf.apply_repeat(11) == 3);
  }
  SECTION("start=3") {
    auto cf = CycleFinder(3, f);
    CHECK(cf.until_cycle_start() == 0);
    CHECK(cf.cycle_len() == 3);
    CHECK(cf.apply_repeat(0) == 3);
    CHECK(cf.apply_repeat(1) == 4);
    CHECK(cf.apply_repeat(2) == 5);
    CHECK(cf.apply_repeat(3) == 3);
    CHECK(cf.apply_repeat(4) == 4);
    CHECK(cf.apply_repeat(5) == 5);
    CHECK(cf.apply_repeat(6) == 3);
    CHECK(cf.apply_repeat(7) == 4);
    CHECK(cf.apply_repeat(8) == 5);
    CHECK(cf.apply_repeat(9) == 3);
    CHECK(cf.apply_repeat(10) == 4);
    CHECK(cf.apply_repeat(11) == 5);
  }
  SECTION("start=4") {
    auto cf = CycleFinder(4, f);
    CHECK(cf.until_cycle_start() == 0);
    CHECK(cf.cycle_len() == 3);
    CHECK(cf.apply_repeat(0) == 4);
    CHECK(cf.apply_repeat(1) == 5);
    CHECK(cf.apply_repeat(2) == 3);
    CHECK(cf.apply_repeat(3) == 4);
    CHECK(cf.apply_repeat(4) == 5);
    CHECK(cf.apply_repeat(5) == 3);
    CHECK(cf.apply_repeat(6) == 4);
    CHECK(cf.apply_repeat(7) == 5);
    CHECK(cf.apply_repeat(8) == 3);
    CHECK(cf.apply_repeat(9) == 4);
    CHECK(cf.apply_repeat(10) == 5);
    CHECK(cf.apply_repeat(11) == 3);
  }
  SECTION("start=6") {
    auto cf = CycleFinder(6, f);
    CHECK(cf.until_cycle_start() == 0);
    CHECK(cf.cycle_len() == 1);
    CHECK(cf.apply_repeat(0) == 6);
    CHECK(cf.apply_repeat(1) == 6);
    CHECK(cf.apply_repeat(2) == 6);
    CHECK(cf.apply_repeat(3) == 6);
  }
}
