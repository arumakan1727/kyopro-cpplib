#include <armkn/util/fn/runlength.hpp>
#include <armkn/util/macro/iter_all.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("runlength", "[util]") {
  using vec = std::vector<int>;
  using Chunks = std::vector<std::pair<int, int>>;

  auto empty_vec = vec{};
  CHECK(runlength(ALL(empty_vec)) == Chunks{});

  auto a = vec{5};
  CHECK(runlength(ALL(a)) == Chunks{{5, 1}});

  auto b = vec{-3, -3, -3};
  CHECK(runlength(ALL(b)) == Chunks{{-3, 3}});

  auto c = vec{2, 7, 7, 7, -1, -1};
  CHECK(runlength(ALL(c)) == Chunks{{2, 1}, {7, 3}, {-1, 2}});
}
