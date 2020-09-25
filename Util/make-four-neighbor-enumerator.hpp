#pragma once
#include <cstdint>
#include <utility>

/**
 * @brief makeFourNeighborEnumerator() (グリッドの四近傍(上下左右)の列挙) 
 *
 * handlerFunc: fn({sy, sx}, {ny, nx}, f)
 */
template <class HandlerFunc>
auto makeFourNeighborEnumerator(int H, int W, HandlerFunc handlerFunc) {
    return [H, W, handlerFunc](auto v, auto func) {
        using P = decltype(v);
        static constexpr int dy[]{0, 1, 0, -1};
        const auto y = std::get<0>(v);
        const auto x = std::get<1>(v);

        for (std::size_t q = 0; q < 4; ++q) {
            const auto ny = y + dy[q];
            const auto nx = x + dy[q ^ 1];
            if (0 <= ny && ny < H && 0 <= nx && nx < W) handlerFunc(P{y, x}, P{ny, nx}, func);
        }
    };
}
