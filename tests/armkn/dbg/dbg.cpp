#include <armkn/dbg/dbg.hpp>
#include <catch2/catch_test_macros.hpp>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

TEST_CASE("dbg", "[dbg]") {
  using namespace std::string_literals;
  using std::string;

  // Check initial value
  static bool is_first_test = true;
  if (is_first_test) {
    REQUIRE(::armkn::dbg::internal::out == &std::clog);

    std::stringstream ss;
    DBG_SET_OUTPUT(&ss);

    using namespace ::armkn::dbg::color;
    DBG(5);
    CHECK(
        ss.str() == ""s + BLUE + "CATCH2_INTERNAL_TEST_0()" + NOCOLOR + ':' + MAGENTA + "26" +
                        NOCOLOR + ": " + CYAN + "5" + WHITE + DIM + "=" + NOCOLOR + YELLOW + "5" +
                        NOCOLOR + "\n"
    );
    is_first_test = false;
  }

  std::stringstream ss;
  DBG_SET_OUTPUT(&ss);

  SECTION("DBG_DISABLE_COLOR") {
    ss.clear();
    DBG_DISABLE_COLOR();

    const std::string line_chk0 = "47";
    const std::string line_chk1 = "52";
    const std::string line_chk2 = "58";

    int a = 5, b = 3;
    DBG(a + b);
    CHECK(ss.str() == "CATCH2_INTERNAL_TEST_0():" + line_chk0 + ": a+b=8\n");

    DBG_DISABLE_COLOR();  // Check idempotence

    DBG(a, b, a * (a / b));
    CHECK(
        ss.str() == "CATCH2_INTERNAL_TEST_0():" + line_chk0 + ": a+b=8\n" +
                        "CATCH2_INTERNAL_TEST_0():" + line_chk1 + ": a=5, b=3, a*(a/b)=5\n"
    );

    [[maybe_unused]] int c = DBGV("hoge", a / b, a * b);
    CHECK(
        ss.str() == "CATCH2_INTERNAL_TEST_0():" + line_chk0 + ": a+b=8\n" +
                        "CATCH2_INTERNAL_TEST_0():" + line_chk1 + ": a=5, b=3, a*(a/b)=5\n" +
                        "CATCH2_INTERNAL_TEST_0():" + line_chk2 + ": \"hoge\", a/b=1, a*b=15\n"
    );
  }

  SECTION("DBG_ENABLE_COLOR") {
    using namespace ::armkn::dbg::color;
    ss.clear();
    DBG_ENABLE_COLOR();
    DBG_ENABLE_COLOR();  // Check idempotence

    int a = 5;
    DBG(a);
    CHECK(
        ss.str() == ""s + BLUE + "CATCH2_INTERNAL_TEST_0()" + NOCOLOR + ':' + MAGENTA + "73" +
                        NOCOLOR + ": " + CYAN + "a" + WHITE + DIM + "=" + NOCOLOR + YELLOW + "5" +
                        NOCOLOR + "\n"
    );
  }

  SECTION("DBGV") {
    ss.clear();
    auto x = DBGV(3.14, "str", false, -1 * 100);
    CHECK(x == -100);

    auto y = DBGV(x);
    CHECK(y == x);
  }

  DBG_DISABLE_COLOR();

  SECTION("pair") {
    ss.clear();
    const char* s = "hello";
    DBG(std::pair{-1, s});
    CHECK(ss.str() == "CATCH2_INTERNAL_TEST_0():95: std::pair{-1,s}=(-1, hello)\n");
  }

  SECTION("tuple") {
    ss.clear();
    const char* s = "hello";
    const auto t = std::tuple{s, std::pair{7, 4}, 3.14};
    DBG(std::tuple{-5}, t);
    CHECK(
        ss.str() == "CATCH2_INTERNAL_TEST_0():103: std::tuple{-5}=(-5), t=(hello, (7, 4), 3.14)\n"
    );
  }

  SECTION("1D vector") {}
  SECTION("2D vector") {}
  SECTION("deque") {}
  SECTION("set") {}
  SECTION("map") {}
}
