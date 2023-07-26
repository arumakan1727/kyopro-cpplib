#include <armkn/dbg/dbg.hpp>
#include <catch2/catch_test_macros.hpp>

#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace {

int func_with_arg(int a) {
  return DBGV(a) * 100;
}

template <class T>
struct SomeStruct {
  T val;

  std::pair<T, T> foo() const noexcept {
    DBG(this->val);
    return {val, val};
  }
};

}  // namespace

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
        ss.str() == ""s + MAGENTA + "47" + NOCOLOR + ':' + BLUE + "CATCH2_INTERNAL_TEST_0()" +
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

    int a = 5, b = 3;
    DBG(a + b);

    DBG_DISABLE_COLOR();  // Check idempotence

    DBG(a, b, a * (a / b));

    [[maybe_unused]] int c = DBGV("hoge", a / b, a * b);
    CHECK(
        ss.str() ==
        "64:CATCH2_INTERNAL_TEST_0(): a+b=8\n"                //
        "68:CATCH2_INTERNAL_TEST_0(): a=5, b=3, a*(a/b)=5\n"  //
        "70:CATCH2_INTERNAL_TEST_0(): \"hoge\", a/b=1, a*b=15\n"
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
        ss.str() == ""s + MAGENTA + "86" + NOCOLOR + ':' + BLUE + "CATCH2_INTERNAL_TEST_0()" +
                        NOCOLOR + ": " + CYAN + "a" + WHITE + DIM + "=" + NOCOLOR + YELLOW + "5" +
                        NOCOLOR + "\n"
    );
  }

  DBG_DISABLE_COLOR();

  SECTION("case of the func has argument") {
    ss.clear();
    func_with_arg(5);
    CHECK(ss.str() == "19:func_with_arg(): a=5\n");
  }

  SECTION("case of member function in template class") {
    ss.clear();
    SomeStruct<int>{1727}.foo();
    CHECK(ss.str() == "27:foo(): this->val=1727\n");
  }

  SECTION("case of the func is lambda func") {
    ss.clear();
    [](int x) { DBG(x + 1); }(777);
    CHECK(ss.str() == "110:<lambda>(): x+1=778\n");
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
    CHECK(ss.str() == "126:CATCH2_INTERNAL_TEST_0(): std::pair{-1,s}=(-1, hello)\n");
  }

  SECTION("tuple") {
    ss.clear();
    const char* s = "hello";
    const auto t = std::tuple{s, std::pair{7, 4}, 3.14};
    DBG(std::tuple{-5}, t);
    CHECK(
        ss.str() == "134:CATCH2_INTERNAL_TEST_0(): std::tuple{-5}=(-5), t=(hello, (7, 4), 3.14)\n"
    );
  }

  /* SECTION("vector<int>") { */
  /*   ss.clear(); */
  /*   std::vector<int> empty_vec{}, short_vec{3, 1, 4, 1}, */
  /*       long_vec{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22}, too_long_vec(203); */
  /*   DBG(empty_vec); */
  /*   DBG(short_vec); */
  /*   DBG(long_vec); */
  /*   DBG(too_long_vec); */
  /*   CHECK( */
  /*       ss.str() == */
  /*       "121:CATCH2_INTERNAL_TEST_0(): empty_vec={}\n" */
  /*       "122:CATCH2_INTERNAL_TEST_0(): short_vec={3, 1, 4, 1}\n" */
  /**/
  /*       "123:CATCH2_INTERNAL_TEST_0():"  // */
  /*       " long_vec={[0]=0, 2, 4, 6, 8, [5]=10, 12, 14, 16, 18, [10]=20, 22}\n" */
  /**/
  /*       "124:CATCH2_INTERNAL_TEST_0(): \n"  // */
  /*       " too_long_vec={"                   // */
  /*       "  [  0]=0, 0, 0, 0, 0, [  5]=0, 0, 0, 0, 0, [ 10]=0, 0, 0, 0, 0, [ 15]=0, 0, 0, 0, 0,\n"
   */
  /*       "  [ 20]=0, 0, 0, 0, 0, [ 25]=0, 0, 0, 0, 0, [ 30]=0, 0, 0, 0, 0, [ 35]=0, 0, 0, 0, 0,\n"
   */
  /*       "  [ 40]=0, 0, 0, 0, 0, [ 45]=0, 0, 0, 0, 0, [ 50]=0, 0, 0, 0, 0, [ 55]=0, 0, 0, 0, 0,\n"
   */
  /*       "  [ 60]=0, 0, 0, 0, 0, [ 65]=0, 0, 0, 0, 0, [ 70]=0, 0, 0, 0, 0, [ 75]=0, 0, 0, 0, 0,\n"
   */
  /*       "  [ 80]=0, 0, 0, 0, 0, [ 85]=0, 0, 0, 0, 0, [ 90]=0, 0, 0, 0, 0, [ 95]=0, 0, 0, 0, 0,\n"
   */
  /*       "  [100]=0, 0, 0, 0, 0, [105]=0, 0, 0, 0, 0, [110]=0, 0, 0, 0, 0, [115]=0, 0, 0, 0, 0,\n"
   */
  /*       "  ...\n"  // */
  /*       "  [180]=0, 0, 0, 0, 0, [185]=0, 0, 0, 0, 0, [190]=0, 0, 0, 0, 0, [195]=0, 0, 0, 0, 0,\n"
   */
  /*       "  [200]=0, 0, 0\n"  // */
  /*       " }\n" */
  /*   ); */
  /* } */
  /* SECTION("vector<vector<int>>") { */
  /*   ss.clear(); */
  /*   std::vector<std::vector<int>> small{ */
  /*       {0, 1}, */
  /*       {10, 20, 30}, */
  /*   }; */
  /*   std::vector<std::vector<int>> large{ */
  /*       {3, 1, 4, 1, 5, 9, 2}, */
  /*       {-1, 5, -30, 999}, */
  /*       {}, */
  /*       {-1, 0, 0, -0x3f3f3f3f, 1727}, */
  /*   }; */
  /*   DBG(small, large); */
  /*   CHECK( */
  /*       ss.str() == */
  /*       "159:CATCH2_INTERNAL_TEST_0(): \n" */
  /*       " small={\n"                                 // */
  /*       "       [0] [1] [2]\n"                       // */
  /*       "  [0] { 0,  1}\n"                           // */
  /*       "  [1] {10, 20, 30}\n"                       // */
  /*       " },\n"                                      // */
  /*       " small={\n"                                 // */
  /*       "       [0] [1]  [2]   [3]   [4] [5] [6]\n"  // */
  /*       "  [0] { 3,  1,   4,    1,    5,  9,  2}\n"  // */
  /*       "  [1] {-1,  5, -30,  999}\n"                // */
  /*       "  [2] {},\n"                                // */
  /*       "  [3] {-1,  0,   0, -INF, 1727}\n"          // */
  /*       " },\n" */
  /*   ); */
  /* } */
  SECTION("deque") {}
  SECTION("set") {}
  SECTION("map") {}
}
