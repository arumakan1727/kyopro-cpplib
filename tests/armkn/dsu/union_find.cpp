#include <armkn/dsu/union_find.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

TEST_CASE("UnionFind", "[dsu][dsu/UnionFind]") {
  auto uf = UnionFind(7);

  REQUIRE(uf.size() == 7);

  SECTION("initial state") {
    auto i = GENERATE(0, 1, 2, 3, 4, 5, 6);
    REQUIRE(uf.size(i) == 1);

    CHECK(uf.unite(0, 0) == false);
    CHECK(uf.unite(1, 1) == false);
    CHECK(uf.unite(2, 2) == false);
    CHECK(uf.unite(6, 6) == false);

    CHECK(uf.is_same(0, 0) == true);
    CHECK(uf.is_same(1, 1) == true);
    CHECK(uf.is_same(2, 2) == true);
    CHECK(uf.is_same(6, 6) == true);

    CHECK(uf.is_same(0, 1) == false);
    CHECK(uf.is_same(1, 2) == false);
    CHECK(uf.is_same(0, 6) == false);
  }

  SECTION("basic senario") {
    // {0, 1, 2, 4}, {3, 6}
    REQUIRE(uf.unite(0, 1) == true);
    REQUIRE(uf.unite(1, 2) == true);
    REQUIRE(uf.unite(0, 4) == true);
    REQUIRE(uf.unite(3, 6) == true);

    SECTION("unite() of already same node returns false") {
      CHECK(uf.unite(4, 1) == false);
      CHECK(uf.unite(0, 1) == false);
      CHECK(uf.unite(1, 2) == false);
      CHECK(uf.unite(2, 0) == false);
      CHECK(uf.unite(3, 6) == false);
      CHECK(uf.unite(6, 3) == false);
    }
    SECTION("is_same() of same node returns true") {
      CHECK(uf.is_same(0, 1));
      CHECK(uf.is_same(1, 2));
      CHECK(uf.is_same(2, 4));
      CHECK(uf.is_same(1, 4));
      CHECK(uf.is_same(4, 0));

      CHECK(uf.is_same(3, 6));
      CHECK(uf.is_same(6, 3));

      CHECK(uf.is_same(5, 5));
    }
    SECTION("is_same() of unsame node returns false") {
      CHECK(uf.is_same(0, 3) == false);
      CHECK(uf.is_same(3, 2) == false);
      CHECK(uf.is_same(6, 0) == false);
      CHECK(uf.is_same(5, 6) == false);
    }
    SECTION("size(node)") {
      CHECK(uf.size(0) == 4);
      CHECK(uf.size(1) == 4);
      CHECK(uf.size(2) == 4);
      CHECK(uf.size(3) == 2);
      CHECK(uf.size(4) == 4);
      CHECK(uf.size(5) == 1);
      CHECK(uf.size(6) == 2);
    }
    SECTION("groups()") {
      auto got = uf.groups();
      std::vector<std::vector<uint32_t>> want = {{0, 1, 2, 4}, {3, 6}, {5}};
      CHECK(got == want);
    }
  }
  SECTION("unite() with hook function") {
    uint32_t parent, child;
    auto hook = [&](uint32_t p, uint32_t c) {
      parent = p;
      child = c;
    };

    uf.unite(0, 1, hook);
    REQUIRE(parent == 0);
    REQUIRE(child == 1);

    uf.unite(0, 2, hook);
    REQUIRE(parent == 0);
    REQUIRE(child == 2);

    uf.unite(6, 3, hook);
    REQUIRE(parent == 6);
    REQUIRE(child == 3);

    uf.unite(3, 2, hook);
    REQUIRE(parent == 0);
    REQUIRE(child == 6);

    // If nodes are already united, hook function must NOT be called.
    parent = child = 777;
    CHECK(uf.unite(0, 1) == false);
    REQUIRE(parent == 777);
    REQUIRE(child == 777);
  }

  REQUIRE(uf.size() == 7);
}
