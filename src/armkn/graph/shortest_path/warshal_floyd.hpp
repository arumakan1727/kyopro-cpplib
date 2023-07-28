#pragma once
#include <algorithm>
#include <cstddef>

template <class T, class Matrix>
void warshall_floyd(Matrix& d, const T inf) {
  for (unsigned k = 0; k < d.size(); k++) {
    for (unsigned i = 0; i < d.size(); i++) {
      if (d[i][k] >= inf) continue;
      for (unsigned j = 0; j < d.size(); j++) {
        if (d[k][j] < inf) d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}
