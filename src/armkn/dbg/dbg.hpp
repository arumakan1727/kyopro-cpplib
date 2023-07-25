#pragma once
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#ifdef ARMKN_DEBUG

#define DBG(...) \
  ((void         \
  )::armkn::dbg::internal::DebugPrinter(__LINE__, __PRETTY_FUNCTION__, #__VA_ARGS__)(__VA_ARGS__))

#define DBGV(...) \
  ::armkn::dbg::internal::DebugPrinter(__LINE__, __PRETTY_FUNCTION__, #__VA_ARGS__)(__VA_ARGS__)

#define DBG_SET_OUTPUT(ostream_ptr) ::armkn::dbg::internal::out = (ostream_ptr)

#define DBG_ENABLE_COLOR() ::armkn::dbg::color::enable_color()

#define DBG_DISABLE_COLOR() ::armkn::dbg::color::disable_color()

namespace armkn::dbg {
using ::std::string;
using ::std::vector;

namespace color {

const char *BLACK, *RED, *GREEN, *YELLOW, *BLUE, *MAGENTA, *CYAN, *WHITE, *DIM, *NOCOLOR;

__attribute__((constructor)) void enable_color() {
  BLACK = "\x1b[30;1m";
  RED = "\x1b[31;1m";
  GREEN = "\x1b[32;1m";
  YELLOW = "\x1b[33;1m";
  BLUE = "\x1b[34;1m";
  MAGENTA = "\x1b[35;1m";
  CYAN = "\x1b[36;1m";
  WHITE = "\x1b[37;1m";
  DIM = "\x1b[;2m";
  NOCOLOR = "\x1b[;m";
}

void disable_color() {
  BLACK = "";
  RED = "";
  GREEN = "";
  YELLOW = "";
  BLUE = "";
  MAGENTA = "";
  CYAN = "";
  WHITE = "";
  DIM = "";
  NOCOLOR = "";
}

}  // namespace color

namespace internal {

using namespace ::armkn::dbg::color;

template <class T1, class T2>
std::ostream& operator<<(std::ostream& o, const std::pair<T1, T2>& p) {
  return o << '(' << p.first << ", " << p.second << ')';
}

std::ostream* out = &std::clog;

class DebugPrinter {
  const unsigned line_no;
  const char* const pretty_func_name;
  const vector<string> args;
  vector<string>::const_iterator itr;

 public:
  DebugPrinter(unsigned line_no, const char* pretty_func, const char* args_str)
      : line_no(line_no),
        pretty_func_name(
            // remove prefix (e.g. "int main()" => "main()")
            std::strchr(pretty_func, ' ') + 1
        ),
        args(split_and_remove_whitespace(args_str)),
        itr(args.cbegin()) {}

  template <class... T>
  auto operator()(T&&... xs) {
    *out << BLUE << pretty_func_name << NOCOLOR << ':' << MAGENTA << line_no << NOCOLOR << ": ";
    return print(std::forward<T>(xs)...);
  }

 private:
  void print() const {
    *out << std::endl;
  }

  template <class Head, class... Tail>
  auto print(Head&& x, Tail&&... tail) {
    put(std::forward<Head>(x));
    ++itr;
    if constexpr (sizeof...(tail)) {
      *out << ", ";
      return print(std::forward<Tail>(tail)...);
    } else {
      print();
      return x;
    }
  }

  template <class T>
  void put(T&& x) const {
    // if string literal, show just value
    if ((*itr)[0] == '"') {
      *out << '"' << GREEN << x << NOCOLOR << '"';
    } else {
      *out << CYAN << *itr << WHITE << DIM << '=' << NOCOLOR << YELLOW << x << NOCOLOR;
    }
  }

  auto split_and_remove_whitespace(const char* s) -> vector<string> {
    vector<string> res;
    char buf[128], *buf_end = buf;
    res.reserve(8);
    unsigned paren = 0, brace = 0, bracket = 0;

    for (; *s != '\0'; ++s) {
      if (std::isspace(*s)) continue;

      if (*s == ',' && paren == 0 && brace == 0 && bracket == 0) {
        res.emplace_back(buf, buf_end);
        buf_end = buf;
        continue;
      }
      *buf_end++ = *s;

      if (*s == '(')
        ++paren;
      else if (*s == ')')
        --paren;
      else if (*s == '{')
        ++brace;
      else if (*s == '}')
        --brace;
      else if (*s == '[')
        ++bracket;
      else if (*s == ']')
        --bracket;
    }

    res.emplace_back(buf, buf_end);
    return res;
  }
};

}  // namespace internal

}  // namespace armkn::dbg

#else

#define DBG(...) ((void)0)
#define DBGV(...) (__VA_ARGS__)
#define DBG_SET_OUTPUT(ostream) ((void)0)
#define DBG_ENABLE_COLOR() ((void)0)
#define DBG_DISABLE_COLOR() ((void)0)

#endif
