#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>

#include "../../Math/Number-Theory/totient-func.hpp"

int main() {
    int n;
    std::cin >> n;
    std::cout << totient(n) << std::endl;

    return 0;
}
