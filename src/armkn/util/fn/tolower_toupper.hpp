#pragma once
#include <cctype>
#include <string>

[[nodiscard]] inline char tolower(char c) noexcept {
  return (char)std::tolower(c);
}

[[nodiscard]] inline char toupper(char c) noexcept {
  return (char)std::toupper(c);
}

[[nodiscard]] inline std::string tolower(std::string const& s) noexcept {
  std::string res;
  res.reserve(s.size());
  for (const char c : s) res += tolower(c);
  return res;
}

[[nodiscard]] inline std::string toupper(std::string const& s) noexcept {
  std::string res;
  res.reserve(s.size());
  for (const char c : s) res += toupper(c);
  return res;
}
