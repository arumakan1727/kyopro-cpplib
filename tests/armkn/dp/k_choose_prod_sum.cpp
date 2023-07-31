#include <armkn/dp/k_choose_prod_sum.hpp>
#include <catch2/catch_test_macros.hpp>

#include <vector>

TEST_CASE("k_choose_prod_sum", "dp") {
  using std::vector;

  const vector<int> a{2, 3, 5, 7, 11};

  const vector<vector<int64_t>> got = k_choose_prod_sum<int64_t>(a, 3);

  const vector<vector<int64_t>> want = {
      {0, 0, 0, 0, 0, 0},
      {0, 2, 5, 10, 17, 28},
      {0, 0, 6, 31, 101, 288},
      {0, 0, 0, 30, 247, 1358},
  };

  CHECK(got == want);
}
