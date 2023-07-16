#include <armkn/util/alias/heapq.hpp>
#include <catch2/catch_test_macros.hpp>

template <class T>
int pop(T& q) {
  int x = q.top();
  q.pop();
  return x;
}

TEST_CASE("MinHeap", "[util][util/heapq]") {
  MinHeap<int> q;
  for (auto i : {3, 1, 4, 1, 5}) q.push(i);

  REQUIRE(pop(q) == 1);
  REQUIRE(pop(q) == 1);
  REQUIRE(pop(q) == 3);
  REQUIRE(pop(q) == 4);
  REQUIRE(pop(q) == 5);
}

TEST_CASE("MaxHeap", "[util][util/heapq]") {
  MaxHeap<int> q;
  for (auto i : {3, 1, 4, 1, 5}) q.push(i);

  REQUIRE(pop(q) == 5);
  REQUIRE(pop(q) == 4);
  REQUIRE(pop(q) == 3);
  REQUIRE(pop(q) == 1);
  REQUIRE(pop(q) == 1);
}
