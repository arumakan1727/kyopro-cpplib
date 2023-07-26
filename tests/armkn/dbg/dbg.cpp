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

static int f(int a) {
  return DBGV(a) * 100;
}

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
        ss.str() == ""s + MAGENTA + "30" + NOCOLOR + ':' + BLUE + "CATCH2_INTERNAL_TEST_0()" +
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

    const std::string line_chk0 = "51";
    const std::string line_chk1 = "56";
    const std::string line_chk2 = "62";

    int a = 5, b = 3;
    DBG(a + b);
    CHECK(ss.str() == line_chk0 + ":CATCH2_INTERNAL_TEST_0(): a+b=8\n");

    DBG_DISABLE_COLOR();  // Check idempotence

    DBG(a, b, a * (a / b));
    CHECK(
        ss.str() == line_chk0 + ":CATCH2_INTERNAL_TEST_0(): a+b=8\n" +  //
                        line_chk1 + ":CATCH2_INTERNAL_TEST_0(): a=5, b=3, a*(a/b)=5\n"
    );

    [[maybe_unused]] int c = DBGV("hoge", a / b, a * b);
    CHECK(
        ss.str() == line_chk0 + ":CATCH2_INTERNAL_TEST_0(): a+b=8\n" +                    //
                        line_chk1 + ":CATCH2_INTERNAL_TEST_0(): a=5, b=3, a*(a/b)=5\n" +  //
                        line_chk2 + ":CATCH2_INTERNAL_TEST_0(): \"hoge\", a/b=1, a*b=15\n"
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
        ss.str() == ""s + MAGENTA + "77" + NOCOLOR + ':' + BLUE + "CATCH2_INTERNAL_TEST_0()" +
                        NOCOLOR + ": " + CYAN + "a" + WHITE + DIM + "=" + NOCOLOR + YELLOW + "5" +
                        NOCOLOR + "\n"
    );
  }

  DBG_DISABLE_COLOR();

  SECTION("case of the func has argument") {
    ss.clear();
    f(5);
    CHECK(ss.str() == "14:f(): a=5\n");
  }

  SECTION("case of the func is lambda func") {
    ss.clear();
    [](int x) { DBG(x + 1); }(777);
    CHECK(ss.str() == "95:<lambda>(): x+1=778\n");
  }

  SECTION("DBGV") {
    ss.clear();
    auto x = DBGV(3.14, "str", false, -1 * 100);
    CHECK(x == -100);

    auto y = DBGV(x);
    CHECK(y == x);
  }

  SECTION("pair") {
    ss.clear();
    const char* s = "hello";
    DBG(std::pair{-1, s});
    CHECK(ss.str() == "111:CATCH2_INTERNAL_TEST_0(): std::pair{-1,s}=(-1, hello)\n");
  }

  SECTION("tuple") {
    ss.clear();
    const char* s = "hello";
    const auto t = std::tuple{s, std::pair{7, 4}, 3.14};
    DBG(std::tuple{-5}, t);
    CHECK(
        ss.str() == "119:CATCH2_INTERNAL_TEST_0(): std::tuple{-5}=(-5), t=(hello, (7, 4), 3.14)\n"
    );
  }

  SECTION("1D vector") {}
  SECTION("2D vector") {}
  SECTION("deque") {}
  SECTION("set") {}
  SECTION("map") {}
}
