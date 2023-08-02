#include <armkn/algo/mapping/doubling.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Doubling") {
  std::vector<int> mapping(5);
  /*-------------------------------------
    0->4->3->2->1
       ^        v
       +<-------+
  -------------------------------------*/
  mapping[0] = 4;
  mapping[1] = 4;
  mapping[2] = 1;
  mapping[3] = 2;
  mapping[4] = 3;

  const auto f = Doubling(mapping);
  CHECK(f.apply_repeat(0, 0) == 0);
  CHECK(f.apply_repeat(0, 1) == 4);
  CHECK(f.apply_repeat(0, 2) == 3);
  CHECK(f.apply_repeat(0, 3) == 2);
  CHECK(f.apply_repeat(0, 4) == 1);
  CHECK(f.apply_repeat(0, 5) == 4);
  CHECK(f.apply_repeat(0, 6) == 3);
  CHECK(f.apply_repeat(0, 7) == 2);
  CHECK(f.apply_repeat(0, 8) == 1);
  CHECK(f.apply_repeat(0, 9) == 4);
  CHECK(f.apply_repeat(0, 10) == 3);
  CHECK(f.apply_repeat(0, 11) == 2);
  CHECK(f.apply_repeat(0, 12) == 1);
  CHECK(f.apply_repeat(0, 13) == 4);
  CHECK(f.apply_repeat(0, 14) == 3);
  CHECK(f.apply_repeat(0, 15) == 2);
  CHECK(f.apply_repeat(0, 16) == 1);
  CHECK(f.apply_repeat(0, 17) == 4);

  CHECK(f.apply_repeat(4, 0) == 4);
  CHECK(f.apply_repeat(4, 1) == 3);
  CHECK(f.apply_repeat(4, 2) == 2);
  CHECK(f.apply_repeat(4, 3) == 1);
  CHECK(f.apply_repeat(4, 4) == 4);
  CHECK(f.apply_repeat(4, 5) == 3);
  CHECK(f.apply_repeat(4, 6) == 2);
  CHECK(f.apply_repeat(4, 7) == 1);
  CHECK(f.apply_repeat(4, 8) == 4);
  CHECK(f.apply_repeat(4, 9) == 3);
  CHECK(f.apply_repeat(4, 10) == 2);
  CHECK(f.apply_repeat(4, 11) == 1);
  CHECK(f.apply_repeat(4, 12) == 4);
  CHECK(f.apply_repeat(4, 13) == 3);
  CHECK(f.apply_repeat(4, 14) == 2);
  CHECK(f.apply_repeat(4, 15) == 1);
  CHECK(f.apply_repeat(4, 16) == 4);
  CHECK(f.apply_repeat(4, 17) == 3);
}
