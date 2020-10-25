#pragma once

/**
 * @brief extgcd() (拡張ユークリッドの互除法)
 * ax + by = gcd(a, b) の整数解 (x, y) を引数に格納する
 */
template <class T>
T extgcd(T a, T b, T& x, T& y) {
    T g = a;
    if (b != 0) {
        g = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return g;
}
