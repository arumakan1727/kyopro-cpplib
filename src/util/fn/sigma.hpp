#pragma once
#include "../alias/ll.hpp"

inline ll sigma(ll a, ll b) {
  return (a + b) * (b - a + 1) >> 1;
}
