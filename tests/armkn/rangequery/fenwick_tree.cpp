#include <armkn/rangequery/fenwick_tree.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("FenwickTree", "[rangequery]") {
  SECTION("size=4 & contains negative value") {
    auto ft = FenwickTree<int>(4);
    REQUIRE(ft.size() == 4);

    // [3, -8, 0, 4]
    ft.add(0, 3);
    ft.add(1, -8);
    ft.add(3, 4);
    CHECK(ft.sum(0) == 0);
    CHECK(ft.sum(1) == 3);
    CHECK(ft.sum(2) == -5);
    CHECK(ft.sum(3) == -5);
    CHECK(ft.sum(4) == -1);

    CHECK(ft.sum(0, 0) == 0);
    CHECK(ft.sum(1, 1) == 0);
    CHECK(ft.sum(4, 4) == 0);

    CHECK(ft.sum(1, 2) == -8);  // [-8]
    CHECK(ft.sum(1, 3) == -8);  // [-8, 0]
    CHECK(ft.sum(1, 4) == -4);  // [-8, 0, 4]
    CHECK(ft.sum(2, 3) == 0);   // [0]
    CHECK(ft.sum(2, 4) == 4);   // [0, 4]
    CHECK(ft.sum(3, 4) == 4);   // [4]

    CHECK(ft[0] == 3);
    CHECK(ft[1] == -8);
    CHECK(ft[2] == 0);
    CHECK(ft[3] == 4);

    // [-2, -8, 0, 4]
    ft.set(0, -2);
    CHECK(ft[0] == -2);
    CHECK(ft.sum(1) == -2);
    CHECK(ft.sum(2) == -10);
    CHECK(ft.sum(3) == -10);
    CHECK(ft.sum(4) == -6);

    // [-2, -8, 0, 15]
    ft.set(3, 15);
    CHECK(ft[3] == 15);
    CHECK(ft.sum(1) == -2);
    CHECK(ft.sum(2) == -10);
    CHECK(ft.sum(3) == -10);
    CHECK(ft.sum(4) == 5);

    // [-2, 0, 1, 15]
    ft.add(1, 8);
    ft.add(2, 1);
    CHECK(ft[1] == 0);
    CHECK(ft[2] == 1);
    CHECK(ft.sum(1) == -2);
    CHECK(ft.sum(2) == -2);
    CHECK(ft.sum(3) == -1);
    CHECK(ft.sum(4) == 14);

    CHECK(ft.lower_bound(-3) == 1);
    CHECK(ft.lower_bound(-2) == 1);
    CHECK(ft.lower_bound(-1) == 3);
    CHECK(ft.lower_bound(0) == 4);
    CHECK(ft.lower_bound(14) == 4);
    CHECK(ft.lower_bound(15) == 5);
  }

  SECTION("size=7 & use constructor FenwickTree(const std::vector<T>&)") {
    std::vector<int> a{3, 1, 4, 1, 0, 0, 5};
    REQUIRE(a.size() == 7);

    auto ft = FenwickTree<int64_t>(a);
    REQUIRE(ft.size() == a.size());

    for (unsigned i = 0; i < a.size(); ++i) {
      CHECK(ft[i] == a[i]);
    }
    CHECK(ft.sum(0, 0) == 0);
    CHECK(ft.sum(7, 7) == 0);
    CHECK(ft.sum(0, 1) == 3);
    CHECK(ft.sum(0, 7) == 14);

    CHECK(ft.sum(2, 3) == 4);
    CHECK(ft.sum(2, 4) == 5);
    CHECK(ft.sum(2, 5) == 5);
    CHECK(ft.sum(2, 6) == 5);
    CHECK(ft.sum(2, 7) == 10);

    //  index:  0  1  2  3  4  5  6   7
    // cumsum: [0, 3, 4, 8, 9, 9, 9, 14]
    CHECK(ft.lower_bound(0) == 0);
    CHECK(ft.lower_bound(1) == 1);
    CHECK(ft.lower_bound(2) == 1);
    CHECK(ft.lower_bound(3) == 1);
    CHECK(ft.lower_bound(4) == 2);
    CHECK(ft.lower_bound(5) == 3);
    CHECK(ft.lower_bound(6) == 3);
    CHECK(ft.lower_bound(7) == 3);
    CHECK(ft.lower_bound(8) == 3);
    CHECK(ft.lower_bound(9) == 4);
    CHECK(ft.lower_bound(10) == 7);
    CHECK(ft.lower_bound(11) == 7);
    CHECK(ft.lower_bound(12) == 7);
    CHECK(ft.lower_bound(13) == 7);
    CHECK(ft.lower_bound(14) == 7);
    CHECK(ft.lower_bound(15) == 8);
    CHECK(ft.lower_bound(16) == 8);
  }
}
