#include <armkn/util/alias/stdint.hpp>
#include <armkn/util/fn/shakutori.hpp>
#include <catch2/catch_test_macros.hpp>

#include <tuple>
#include <vector>

TEST_CASE("shakutori") {
  //          index:  0  1  2  3  4    5   6  7  8  9
  const std::vector a{9, 1, 4, 1, 5, 999, 11, 6, 5, 3};

  // 連続部分列の総和が X 以下となる最長の区間をしゃくとり法で探す
  constexpr int X = 11;
  int sum = 0;

  const auto can_push_right = [&](u32 r) { return sum + a[r] <= X; };

  const auto push_right = [&](u32 r) { sum += a[r]; };

  const auto pop_left = [&](u32 l) { sum -= a[l]; };

  std::vector<std::tuple<u32, u32, int>> log;  // (l, r, sum)
  const auto action = [&](u32 l, u32 r) { log.emplace_back(l, r, sum); };

  shakutori(0u, (u32)a.size(), can_push_right, push_right, pop_left, action);

  const decltype(log) want{
      {0, 2, 9 + 1},
      {1, 5, 1 + 4 + 1 + 5},
      {2, 5, 4 + 1 + 5},
      {3, 5, 1 + 5},
      {4, 5, 5},
      {5, 5, 0},
      {6, 7, 11},
      {7, 9, 6 + 5},
      {8, 10, 5 + 3},
      {9, 10, 3},
  };

  CHECK(log == want);
}
