#include <armkn/util/type_traits/is_key_value_map.hpp>
#include <catch2/catch_test_macros.hpp>

#include <array>
#include <list>
#include <map>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

TEST_CASE("is_key_value_map", "[type_traits]") {
  using armkn::is_key_value_map_v;

  CHECK(is_key_value_map_v<std::map<int, int>>);
  CHECK(is_key_value_map_v<std::map<std::string, bool>>);
  CHECK(is_key_value_map_v<std::map<std::string, bool>>);
  CHECK(is_key_value_map_v<std::multimap<uint64_t, std::vector<int>>>);
  CHECK(is_key_value_map_v<std::unordered_map<int, int>>);
  CHECK(is_key_value_map_v<std::unordered_multimap<int, int>>);

  CHECK_FALSE(is_key_value_map_v<int>);
  CHECK_FALSE(is_key_value_map_v<uint8_t>);
  CHECK_FALSE(is_key_value_map_v<std::pair<int, int>>);
  CHECK_FALSE(is_key_value_map_v<std::tuple<int, int>>);
  CHECK_FALSE(is_key_value_map_v<std::array<std::pair<int, int>, 3>>);
  CHECK_FALSE(is_key_value_map_v<std::list<int>>);
  CHECK_FALSE(is_key_value_map_v<std::list<std::pair<int, int>>>);
  CHECK_FALSE(is_key_value_map_v<std::multiset<std::pair<int, int>>>);
  CHECK_FALSE(is_key_value_map_v<std::set<int>>);
  CHECK_FALSE(is_key_value_map_v<std::set<std::pair<int, int>>>);
  CHECK_FALSE(is_key_value_map_v<std::string>);
  CHECK_FALSE(is_key_value_map_v<std::string_view>);
  CHECK_FALSE(is_key_value_map_v<std::unordered_set<std::tuple<int, int>>>);
}
