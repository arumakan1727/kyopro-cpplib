#include <armkn/util/type_traits/is_random_accessible.hpp>
#include <catch2/catch_test_macros.hpp>

#include <array>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <valarray>
#include <vector>

TEST_CASE("is_random_accessible", "[type_traits]") {
  using armkn::is_random_accessible_v;

  CHECK(is_random_accessible_v<std::string>);
  CHECK(is_random_accessible_v<std::wstring>);
  CHECK(is_random_accessible_v<std::string_view>);
  CHECK(is_random_accessible_v<std::wstring_view>);
  CHECK(is_random_accessible_v<std::vector<int>>);
  CHECK(is_random_accessible_v<std::vector<std::vector<float>>>);
  CHECK(is_random_accessible_v<std::vector<bool>>);
  CHECK(is_random_accessible_v<std::deque<int>>);
  CHECK(is_random_accessible_v<std::array<int, 1>>);

  CHECK(is_random_accessible_v<char> == false);
  CHECK(is_random_accessible_v<int> == false);
  CHECK(is_random_accessible_v<uint8_t> == false);
  CHECK(is_random_accessible_v<int64_t> == false);
  CHECK(is_random_accessible_v<std::list<int>> == false);
  CHECK(is_random_accessible_v<std::map<int, int>> == false);
  CHECK(is_random_accessible_v<std::pair<int, int>> == false);
  CHECK(is_random_accessible_v<std::set<int>> == false);
  CHECK(is_random_accessible_v<std::stack<int>> == false);
  CHECK(is_random_accessible_v<std::tuple<int>> == false);
  CHECK(is_random_accessible_v<std::unordered_multimap<int, int>> == false);
  CHECK(is_random_accessible_v<std::valarray<int>> == false);
  CHECK(is_random_accessible_v<int[1]> == false);
  CHECK(is_random_accessible_v<int*> == false);
  CHECK(is_random_accessible_v<char*> == false);
  CHECK(is_random_accessible_v<std::vector<int>::iterator> == false);
}
