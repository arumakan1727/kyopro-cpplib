#include <armkn/algo/numeric/bin_search_int.hpp>
#include <armkn/util/alias/stdint.hpp>
#include <catch2/catch_test_macros.hpp>

#include <utility>
#include <vector>

#define fn(expr) ([&](u32 i) { return (expr); })

TEST_CASE("bin_search_int") {
  std::vector<int> a{1, 3, 3, 3, 3, 6};

  CHECK(bin_search_int(5u, 0u, fn(a[i] >= 1)) == 0);
  CHECK(bin_search_int(5u, 0u, fn(a[i] >= 2)) == 1);
  CHECK(bin_search_int(5u, 0u, fn(a[i] >= 3)) == 1);
  CHECK(bin_search_int(5u, 0u, fn(a[i] >= 4)) == 5);
  CHECK(bin_search_int(5u, 0u, fn(a[i] >= 5)) == 5);
  CHECK(bin_search_int(5u, 0u, fn(a[i] >= 6)) == 5);
  CHECK(bin_search_int(5u, 0u, fn(a[i] >= 7)) == 6);

  CHECK(bin_search_int(0u, 5u, fn(a[i] < 1)) == -1);
  CHECK(bin_search_int(0u, 5u, fn(a[i] < 2)) == 0);
  CHECK(bin_search_int(0u, 5u, fn(a[i] < 3)) == 0);
  CHECK(bin_search_int(0u, 5u, fn(a[i] < 4)) == 4);
  CHECK(bin_search_int(0u, 5u, fn(a[i] < 5)) == 4);
  CHECK(bin_search_int(0u, 5u, fn(a[i] < 6)) == 4);
  CHECK(bin_search_int(0u, 5u, fn(a[i] < 7)) == 5);
}
