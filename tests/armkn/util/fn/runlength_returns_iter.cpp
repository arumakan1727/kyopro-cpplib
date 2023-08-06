#include <armkn/util/fn/runlength_returns_iter.hpp>
#include <armkn/util/macro/iter_all.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("runlength_returns_iter", "[util]") {
  using vec = std::vector<int>;
  using Chunks = std::vector<std::pair<vec::iterator, int>>;

  auto empty_vec = vec{};
  CHECK(runlength_returns_iter(ALL(empty_vec)) == Chunks{});

  auto a = vec{5};
  CHECK(runlength_returns_iter(ALL(a)) == Chunks{{a.begin(), 1}});

  auto b = vec{-3, -3, -3};
  CHECK(runlength_returns_iter(ALL(b)) == Chunks{{b.begin(), 3}});

  auto c = vec{2, 7, 7, 7, -1, -1};
  CHECK(
      runlength_returns_iter(ALL(c)) ==
      Chunks{{c.begin(), 1}, {c.begin() + 1, 3}, {c.begin() + 4, 2}}
  );
}
