#include <armkn/util/fn/rotate_matrix.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("rotate_matrix", "[util]") {
  using svec = std::vector<std::string>;

  const svec m{
      "###",
      "#..",
      "###",
      "#..",
      "#..",
  };
  const svec rot90{
      "#####",
      "..#.#",
      "..#.#",
  };
  const svec rot180{
      "..#",
      "..#",
      "###",
      "..#",
      "###",
  };
  const svec rot270{
      "#.#..",
      "#.#..",
      "#####",
  };
  CHECK(rotate_matrix(m, 0) == m);
  CHECK(rotate_matrix(m, 4) == m);
  CHECK(rotate_matrix(m, 8) == m);
  CHECK(rotate_matrix(m, -16) == m);

  CHECK(rotate_matrix(m, 1) == rot90);
  CHECK(rotate_matrix(m, 9) == rot90);
  CHECK(rotate_matrix(m, -3) == rot90);
  CHECK(rotate_matrix(m, -7) == rot90);

  CHECK(rotate_matrix(m, 2) == rot180);
  CHECK(rotate_matrix(m, 10) == rot180);
  CHECK(rotate_matrix(m, -2) == rot180);
  CHECK(rotate_matrix(m, -6) == rot180);

  CHECK(rotate_matrix(m, 3) == rot270);
  CHECK(rotate_matrix(m, 11) == rot270);
  CHECK(rotate_matrix(m, -1) == rot270);
  CHECK(rotate_matrix(m, -5) == rot270);
}
