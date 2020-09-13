#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <iostream>

#include "../../Math/Number-Theory/prime-factorize.hpp"

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << ":";

    for (const auto [value, cnt] : primeFactorize(n)) {
        for (int i = 0; i < cnt; ++i) cout << ' ' << value;
    }
    cout << endl;
}