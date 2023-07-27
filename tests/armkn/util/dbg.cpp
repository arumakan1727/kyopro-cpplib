#include <armkn/util/console/color.hpp>
#include <armkn/util/dbg.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/reporters/catch_reporter_event_listener.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>

#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifndef ARMKN_DEBUG

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
#pragma clang diagnostic ignored "-Wunused-parameter"

#undef CHECK
#define CHECK(...) ((void)0)

#endif

const auto RE_DBG_MSG_PREFIX = std::regex(R"([0-9][0-9]*:CATCH2_INTERNAL_TEST_0\(\): )");

namespace {

std::string remove_dbg_prefix(const std::string& msg) {
  return std::regex_replace(msg, RE_DBG_MSG_PREFIX, "");
}

void report_difference(const std::string_view got, const std::string_view want) {
  if (got == want) return;
  for (unsigned i = 0; i < std::min(got.size(), want.size()); ++i) {
    if (got[i] != want[i]) {
      std::clog << "Found difference: i=" << i << ", got[i]=`" << got[i] << "`, want[i]=`"
                << want[i] << '`' << std::endl;

      std::clog << "Near got: `";
      for (int d = -5; d <= 5; ++d) {
        if (i + d < got.size()) std::clog.put(got[i + d]);
      }
      std::clog << "`" << std::endl;

      std::clog << "Near want: `";
      for (int d = -5; d <= 5; ++d) {
        if (i + d < want.size()) std::clog.put(want[i + d]);
      }
      std::clog << "`" << std::endl;

      break;
    }
  }
}

template <class T>
struct SomeStruct {
  T val;

  std::pair<T, T> foo(T x) const noexcept {
    DBG(this->val);
    return {val - x, val + x};
  }
};

}  // namespace

TEST_CASE("dbg", "[dbg]") {
  using namespace std::string_literals;
  std::stringstream ss;

  SECTION("initial state") {
    using namespace ::armkn::console::color;
    static bool executed = false;
    if (!executed) {
#ifdef ARMKN_DEBUG
      REQUIRE(::armkn::dbg::out == &std::clog);
#endif

      DBG_SET_OUTPUT(&ss);
      DBG(5);
      CHECK(
          ss.str() == ""s + MAGENTA + "95" + RESET + ':' + BLUE + "CATCH2_INTERNAL_TEST_0()" +
                          RESET + ": " + CYAN + "5" + WHITE + DIM + "=" + RESET + YELLOW + "5" +
                          RESET + "\n"
      );
      executed = true;
    }
  }

  DBG_DISABLE_COLOR();
  DBG_SET_OUTPUT(&ss);

  SECTION("case of complicated member func") {
    ss.clear();
    SomeStruct<int>{1727}.foo(5);
    CHECK(ss.str().substr(2) == ":foo(): this->val=1727\n");
  }

  SECTION("case of the func is lambda func") {
    ss.clear();
    [](int x) { DBG(x + 1); }(777);
    CHECK(ss.str().substr(3) == ":<lambda>(): x+1=778\n");
  }

  SECTION("primitive arithmetic expr") {
    ss.clear();
    int a = 5, b = 3;

    DBG(a + b);
    DBG(a, b, a * (a / b));
    a = DBGV("hoge", a / b, a * b);

    CHECK(
        remove_dbg_prefix(ss.str()) ==
        "a+b=8\n"                //
        "a=5, b=3, a*(a/b)=5\n"  //
        "\"hoge\", a/b=1, a*b=15\n"
    );
    CHECK(a == 15);
  }

  SECTION("DBGV") {
    ss.clear();
    auto x = DBGV(3.14, "str", false, -1 * 100);
    auto y = DBGV(x);
    CHECK(x == -100);
    CHECK(y == x);
  }

  SECTION("pair") {
    ss.clear();
    const char* s = "hello";
    DBG(std::pair{-1, s});
    CHECK(remove_dbg_prefix(ss.str()) == "std::pair{-1,s}=(-1, hello)\n");
  }

  SECTION("tuple") {
    ss.clear();
    const char* s = "hello";
    const auto t = std::tuple{s, std::pair{7, 4}, 3.14};
    DBG(std::tuple{-5}, t);
    CHECK(remove_dbg_prefix(ss.str()) == "std::tuple{-5}=(-5), t=(hello, (7, 4), 3.14)\n");
  }

  SECTION("vector<int>") {
    ss.clear();
    std::vector<int> empty_vec{}, short_vec{3, 1, 4, 1},
        long_vec{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22}, too_long_vec(233);
    DBG(empty_vec);
    DBG(short_vec);
    DBG(long_vec);
    DBG(too_long_vec);
    const std::string got = remove_dbg_prefix(ss.str());
    constexpr std::string_view want =
        ("empty_vec={}\n"
         "short_vec={3, 1, 4, 1}\n"

         "long_vec={0, 2, 4, 6, 8, [5]10, 12, 14, 16, 18, [10]20, 22}\n"

         "too_long_vec={"
         "0, 0, 0, 0, 0, [5]0, 0, 0, 0, 0, [10]0, 0, 0, 0, 0, [15]0, 0, 0, 0, 0, "
         "[20]0, 0, 0, 0, 0, [25]0, 0, 0, 0, 0, [30]0, 0, 0, 0, 0, [35]0, 0, 0, 0, 0, "
         "[40]0, 0, 0, 0, 0, [45]0, 0, 0, 0, 0, [50]0, 0, 0, 0, 0, [55]0, 0, 0, 0, 0, "
         "[60]0, 0, 0, 0, 0, [65]0, 0, 0, 0, 0, [70]0, 0, 0, 0, 0, [75]0, 0, 0, 0, 0, "
         "[80]0, 0, 0, 0, 0, [85]0, 0, 0, 0, 0, [90]0, 0, 0, 0, 0, [95]0, 0, 0, 0, 0, "
         "[100]0, 0, 0, 0, 0, [105]0, 0, 0, 0, 0, [110]0, 0, 0, 0, 0, [115]0, 0, 0, 0, 0, "
         "..., "
         "[210]0, 0, 0, 0, 0, [215]0, 0, 0, 0, 0, [220]0, 0, 0, 0, 0, [225]0, 0, 0, 0, 0, "
         "[230]0, 0, 0"
         "}\n");
    CHECK(got == want);
    CHECK(got.length() == want.length());
    report_difference(got, want);
  }

  SECTION("vector<deque<vector<int>>>") {
    ss.clear();
    std::array<std::deque<std::vector<int>>, 3> v{
        std::deque{
            std::vector{-1, 0xf, 1, 7, 2, 7, 998244353, 7},
        },
        {},
        {
            {},
            {10, 20, 30},
            {40, 50, 60, 70},
        }};
    DBG(v, v[0][0][0]);
    const auto got = remove_dbg_prefix(ss.str());
    const std::string_view want = R"(v={
  [0] {
    [0] {-1, 15, 1, 7, 2, [5]7, 998244353, 7}
  },
  [1] {},
  [2] {
    [0] {},
    [1] {10, 20, 30},
    [2] {40, 50, 60, 70}
  }
}, v[0][0][0]=-1
)";
    CHECK(got == want);
    CHECK(got.length() == want.length());
    report_difference(got, want);
  }

  SECTION("deque<int>") {
    ss.clear();
    auto a = std::deque{3, 1, 4, 1, 5, 9, 2, 6};
    DBG(a);
    CHECK(remove_dbg_prefix(ss.str()) == "a={3, 1, 4, 1, 5, [5]9, 2, 6}\n");
  }

  SECTION("set<int>") {
    ss.clear();
    auto a = std::set{3, 1, 4, 1, 5, 9, 2, 6};
    DBG(a);
    CHECK(remove_dbg_prefix(ss.str()) == "a={0:1, 2, 3, 4, 5, 5:6, 9}\n");
  }

  SECTION("multiset<array<int, 3>>") {
    ss.clear();
    std::multiset<std::array<int, 3>> a{{3, 1, 4}, {1, 5, 9}, {2}};
    DBG(a);
    const auto got = remove_dbg_prefix(ss.str());
    const std::string_view want = R"(a={
  0: {1, 5, 9},
  1: {2, 0, 0},
  2: {3, 1, 4}
}
)";
    CHECK(remove_dbg_prefix(ss.str()) == want);
  }

  SECTION("list<int> (too long)") {
    ss.clear();
    DBG(std::list<int>(242));
    const auto got = remove_dbg_prefix(ss.str());
    const std::string_view want =
        ("std::list<int>(242)={"
         "0:0, 0, 0, 0, 0, 5:0, 0, 0, 0, 0, 10:0, 0, 0, 0, 0, 15:0, 0, 0, 0, 0, "
         "20:0, 0, 0, 0, 0, 25:0, 0, 0, 0, 0, 30:0, 0, 0, 0, 0, 35:0, 0, 0, 0, 0, "
         "40:0, 0, 0, 0, 0, 45:0, 0, 0, 0, 0, 50:0, 0, 0, 0, 0, 55:0, 0, 0, 0, 0, "
         "60:0, 0, 0, 0, 0, 65:0, 0, 0, 0, 0, 70:0, 0, 0, 0, 0, 75:0, 0, 0, 0, 0, "
         "80:0, 0, 0, 0, 0, 85:0, 0, 0, 0, 0, 90:0, 0, 0, 0, 0, 95:0, 0, 0, 0, 0, "
         "100:0, 0, 0, 0, 0, 105:0, 0, 0, 0, 0, 110:0, 0, 0, 0, 0, 115:0, 0, 0, 0, 0, "
         "..., "
         "0, 0, 0, 240:0, 0"
         "}\n");
    CHECK(got.length() == want.length());
    CHECK(got == want);
    report_difference(got, want);
  }

  SECTION("map<int, int>") {
    ss.clear();
    auto m = std::map<int, int>{{-1, 5}, {2, 7}, {-4, 998244353}};
    auto empty = std::map<int, int>{};
    DBG(m, empty);
    CHECK(remove_dbg_prefix(ss.str()) == "m={[-4]=998244353, [-1]=5, [2]=7}, empty={}\n");
  }

  SECTION("unordered_multimap<int, int>") {
    ss.clear();
    auto m = std::unordered_multimap<int, int>{{-1, 5}};
    DBG(m);
    CHECK(remove_dbg_prefix(ss.str()) == "m={[-1]=5}\n");
  }

  SECTION("map<int, string_view>") {
    ss.clear();
    auto m = std::map<int, std::string_view>{{-1, "hoge"}, {2, "foo"}, {-4, "bar"}};
    DBG(m);
    CHECK(remove_dbg_prefix(ss.str()) == "m={[-4]=bar, [-1]=hoge, [2]=foo}\n");
  }

  SECTION("map<pair<int, int>, char>") {
    ss.clear();
    auto m = std::map<std::pair<int, int>, char>{{{3, 1}, 'a'}, {{4, 1}, 'b'}, {{0, 9}, 'c'}};
    DBG(m);
    CHECK(remove_dbg_prefix(ss.str()) == "m={[(0, 9)]=c, [(3, 1)]=a, [(4, 1)]=b}\n");
  }

  SECTION("map<string_view, int>") {
    ss.clear();
    auto m = std::map<std::string_view, int>{{"hoge", 5}, {"foo", 3}, {"bar", 8}};
    DBG(m);
    const std::string_view want = R"(m={
  [bar]=8,
  [foo]=3,
  [hoge]=5
}
)";
    CHECK(remove_dbg_prefix(ss.str()) == want);
  }

  SECTION("map<int, set<int>>") {
    ss.clear();
    auto m = std::map<int, std::unordered_set<int>>{{3, {}}, {1, {3, 1}}, {4, {998244353}}};
    DBG(m);
    const std::string_view want = R"(m={
  [1]={0:1, 3},
  [3]={},
  [4]={0:998244353}
}
)";
    CHECK(remove_dbg_prefix(ss.str()) == want);
  }

  SECTION("map<array<int, 3>, set<int>>") {
    ss.clear();
    auto m = std::map<std::array<int, 3>, std::set<int>>{{{3, 1, 4}, {}}, {{1, 1, 1}, {1, 3, 3}}};
    DBG(m);
    const std::string_view want = R"(m={
  [{1, 1, 1}]={0:1, 3},
  [{3, 1, 4}]={}
}
)";
    CHECK(remove_dbg_prefix(ss.str()) == want);
  }
}

namespace {

class TestStartHook : public Catch::EventListenerBase {
 public:
  using Catch::EventListenerBase::EventListenerBase;

  void testRunStarting(Catch::TestRunInfo const& info) override {
    DBG(info.name);

    using std::array;
    using std::deque;
    using std::pair;
    using std::string;
    using std::tuple;
    using std::vector;

    DBG("hello");
    DBG(string("hello"));
    DBG(tuple{-1 * 5, pair{0x3f3f3f3f, false}, "hello"});
    DBG(deque<pair<int, int>>{{0, 3}, {1, 4}, {1, 5}, {9, 2}, {6, 5}, {3, 5}});
    DBG(vector<int>{});
    DBG(array<string, 3>{"hoge", "foo", "bar"});
    DBG(vector<int>(302));

    auto vec_3d = vector<vector<vector<int>>>{
        {
            {-1, 0x3f3f3f3f, 1, 7, 2, 7, 998244353, 7},
        },
        {},
        {
            {},
            {10, 20, 30},
            {40, 50, 60},
        }};
    std::multiset<int> large_multiset;
    for (unsigned i = 0; i < 302; ++i) large_multiset.insert(i);

    auto map_pair2int =
        std::map<std::pair<int, int>, char>{{{3, 1}, 'a'}, {{4, 1}, 'b'}, {{0, 9}, 'c'}};

    DBG(vec_3d);
    DBG(std::set{3, 1, 4, 1, 5, 9, 2, 6, 5});
    DBG(std::list{3, 1, 4, 1, 5, 9, 2, 6, 5});
    DBG(large_multiset);
    DBG(map_pair2int);
    DBG(std::map<int, int>{{-1, 5}, {-2, 7}, {-4, 0x3f3f3f3f}});
    DBG(std::map<int, std::string_view>{{-1, "hoge"}, {-2, "foo"}, {-4, "bar"}});
    DBG(std::map<std::string_view, int>{{"hoge", 5}, {"foo", 3}, {"bar", 8}});
  }
};

}  // namespace

CATCH_REGISTER_LISTENER(TestStartHook)

#ifndef ARMKN_DEBUG

#pragma GCC diagnostic pop
#pragma clang diagnostic pop

#endif
