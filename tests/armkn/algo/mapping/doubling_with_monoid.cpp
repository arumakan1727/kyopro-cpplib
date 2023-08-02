#include <armkn/algo/mapping/doubling_with_monoid.hpp>
#include <catch2/catch_test_macros.hpp>

#include <string>
#include <vector>

TEST_CASE("DoublingWithMonoid") {
  using std::string;
  std::vector<int> dest(5);
  std::vector<string> weight(5);
  /*---------------------------
    0->4->3->2->1
       ^        v
       +<---<---+
  ---------------------------*/
  dest[0] = 4;
  dest[1] = 4;
  dest[2] = 1;
  dest[3] = 2;
  dest[4] = 3;
  weight[0] = "0";
  weight[1] = "1";
  weight[2] = "2";
  weight[3] = "3";
  weight[4] = "4";

  const auto f = DoublingWithMonoid(
      dest,
      weight,
      [](string const& a, string const& b) { return a + b; },
      4
  );

  using P = std::pair<u32, std::string>;

  CHECK(f.apply_repeat(0, "", 0) == P{0, ""});
  CHECK(f.apply_repeat(0, "hoge", 0) == P{0, "hoge"});

  CHECK(f.apply_repeat(0, "/", 1) == P{4, "/0"});
  CHECK(f.apply_repeat(0, "/", 2) == P{3, "/04"});
  CHECK(f.apply_repeat(0, "/", 3) == P{2, "/043"});
  CHECK(f.apply_repeat(0, "/", 4) == P{1, "/0432"});
  CHECK(f.apply_repeat(0, "/", 5) == P{4, "/04321"});
  CHECK(f.apply_repeat(0, "/", 6) == P{3, "/043214"});
  CHECK(f.apply_repeat(0, "/", 7) == P{2, "/0432143"});
  CHECK(f.apply_repeat(0, "/", 8) == P{1, "/04321432"});
  CHECK(f.apply_repeat(0, "/", 9) == P{4, "/043214321"});
  CHECK(f.apply_repeat(0, "/", 10) == P{3, "/0432143214"});
  CHECK(f.apply_repeat(0, "/", 11) == P{2, "/04321432143"});
  CHECK(f.apply_repeat(0, "/", 12) == P{1, "/043214321432"});
  CHECK(f.apply_repeat(0, "/", 13) == P{4, "/0432143214321"});
  CHECK(f.apply_repeat(0, "/", 14) == P{3, "/04321432143214"});
  CHECK(f.apply_repeat(0, "/", 15) == P{2, "/043214321432143"});

  CHECK(f.apply_repeat(4, "", 0) == P{4, ""});
  CHECK(f.apply_repeat(4, "", 1) == P{3, "4"});
  CHECK(f.apply_repeat(4, "", 2) == P{2, "43"});
  CHECK(f.apply_repeat(4, "", 3) == P{1, "432"});
  CHECK(f.apply_repeat(4, "", 4) == P{4, "4321"});
  CHECK(f.apply_repeat(4, "", 5) == P{3, "43214"});
  CHECK(f.apply_repeat(4, "", 6) == P{2, "432143"});
  CHECK(f.apply_repeat(4, "", 7) == P{1, "4321432"});
  CHECK(f.apply_repeat(4, "", 8) == P{4, "43214321"});
  CHECK(f.apply_repeat(4, "", 9) == P{3, "432143214"});
  CHECK(f.apply_repeat(4, "", 10) == P{2, "4321432143"});
  CHECK(f.apply_repeat(4, "", 11) == P{1, "43214321432"});
  CHECK(f.apply_repeat(4, "", 12) == P{4, "432143214321"});
  CHECK(f.apply_repeat(4, "", 13) == P{3, "4321432143214"});
  CHECK(f.apply_repeat(4, "", 14) == P{2, "43214321432143"});
  CHECK(f.apply_repeat(4, "", 15) == P{1, "432143214321432"});
}
