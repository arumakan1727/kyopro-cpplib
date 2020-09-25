#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>

#include "../../Util/at.hpp"

void at_test_dim1_a() {
    using arumakan::at;
    constexpr int W = 5;
    int a[W];

    for (int i = 0; i < W; ++i) {
        at(a, i) = i;
        assert(&at(a, i) == &a[i]);
        assert(a[i] == i);
    }

    std::clog << __func__ << " : OK" << std::endl;
}

void at_test_dim1_b() {
    using arumakan::at;
    constexpr int W = 5;
    int a[W];
    using P1 = std::array<int, 1>;
    using P2 = std::tuple<int>;

    for (int i = 0; i < W; ++i) {
        at(a, P1{i}) = i;
        assert(a[i] == i);
        assert(&at(a, P1{i}) == &a[i]);
        assert(&at(a, P2{i}) == &a[i]);
    }

    std::clog << __func__ << " : OK" << std::endl;
}

void at_test_dim2() {
    using arumakan::at;
    constexpr int H = 3;
    constexpr int W = 4;
    int a[H][W];
    using P1 = std::array<int, 2>;
    using P2 = std::pair<int, int>;
    using P3 = std::tuple<int, int>;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            at(a, P1{i, j}) = i * W + j;
            assert(a[i][j] == i * W + j);
            assert(&at(a, P1{i, j}) == &a[i][j]);
            assert(&at(a, P2{i, j}) == &a[i][j]);
            assert(&at(a, P3{i, j}) == &a[i][j]);
        }
    }

    std::clog << __func__ << " : OK" << std::endl;
}

void at_test_dim3() {
    using arumakan::at;
    constexpr int D = 3;
    constexpr int H = 3;
    constexpr int W = 4;
    int a[D][H][W];
    using P1 = std::array<int, 3>;
    using P2 = std::tuple<int, int, int>;

    for (int z = 0; z < D; ++z) {
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                at(a, P1{z, y, x}) = (z * H * W) + (y * H) + (x);
                assert(a[z][y][x] == (z * H * W) + (y * H) + (x));
                assert(&at(a, P1{z, y, x}) == &a[z][y][x]);
                assert(&at(a, P2{z, y, x}) == &a[z][y][x]);
            }
        }
    }

    std::clog << __func__ << " : OK" << std::endl;
}

int main() {
    std::cout << "Hello World" << std::endl;

    at_test_dim1_a();
    at_test_dim1_b();
    at_test_dim2();
    at_test_dim3();

    return 0;
}
