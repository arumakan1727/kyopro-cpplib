#include <armkn/util/constants/infinity.hpp>
#include <catch2/catch_test_macros.hpp>
#include <limits>

TEST_CASE("infinity", "[constants]") {
  // チェック項目
  // 2倍してもオーバーフローしない
  // 32bit => 10^9 より大きい
  // 64bit => 2 * 10^18 より大きい

  SECTION("int32_t") {
    using T = int32_t;
    constexpr auto INF = infinity<T>;
    CHECK(INF > 1'000'000'000);
    CHECK(INF <= std::numeric_limits<T>::max() >> 1);
  }
  SECTION("uint32_t") {
    using T = uint32_t;
    constexpr auto INF = infinity<T>;
    CHECK(INF > 1'000'000'000);
    CHECK(INF <= std::numeric_limits<T>::max() >> 1);
  }
  SECTION("int64_t") {
    using T = int64_t;
    constexpr auto INF = infinity<T>;
    CHECK(INF > 2'000'000'000'000'000'000);
    CHECK(INF <= std::numeric_limits<T>::max() >> 1);
  }
  SECTION("uint64_t") {
    using T = uint64_t;
    constexpr auto INF = infinity<T>;
    CHECK(INF > 2'000'000'000'000'000'000);
    CHECK(INF <= std::numeric_limits<T>::max() >> 1);
  }
}
