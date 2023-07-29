#include <armkn/util/fn/match_2d.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cctype>
#include <string_view>
#include <vector>

TEST_CASE("match_2d", "[util/fn]") {
  const auto mat = std::vector<std::string_view>{
      "abcdefgf",  //
      "xyz",       //
      "hjkl"       //
  };

  SECTION("should return true") {
    const auto pattern1 = std::vector<std::string_view>{
        "z",
        "kl",
    };
    const auto pattern2 = std::vector<std::string_view>{
        "l",
    };
    CHECK(match_2d(mat, mat, 0, 0));
    CHECK(match_2d(mat, pattern1, 1, 2));
    CHECK(match_2d(mat, pattern2, 2, 3));
  }
  SECTION("should retrun false") {
    const auto pattern1 = std::vector<std::string_view>{
        "abcdef",
        "xyz",
        "hjkX",
    };
    const auto pattern2 = std::vector<std::string_view>{
        "abcde_",
        "xyz",
        "hjkl",
    };
    const auto pattern3 = std::vector<std::string_view>{
        "abcdef",
        "xyz",
        "?jkl",
    };
    CHECK_FALSE(match_2d(mat, mat, 0, 1));
    CHECK_FALSE(match_2d(mat, mat, 1, 0));
    CHECK_FALSE(match_2d(mat, mat, 99999, 99999));
    CHECK_FALSE(match_2d(mat, pattern1, 0, 0));
    CHECK_FALSE(match_2d(mat, pattern2, 0, 0));
    CHECK_FALSE(match_2d(mat, pattern3, 0, 0));
  }
  SECTION("custom matcher fn") {
    const auto pattern = std::vector<std::string_view>{
        "ABCDEF",
        "XYZ",
        "HJKL",
    };
    CHECK_FALSE(match_2d(mat, pattern, 0, 0));
    CHECK(match_2d(mat, pattern, 0, 0, [&](u32 r, u32 c, u32 i, u32 j) {
      return mat[r][c] == std::tolower(pattern[i][j]);
    }));
  }
}

TEST_CASE("match_2d_with_special_char", "[util/fn]") {
  const auto mat = std::vector<std::string_view>{
      "abcdefgf",  //
      "xyz",       //
      "hjkl"       //
  };

  SECTION("should return true") {
    const auto pattern1 = std::vector<std::string_view>{
        "????????",  //
        "???",       //
        "????"       //
    };
    const auto pattern2 = std::vector<std::string_view>{
        "z",
        "*l",
    };
    const auto pattern3 = std::vector<std::string_view>{
        "~",
    };
    CHECK(match_2d_with_special_char(mat, mat, 0, 0, '?'));
    CHECK(match_2d_with_special_char(mat, pattern1, 0, 0, '?'));
    CHECK(match_2d_with_special_char(mat, pattern2, 1, 2, '*'));
    CHECK(match_2d_with_special_char(mat, pattern3, 2, 3, '~'));
  }
  SECTION("should return false") {
    const auto pattern1 = std::vector<std::string_view>{
        "??????",
        "????",
        "????",
    };
    const auto pattern2 = std::vector<std::string_view>{
        "abcde?",
        "xy_",
        "hjkl",
    };
    const auto pattern3 = std::vector<std::string_view>{
        "abcdef",
        "xy?",
        "*jkl",
    };
    CHECK_FALSE(match_2d_with_special_char(mat, mat, 0, 1, '?'));
    CHECK_FALSE(match_2d_with_special_char(mat, mat, 1, 0, '?'));
    CHECK_FALSE(match_2d_with_special_char(mat, mat, 99999, 99999, '?'));
    CHECK_FALSE(match_2d_with_special_char(mat, pattern1, 0, 0, '?'));
    CHECK_FALSE(match_2d_with_special_char(mat, pattern2, 0, 0, '?'));
    CHECK_FALSE(match_2d_with_special_char(mat, pattern3, 0, 0, '?'));
  }
}
