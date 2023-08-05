#include <armkn/util/fn/hamming_distance.hpp>
#include <catch2/catch_test_macros.hpp>

#include <string_view>

TEST_CASE("hamming_distance") {
  using namespace std::string_view_literals;

  CHECK(hamming_distance(""sv, ""sv) == 0);
  CHECK(hamming_distance("abc"sv, "abc"sv) == 0);
  CHECK(hamming_distance("abc"sv, "Xbc"sv) == 1);
  CHECK(hamming_distance("abc"sv, "aYc"sv) == 1);
  CHECK(hamming_distance("abc"sv, "abZ"sv) == 1);
  CHECK(hamming_distance("abcd"sv, "aXca"sv) == 2);
  CHECK(hamming_distance("abcd"sv, "xyzw"sv) == 4);
}
