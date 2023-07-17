#include <armkn/str/rolling_hash.hpp>
#include <armkn/util/macro/iter_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string_view>

TEST_CASE("RollingHash", "[str]") {
  const std::string_view a_str = "mississippi";
  const std::string_view b_str = "ississi";
  const std::string_view c_str = "ippippi";

  using RHash = RollingHash<1333>;
  const auto a = RHash(ALL(a_str));
  const auto b = RHash(ALL(b_str));
  const auto c = RHash(ALL(c_str));

  REQUIRE(a.hash() == a.hash());
  REQUIRE(b.hash() == b.hash());
  REQUIRE(c.hash() == c.hash());

  REQUIRE(a.hash() != b.hash());
  REQUIRE(a.hash() != c.hash());
  REQUIRE(b.hash() != c.hash());

  REQUIRE(a.size() == a_str.size());
  REQUIRE(b.size() == b_str.size());
  REQUIRE(c.size() == c_str.size());

  CHECK(a.slice(0, 0) == RHash::Hash{0, 0});
  CHECK(a.slice(11, 11) == RHash::Hash{0, 0});

  CHECK(a.substr(0, a.size()) == a.hash());
  CHECK(a.slice(0, a.size()) == a.hash());

  // "m[ississi]ppi" vs "ississi"
  CHECK(a.substr(1, b.size()) == b.hash());
  CHECK(a.slice(1, 1 + b.size()) == b.hash());

  // "mi[ssi]ssippi" vs "missi[ssi]ppi"
  CHECK(a.substr(2, 3) == a.substr(5, 3));
  CHECK(a.slice(2, 5) == a.slice(5, 8));

  // "mi[ssi]ssippi" vs "mi[ssis]sippi"
  CHECK(a.substr(2, 3) != a.substr(2, 4));

  // "mi[ssi]ssippi" vs "mississi[ppi]"
  CHECK(a.substr(2, 3) != a.substr(8, 3));

  // "[i]ssissi" vs "ippipp[i]"
  CHECK(b.substr(0, 1) == c.substr(6, 1));

  // "mi[ssi]ssippi" vs "issi[ssi]"
  CHECK(a.substr(2, 3) == b.substr(4, 3));

  // "[ississi]" + "i[ppi]ppi" vs "m[ississippi]"
  CHECK(RHash::concat(b.hash(), c.substr(1, 3)) == a.slice(1, a.size()));
}
