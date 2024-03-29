#pragma once
#include <iostream>
#include <utility>

struct Printer {
  std::ostream& _out = std::cout;
  const char* _sep = " ";
  const char* _end = "\n";

  inline Printer() = default;

  inline void operator()() {
    _out << _end;
  }

  template <class T, class... Rest>
  inline void operator()(T&& a, Rest&&... rest) {
    _out << a;
    if constexpr (sizeof...(rest)) _out << _sep;
    operator()(std::forward<Rest>(rest)...);
  }

#define EMIT_YES_NO_METHOD(yes, no)   \
  inline void yes##no(bool x) const { \
    _out << (x ? #yes : #no) << _end; \
  }
  EMIT_YES_NO_METHOD(yes, no);
  EMIT_YES_NO_METHOD(YES, NO);
  EMIT_YES_NO_METHOD(Yes, No);
#undef EMIT_YES_NO_METHOD

  template <class Iterable>
  inline void each(const Iterable& xs) const {
    each(std::begin(xs), std::end(xs));
  }

  template <class Iterable>
  inline void lines(const Iterable& xs) {
    auto tmp = std::exchange(_sep, "\n");
    each(std::begin(xs), std::end(xs));
    _sep = tmp;
  }

  template <class InputItr>
  inline void each(InputItr begin, InputItr end) const {
    for (begin != end && _out << *begin++; begin != end; ++begin) _out << _sep << *begin;
    _out << _end;
  }

  inline Printer to(std::ostream& o) const {
    return Printer{o, _sep, _end};
  }
  inline Printer sep(const char* sep) const {
    return Printer{_out, sep, _end};
  }
  inline Printer ends(const char* end) const {
    return Printer{_out, _sep, end};
  }
} print;
