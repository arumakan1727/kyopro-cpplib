#include <armkn/util/type_traits/is_iterable.hpp>
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
#include <vector>

TEST_CASE("is_iterable", "[type_traits]") {
  using armkn::is_iterable_v;

  CHECK(is_iterable_v<std::string>);
  CHECK(is_iterable_v<std::wstring>);
  CHECK(is_iterable_v<std::string_view>);
  CHECK(is_iterable_v<std::wstring_view>);

  CHECK(is_iterable_v<std::array<int, 1>>);
  CHECK(is_iterable_v<std::deque<int>>);
  CHECK(is_iterable_v<std::list<int>>);
  CHECK(is_iterable_v<std::map<int, int>>);
  CHECK(is_iterable_v<std::set<int>>);
  CHECK(is_iterable_v<std::unordered_multimap<int, int>>);
  CHECK(is_iterable_v<std::vector<bool>>);
  CHECK(is_iterable_v<std::vector<int>>);
  CHECK(is_iterable_v<std::vector<std::vector<float>>>);

  CHECK(is_iterable_v<char> == false);
  CHECK(is_iterable_v<int> == false);
  CHECK(is_iterable_v<uint8_t> == false);
  CHECK(is_iterable_v<int64_t> == false);
  CHECK(is_iterable_v<int[1]> == false);
  CHECK(is_iterable_v<int*> == false);
  CHECK(is_iterable_v<char*> == false);
  CHECK(is_iterable_v<std::vector<int>::iterator> == false);
  CHECK(is_iterable_v<std::pair<int, int>> == false);
  CHECK(is_iterable_v<std::tuple<int>> == false);
  CHECK(is_iterable_v<std::stack<int>> == false);
}
