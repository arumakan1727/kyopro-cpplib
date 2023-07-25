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

  DBG_SET_OUTPUT(&std::clog);
  DBG("hello");

  SECTION("without color") {
    std::stringstream ss;
    DBG_DISABLE_COLOR();
    DBG_SET_OUTPUT(&ss);

    const std::string line_chk0 = "30";
    const std::string line_chk1 = "35";
    const std::string line_chk2 = "41";

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

  SECTION("with color") {
    using namespace ::armkn::dbg::color;
    std::stringstream ss;
    DBG_ENABLE_COLOR();
    DBG_ENABLE_COLOR();  // Check idempotence
    DBG_SET_OUTPUT(&ss);

    int a = 5;

    DBG(a);
    CHECK(
        ss.str() == ""s + BLUE + "CATCH2_INTERNAL_TEST_0()" + NOCOLOR + ':' + MAGENTA + "58" +
                        NOCOLOR + ": " + CYAN + "a" + WHITE + DIM + "=" + NOCOLOR + YELLOW + "5" +
                        NOCOLOR + "\n"
    );
  }
}
