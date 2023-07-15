#include <armkn/fmt/printer.hpp>
#include <catch2/catch_test_macros.hpp>
#include <set>
#include <sstream>
#include <vector>

TEST_CASE("Printer", "[fmt][fmt/Printer]") {
  std::stringstream ss;
  auto sprint = print.to(ss);

  std::vector<int> vec{3, 1, 4, 1, 5};
  std::set<std::string> set{"hoge", "xyz", "abc"};

  SECTION("Calling with no args will newline") {
    sprint();
    CHECK(ss.str() == "\n");
  }
  SECTION("Calling with one argument") {
    sprint(1727);
    sprint('!');
    CHECK(ss.str() == "1727\n!\n");
  }
  SECTION("Calling with multiple argument") {
    sprint(1727, "hello");
    sprint('a', -3, true, 3.14);
    CHECK(ss.str() == "1727 hello\na -3 1 3.14\n");
  }
  SECTION("each(iterable)") {
    sprint.each(vec);
    sprint.each(set);
    CHECK(ss.str() == "3 1 4 1 5\nabc hoge xyz\n");
  }
  SECTION("lines(iterable)") {
    sprint.lines(vec);
    sprint.lines(set);
    CHECK(ss.str() == "3\n1\n4\n1\n5\nabc\nhoge\nxyz\n");
  }
  SECTION("change sep str") {
    sprint.sep(",")("hello", 1727, '!');
    sprint.sep(",").each(vec);
    sprint.sep(",").lines(vec);
    CHECK(ss.str() == "hello,1727,!\n3,1,4,1,5\n3\n1\n4\n1\n5\n");
  }
  SECTION("change end str") {
    sprint.ends(";;")("hello", 1727, '!');
    sprint.ends("ฅ^•ω•^ฅ").each(vec);
    sprint.ends("|").lines(vec);
    CHECK(ss.str() == "hello 1727 !;;3 1 4 1 5ฅ^•ω•^ฅ3\n1\n4\n1\n5|");
  }
  SECTION("yesno(cond)") {
    sprint.yesno(true);
    sprint.yesno(false);
    CHECK(ss.str() == "yes\nno\n");
  }
  SECTION("YESNO(cond)") {
    sprint.YESNO(true);
    sprint.YESNO(false);
    CHECK(ss.str() == "YES\nNO\n");
  }
  SECTION("YesNo(cond)") {
    sprint.YesNo(true);
    sprint.YesNo(false);
    CHECK(ss.str() == "Yes\nNo\n");
  }
}
