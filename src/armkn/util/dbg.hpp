#pragma once

#ifndef ARMKN_DEBUG

#define DBG(...) ((void)0)
#define DBGV(...) (__VA_ARGS__)
#define DBG_SET_OUTPUT(ostream) ((void)0)
#define DBG_ENABLE_COLOR() ((void)0)
#define DBG_DISABLE_COLOR() ((void)0)

#else

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include "../graph/model/Edge3.hpp"
#include "../graph/model/weighted_graph.hpp"
#include "console/color.hpp"
#include "type_traits/is_iterable.hpp"
#include "type_traits/is_key_value_map.hpp"
#include "type_traits/is_random_accessible.hpp"
#include "type_traits/is_string_like.hpp"

#define DBG(...) \
  ((void         \
  )::armkn::dbg::DebugPrinter(__LINE__, __func__, __PRETTY_FUNCTION__, #__VA_ARGS__)(__VA_ARGS__))

#define DBGV(...) \
  ::armkn::dbg::DebugPrinter(__LINE__, __func__, __PRETTY_FUNCTION__, #__VA_ARGS__)(__VA_ARGS__)

#define DBG_SET_OUTPUT(ostream_ptr) ::armkn::dbg::out = (ostream_ptr)

#define DBG_ENABLE_COLOR() ::armkn::dbg::enable_color()

#define DBG_DISABLE_COLOR() ::armkn::dbg::disable_color()

namespace armkn::dbg {

using ::std::string;
using ::std::vector;
using namespace ::armkn::console::color;

template <class T1, class T2>
std::ostream& operator<<(std::ostream& o, const std::pair<T1, T2>& p) {
  return o << RESET << '(' << YELLOW << p.first << RESET << ", " << YELLOW << p.second << RESET
           << ')';
}

template <class Tuple>
void write_tuple_elements(std::ostream& o, Tuple&&, std::index_sequence<>) {
  o << RESET << ')';
}

template <class Tuple, std::size_t Index, std::size_t... RestIndexes>
void write_tuple_elements(std::ostream& o, Tuple&& t, std::index_sequence<Index, RestIndexes...>) {
  if constexpr (Index == 0) {
    o << RESET << '(';
  } else {
    o << RESET << ", ";
  }
  o << YELLOW << std::get<Index>(t);
  write_tuple_elements(o, t, std::index_sequence<RestIndexes...>{});
}

template <class... T>
std::ostream& operator<<(std::ostream& o, const std::tuple<T...>& t) {
  write_tuple_elements(o, t, std::index_sequence_for<T...>{});
  return o;
}

template <class Weight>
std::ostream& operator<<(std::ostream& o, const Edge<Weight>& e) {
  return o << RESET << '(' << YELLOW << e.to << RESET << ", " << YELLOW << e.w << RESET << ')';
}

template <class Weight>
std::ostream& operator<<(std::ostream& o, const Edge3<Weight>& e) {
  return o << RESET << '(' << YELLOW << e.from << RESET << ", " << YELLOW << e.to << RESET << ", "
           << YELLOW << e.w << RESET << ')';
}

template <class T>
inline std::size_t nchars(const T& x) {
  std::stringstream ss;
  ss << x;
  return ss.str().length();
}

inline void indent(std::ostream& o, int level) {
  int w = level << 1;
  while (w-- > 0) o.put(' ');
}

template <
    class Iterable,
    std::enable_if_t<armkn::is_string_like_v<Iterable>, std::nullptr_t> = nullptr>
void write_iterable(std::ostream& o, const Iterable& xs, [[maybe_unused]] int nest = 0) {
  o << GREEN << xs << RESET;
}

// For random accessible container
template <
    class Iterable,
    std::enable_if_t<
        not armkn::is_string_like_v<Iterable> && armkn::is_random_accessible_v<Iterable>,
        std::nullptr_t> = nullptr>
void write_iterable(std::ostream& o, const Iterable& xs, int nest = 0) {
  using elem_type = std::decay_t<decltype(*std::begin(xs))>;
  constexpr bool should_nest =
      not armkn::is_string_like_v<elem_type> && armkn::is_iterable_v<elem_type>;

  constexpr unsigned OMISSION_N = should_nest ? 30 : 120;
  constexpr unsigned OMMSSION_TAIL_SHOW_N = should_nest ? 5 : 20;

  const size_t n = std::end(xs) - std::begin(xs);
  const size_t limitted_n = (n > OMISSION_N + OMMSSION_TAIL_SHOW_N) ? OMISSION_N : n;
  const auto idx_nchars = (int)nchars(n - 1);

  o << RESET << '{';

  size_t i = 0;
  const auto begin = std::begin(xs);

  while (i < n) {
    if (i == limitted_n) {
      o << RED << "..., " << RESET;
      i = 5 * ((n - OMMSSION_TAIL_SHOW_N) / 5);
      continue;
    }

    if constexpr (should_nest) {
      o << "\n";
      indent(o, nest + 1);
      o << DIM << WHITE << '[' << CYAN << std::setw(idx_nchars) << i << WHITE << "] " << RESET;
      write_iterable(o, begin[i], nest + 1);
    } else {
      if (i >= 5 && i % 5 == 0) {
        o << DIM << WHITE << '[' << CYAN << i << WHITE << "]" << RESET;
      }
      o << YELLOW << begin[i];
    }

    if (i + 1 < n) o << RESET << (should_nest ? "," : ", ");
    ++i;
  }

  o << RESET;
  if constexpr (should_nest) {
    if (n) {
      o.put('\n');
      indent(o, nest);
    }
  }
  o << '}';
}

// For non-random-accessible & non-map container
template <
    class Iterable,
    std::enable_if_t<
        armkn::is_iterable_v<Iterable> && not armkn::is_random_accessible_v<Iterable> &&
            not armkn::is_key_value_map_v<Iterable>,
        std::nullptr_t> = nullptr>
void write_iterable(std::ostream& o, const Iterable& xs, int nest = 0) {
  using elem_type = std::decay_t<decltype(*std::begin(xs))>;
  constexpr bool should_nest =
      not armkn::is_string_like_v<elem_type> && armkn::is_iterable_v<elem_type>;

  constexpr unsigned OMISSION_N = should_nest ? 30 : 120;
  constexpr unsigned OMMSSION_TAIL_SHOW_N = should_nest ? 5 : 20;

  const size_t n = std::size(xs);
  const size_t limitted_n = (n > OMISSION_N + OMMSSION_TAIL_SHOW_N) ? OMISSION_N : n;
  const auto idx_nchars = (int)nchars(n - 1);

  o << RESET << '{';

  size_t i = 0;
  auto itr = std::begin(xs);

  while (i < n) {
    if (i == limitted_n) {
      o << RED << "..., " << RESET;
      i = n - 5;
      itr = std::prev(std::end(xs), 5);
      continue;
    }

    if constexpr (should_nest) {
      o << "\n";
      indent(o, nest + 1);
      o << DIM << CYAN << std::setw(idx_nchars) << i << WHITE << ": " << RESET;
      write_iterable(o, *itr, nest + 1);
    } else {
      if (i % 5 == 0) {
        o << DIM << CYAN << i << WHITE << ":" << RESET;
      }
      o << YELLOW << *itr;
    }

    if (i + 1 < n) o << RESET << (should_nest ? "," : ", ");
    ++i;
    ++itr;
  }

  o << RESET;
  if constexpr (should_nest) {
    if (n) {
      o.put('\n');
      indent(o, nest);
    }
  }
  o << '}';
}

// For key-value map
template <
    class Iterable,
    std::enable_if_t<armkn::is_key_value_map_v<Iterable>, std::nullptr_t> = nullptr>
void write_iterable(std::ostream& o, const Iterable& xs, int nest = 0) {
  using key_type = std::decay_t<typename Iterable::key_type>;
  using mapped_type = std::decay_t<typename Iterable::mapped_type>;
  constexpr bool should_nest =
      (armkn::is_iterable_v<key_type>) ||
      (not armkn::is_string_like_v<mapped_type> && armkn::is_iterable_v<mapped_type>);

  constexpr unsigned OMISSION_N = should_nest ? 30 : 120;
  constexpr unsigned OMMSSION_TAIL_SHOW_N = should_nest ? 5 : 20;

  const size_t n = std::size(xs);
  const size_t limitted_n = (n > OMISSION_N + OMMSSION_TAIL_SHOW_N) ? OMISSION_N : n;

  o << RESET << '{';

  std::size_t cnt = 0;
  auto itr = std::begin(xs);
  const auto end = std::end(xs);

  while (itr != end) {
    if (cnt == limitted_n) {
      o << RED << "..., " << RESET;
      cnt = n - 5;
      itr = std::prev(std::end(xs), 5);
      continue;
    }

    const auto& [key, value] = *itr;

    if constexpr (should_nest) {
      o << "\n";
      indent(o, nest + 1);
    }

    o << DIM << WHITE << '[' << CYAN;
    if constexpr (armkn::is_iterable_v<key_type>) {
      write_iterable(o, key);
    } else {
      o << key;
    }
    o << DIM << WHITE << "]=" << RESET;

    if constexpr (armkn::is_iterable_v<mapped_type>) {
      write_iterable(o, value, nest + 1);
    } else {
      o << YELLOW << value;
    }

    if (std::next(itr) != end) o << RESET << (should_nest ? "," : ", ");
    ++cnt;
    ++itr;
  }

  o << RESET;
  if constexpr (should_nest) {
    if (n) {
      o.put('\n');
      indent(o, nest);
    }
  }
  o << '}';
}

template <
    class Iterable,
    std::enable_if_t<
        not armkn::is_string_like_v<Iterable> && armkn::is_iterable_v<Iterable>,
        std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& o, const Iterable& xs) {
  write_iterable(o, xs);
  return o;
}

std::ostream* out = &std::clog;

class DebugPrinter {
  const unsigned line_no;
  const char* const pretty_func_name;
  const vector<string> args;
  vector<string>::const_iterator itr;

 public:
  DebugPrinter(
      unsigned line_no_,
      const char* simple_fn_name,
      const char* pretty_fn_name,
      const char* args_str
  )
      : line_no(line_no_),
        pretty_func_name(
            std::strstr(pretty_fn_name, "(anonymous class)::operator()") == nullptr &&
                    std::strstr(pretty_fn_name, "<lambda") == nullptr
                ? simple_fn_name
                : "<lambda>"
        ),
        args(split_and_remove_whitespace(args_str)),
        itr(args.cbegin()) {}

  template <class... T>
  auto operator()(T&&... xs) {
    *out << MAGENTA << line_no << RESET << ':';
    *out << BLUE << pretty_func_name << "()" << RESET << ": ";
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
    // if arg is string literal, show just value
    if ((*itr)[0] == '"') {
      *out << '"' << GREEN << x << RESET << '"';
    } else {
      *out << CYAN << *itr << WHITE << DIM << '=' << RESET << YELLOW << x << RESET;
    }
  }

  auto split_and_remove_whitespace(const char* s) -> vector<string> {
    vector<string> res;
    char buf[128], *buf_end = buf;
    res.reserve(8);
    unsigned paren = 0, brace = 0, bracket = 0, angle = 0;

    for (; *s != '\0'; ++s) {
      if (std::isspace(*s)) continue;

      if (*s == ',' && paren == 0 && brace == 0 && bracket == 0 && angle == 0) {
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
      else if (*s == '<' && !std::isspace(s[-1]))
        ++angle;
      else if (*s == '>' && !std::isspace(s[-1]))
        --angle;
    }

    res.emplace_back(buf, buf_end);
    return res;
  }
};

}  // namespace armkn::dbg

#endif
