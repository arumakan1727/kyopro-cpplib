#pragma once

/**
 * @brief within() (半開区間内に含まれているかの判定)
 */
template <class Value, class ValueBegin, class ValueEnd>
inline bool within(const Value& v, const ValueBegin& begin, const ValueEnd& end) {
    return begin <= v && v < end;
}
