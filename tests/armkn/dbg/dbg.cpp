#include <armkn/dbg/dbg.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("dbg", "[dbg]") {
  int a = 5;
  int b = 3;
  DBG(a + b);
  DBG(a, b, a - b, a * (a / b));
  DBG(a, "hoge", b);
  int x = DBGV(a, "xxx", a + b);
  DBG(x);
}
