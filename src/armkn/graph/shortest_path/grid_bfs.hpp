#pragma once
#include <cstdint>
#include <initializer_list>
#include <queue>
#include <string>
#include <vector>

/// マス(i, j) が到達不可能な場合は戻り値 `dist[i][j] = -1`
auto grid_bfs(uint32_t sy, uint32_t sx, const std::vector<std::string>& grid, const char wall)
    -> std::vector<std::vector<int>> {
  using u32 = uint32_t;
  const auto H = grid.size();
  const auto W = grid[0].size();
  auto dist = std::vector(H, std::vector(W, -1));
  auto que = std::queue<std::pair<u32, u32>>();
  dist[sy][sx] = 0;
  que.emplace(sy, sx);

  constexpr std::pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (que.size()) {
    const auto [y, x] = que.front();
    que.pop();
    for (const auto& [dy, dx] : dirs) {
      const auto ny = y + (u32)dy;
      const auto nx = x + (u32)dx;
      if (ny < H && nx < W && dist[ny][nx] == -1 && grid[ny][nx] != wall) {
        dist[ny][nx] = dist[y][x] + 1;
        que.emplace(ny, nx);
      }
    }
  }
  return dist;
}
