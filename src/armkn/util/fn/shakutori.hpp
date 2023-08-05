#pragma once

/// しゃくとり法;
/// - `can_push_right`: `I -> bool`
/// - `push_right` : `I -> void`
/// - `pop_left`: `I -> void`
/// - `action`: `(I left, I right) -> void`
template <class I, class F1, class F2, class F3, class F4>
void shakutori(I begin, I end, F1&& can_push_right, F2&& push_right, F3&& pop_left, F4&& action) {
  I right = begin;
  for (I left = begin; left < end; ++left) {
    while (right < end && can_push_right(right)) {
      push_right(right);
      ++right;
    }
    action(left, right);
    if (right == left) {
      ++right;
    } else {
      pop_left(left);
    }
  }
}
