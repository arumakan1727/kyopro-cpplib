#include <armkn/util/type_traits/is_string_like.hpp>
#include <array>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <string_view>

TEST_CASE("is_string_like", "[type_traits]") {
  using armkn::is_string_like_v;

  CHECK(is_string_like_v<std::string>);
  CHECK(is_string_like_v<std::wstring>);
  CHECK(is_string_like_v<std::string_view>);
  CHECK(is_string_like_v<std::wstring_view>);

  CHECK(is_string_like_v<char> == false);
  CHECK(is_string_like_v<int> == false);
  CHECK(is_string_like_v<uint8_t> == false);
  CHECK(is_string_like_v<int64_t> == false);
  CHECK(is_string_like_v<std::vector<char>> == false);
  CHECK(is_string_like_v<std::vector<int8_t>> == false);
  CHECK(is_string_like_v<std::vector<uint8_t>> == false);
  CHECK(is_string_like_v<std::string::iterator> == false);
  CHECK(is_string_like_v<std::array<char, 1>> == false);
  CHECK(is_string_like_v<char[1]> == false);
  CHECK(is_string_like_v<char*> == false);
}
