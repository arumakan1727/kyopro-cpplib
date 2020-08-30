#pragma once

/**
 * @brief 半開区間内に含まれているかのチェック
 */
template <class Value, class BeginValue, class EndValue>
inline bool within(const Value &v, const BeginValue &begin, const EndValue &end) { return begin <= v && v < end; }
